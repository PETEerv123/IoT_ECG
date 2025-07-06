#include <EEPROM.h>
#include "00_ChuongTrinhChinh.h"
#include "03_ThongSoBoard.h"
#include "04_ESPNOW.h"
#include "05_WIFI.h"
#include "06_Flags.h"
#include "07_LoRa.h"

_LoRa _LoRa_(CS_LoRa, RST_LoRa, INT_LoRa, EN_LoRa);
WIFI _WiFi;
Flags _Flags;                // Cờ định thời gian thực thi cách lệnh.
ESPNOW _ESPNow;              // Kết nối ESP-NOW giữa các ESP với nhau
ThongSoBoard _ThongSoBoard;  // Thông số cài đặt cho board lưu trong EEPROM.

struct ECGFIFO {
  int32_t EcgWave;  // 8 byte
  int16_t HR;       // 1 byte  0~256 bpm
  int16_t RR;       // 2 byte
  int8_t Bat;       // 1 byte // mức độ pin tiêu thụ 0-100%
  int8_t Accel;     // 1 byte ~~ 0-256 tính độ phần trăm té ngã 0-100%
};

QueueHandle_t QueueHandle;        // khi có dữ liệu nhận từ Esp now nó sẽ lưu vào QuêuHandle
const int QueueElementSize = 20;  // Mảng trung gian để lưu
String ID_Mac_Board;              // Số ID của ESP32, đây là số IMEI của board.
uint8_t _GiuBootDePhatAP = 0;

void TaskhandleLoRa(void* pvParameters) {
  static ECGFIFO buff[20];
  bool State = false;
  for (;;) {
    if (xQueueReceive(QueueHandle, &buff, portMAX_DELAY) == pdPASS) {
      esp_wifi_stop();  // Tắt WiFi trước khi phát tránh xung đột với SPI khi đang truyền LoRa
      LoRa.beginPacket();
      LoRa.write((uint8_t*)&buff, sizeof(ECGFIFO) * 20);
      State = LoRa.endPacket();
      //       for (int i = 0; i < 20; i++) {
      // #ifdef debug
      //         Serial.print(buff[i].EcgWave);
      //         Serial.println();
      // #endif
      //       }
      if (State) {
#ifdef debug
        Serial.print("✅Lora gửi thành công\n");
#endif
      }
      esp_wifi_start();  // Mở lại sau khi gửi
    }
    vTaskDelay(pdMS_TO_TICKS(1));  // giải phóng Stack
  }
}

void KhoiTao() {
  Serial.begin(115200);
  delay(500);
  pinMode(NutBoot, INPUT);
  // Khởi tạo bộ nhớ ROM của ESP32
  EEPROM.begin(512);
  delay(10);
  // ID_Mac_Board = "ABCDEF";

  _ThongSoBoard.KhoiTao();  // lấy mac từ EPROM được lưu từ 0 -> MAc length

  strncpy(_ESPNow.MACMaster, _ThongSoBoard.MACMaster, sizeof(_ThongSoBoard.MACMaster));  // copy  char
  QueueHandle = xQueueCreate(QueueElementSize, sizeof(ECGFIFO) * 20);

  _ESPNow.khoitao_NhanFIFO(OnDataRecv);  // trong Esp now có sẵn WiFi.STA nên phải khai báo theo tuần tự
  ID_Mac_Board = _WiFi.LaySoMAC();
  SPI.begin(SCK_LoRa, MISO_LoRa, MOSI_LoRa);  // cấu hình cho SPI để giao tiếp với LoRa
  _LoRa_.khoitao(Region_Assian, 0x23);        //khởi tạo LoRa
  _LoRa_.Enable();
  LoRa.setSpreadingFactor(10);     // Giảm từ 12 -> 10 (cân bằng tốc độ/khoảng cách)
  LoRa.setSignalBandwidth(450E3);  // Tăng băng thông
  LoRa.setCodingRate4(6);          // CR 4/6 (giảm sửa lỗi để tăng tốc độ)
  LoRa.setTxPower(17);             // Giảm công suất để giảm nhiễu
  LoRa.enableCrc();                // Bật CRC phần cứng
#ifdef debug
  Serial.printf("LoRa initialized on frequency: %.1fMHz\n", _LoRa_.FREQ / 1000000.0);
  Serial.print("Gate way Mac : ");
  Serial.println(ID_Mac_Board);
#endif
  // tạo task dual core
  xTaskCreatePinnedToCore(
    TaskhandleLoRa,     /* Task function. */
    "Task handle LoRa", /* name of task. */
    10000,              /* Stack size of task */
    NULL,               /* parameter of the task */
    3,                  /* priority of the task */
    NULL,               /* Task handle to keep track of created task */
    1);                 /* pin task to core 0 */
}
void ChayChuongTrinhChinh() {
  vTaskDelay(pdMS_TO_TICKS(1));
}
void OnDataRecv(const esp_now_recv_info_t* recv_info, const unsigned char* incomingData, int len) {
  static ECGFIFO FIFO[20];
  snprintf(_ESPNow.MacAddressRC, sizeof(_ESPNow.MacAddressRC), "%02x:%02x:%02x:%02x:%02x:%02x",
           recv_info->src_addr[0], recv_info->src_addr[1], recv_info->src_addr[2], recv_info->src_addr[3], recv_info->src_addr[4], recv_info->src_addr[5]);

  memcpy(FIFO, incomingData, sizeof(FIFO));
  xQueueSend(QueueHandle, &FIFO, 0);  // xQueueSendFromISR(QueueHandle, (void*)FIFO, NULL);  // kh chuyển đổi ngữ cảnh
}

void ThucThiTacVuTheoFLAG(void) {
#pragma region ThucThiTacVuTheoFLAG
#pragma region Flag100ms
#ifdef _Flag_100ms
  if (_Flags.Flag.t100ms) {
    if (digitalRead(NutBoot) == LOW) {
      _GiuBootDePhatAP++;
      Serial.print("NHAN GIU LAN THU: ");
      Serial.println(_GiuBootDePhatAP);
    }
  }
#endif
#pragma endregion Flag100ms
#pragma region Flag500ms
#ifdef _Flag_500ms
  if (_Flags.Flag.t500ms) {
    if (_GiuBootDePhatAP > 10) {
      _WiFi.ThietLapAP();
    }
  }
#endif
#pragma endregion Flag500ms
}
#pragma endregion ThucThiTacVuTheoFLAG
