#include <EEPROM.h>
#include "00_ChuongTrinhChinh.h"
#include "03_ThongSoBoard.h"
#include "04_ESPNOW.h"
#include "05_WIFI.h"
#include "06_Flags.h"
#include "07_LoRa.h"




#define debug
_LoRa _LoRa_(CS_LoRa, RST_LoRa, INT_LoRa, EN_LoRa);
WIFI _WiFi;
Flags _Flags;                // Cờ định thời gian thực thi cách lệnh.
ESPNOW _ESPNow;              // Kết nối ESP-NOW giữa các ESP với nhau
ThongSoBoard _ThongSoBoard;  // Thông số cài đặt cho board lưu trong EEPROM.
#define MaximumSample 50
struct ECGFIFO {
  int32_t EcgWave[MaximumSample];  // 4 byte
  int16_t HR;                      // 2 byte  0~256 bpm
  int16_t RR;                      // 2 byte
  int8_t Bat;                      // 1 byte // mức độ pin tiêu thụ 0-100%
  int8_t Accel;                    // 1 byte ~~ 0-256 tính độ phần trăm té ngã 0-100%
};
typedef struct _ECGFIFO {
  char Mac[18];
  ECGFIFO FIFO;
} _ECGFIFO;
QueueHandle_t QueueHandle;        // khi có dữ liệu nhận từ Esp now nó sẽ lưu vào QuêuHandle
const int QueueElementSize = 20;  // Mảng trung gian để lưu
String ID_Mac_Board;              // Số ID của ESP32, đây là số IMEI của board.
uint8_t _GiuBootDePhatAP = 0;

void TaskhandleLoRa(void* pvParameters) {
  static _ECGFIFO FIFO_Send;
  bool State = false;
  for (;;) {
    if (xQueueReceive(QueueHandle, &FIFO_Send, portMAX_DELAY) == pdPASS) {
      esp_wifi_stop();  // Tắt WiFi trước khi phát tránh xung đột với SPI khi đang truyền LoRa
      _LoRa_.Enable();
      LoRa.beginPacket();
      LoRa.write((uint8_t*)&FIFO_Send, sizeof(_ECGFIFO));
      State = LoRa.endPacket();
      if (State) {
#ifdef debug
        Serial.print("✅Lora gửi thành công\n");
#endif
      }
      _LoRa_.Disable();  // bật tắt giúp ổn định đường truyền
      //       String data = "{\"Mac\":\"";
      //       data += String(Plotter.Mac);
      //       data += "\",\"ECGWave\":[";
      //       for (int i = 0; i < MaximumSample; ++i) {
      //         data += String(Plotter.FIFO.EcgWave[i]);
      //         if (i < MaximumSample - 1) data += ",";
      //       }

      //       data += "],";
      //       data += "\"HR\":";
      //       data += String(Plotter.FIFO.HR);
      //       data += ",\"RR\":";
      //       data += String(Plotter.FIFO.RR);
      //       data += ",\"BAT\":";
      //       data += String(Plotter.FIFO.Bat);
      //       data += ",\"Accel\":";
      //       data += String(Plotter.FIFO.Accel);
      //       data += "}";
      // #ifdef debug
      //       Serial.println(data);
      // #endif
      esp_wifi_start();

    }                                 // Mở lại sau khi gửi
    vTaskDelay(pdMS_TO_TICKS(1));    // giải phóng Stack
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
  
  WiFi.mode(WIFI_STA);
  _ESPNow.khoitao_NhanFIFO(OnDataRecv);  // trong Esp now có sẵn WiFi.STA nên phải khai báo theo tuần tự
  ID_Mac_Board = _WiFi.LaySoMAC();       // Tắt WiFi trước khi phát tránh xung đột với SPI khi đang truyền LoRa

  QueueHandle = xQueueCreate(QueueElementSize, sizeof(_ECGFIFO));
  SPI.begin(SCK_LoRa, MISO_LoRa, MOSI_LoRa);  // cấu hình cho SPI để giao tiếp với LoRa
  _LoRa_.khoitao(Region_Assian, 0x23);        //khởi tạo LoRa
  LoRa.setSpreadingFactor(9);                 // Cân bằng giữa tầm xa và tốc độ
  LoRa.setSignalBandwidth(450E3);             // Băng thông cao hơn cho tốc độ nhanh
  LoRa.setCodingRate4(5);                     // Tỉ lệ mã hóa thấp hơn
  LoRa.enableCrc();                           // Bật kiểm tra CRC

  // esp_wifi_start();
#ifdef debug
  Serial.print("Gate way Mac : ");
  Serial.println(ID_Mac_Board);
  Serial.printf("LoRa initialized on frequency: %.1fMHz\n", _LoRa_.FREQ / 1000000.0);
#endif
  // tạo task dual core
  xTaskCreatePinnedToCore(
    TaskhandleLoRa,                      /* Task function. */
    "Task handle LoRa",                  /* name of task. */
    10000,                               /* Stack size of task */
    NULL,                                /* parameter of the task */
    3,                                   /* priority of the task */
    NULL,                                /* Task handle to keep track of created task */
    1);                                  /* pin task to core 0 */
}
void ChayChuongTrinhChinh() {
  vTaskDelay(pdMS_TO_TICKS(1));
}
void OnDataRecv(const esp_now_recv_info_t* recv_info, const unsigned char* incomingData, int len) {
  static _ECGFIFO FIFO_Receiver;
  snprintf(_ESPNow.MacAddressRC, sizeof(_ESPNow.MacAddressRC), "%02x:%02x:%02x:%02x:%02x:%02x",
           recv_info->src_addr[0], recv_info->src_addr[1], recv_info->src_addr[2], recv_info->src_addr[3], recv_info->src_addr[4], recv_info->src_addr[5]);

  memcpy(&FIFO_Receiver.FIFO, incomingData, sizeof(ECGFIFO));
  memcpy(&FIFO_Receiver.Mac, _ESPNow.MacAddressRC, sizeof(_ESPNow.MacAddressRC));
  xQueueSend(QueueHandle, &FIFO_Receiver, 0);  // xQueueSendFromISR(QueueHandle, (void*)FIFO, NULL);  // kh chuyển đổi ngữ cảnh
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
