#include <EEPROM.h>
#include "WiFi.h"
#include "00_ChuongTrinhChinh.h"
#include "01_LoRa.h"
#include "02_POSTGET.h"

#include "05_WiFi.h"
#include "06_Flags.h"


_LoRa _LoRa_(CS_LoRa, RST_LoRa, INT_LoRa, EN_LoRa);


WIFI _WiFi;
Flags _Flags;
POSTGET _POSTGET;  // Các hàm thực thi POST - GET giữa device và serve.
//
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

// static std::vector<ECGFIFO> ManagerBoard;
TaskHandle_t HandleWireless;
// Define Queue handle
QueueHandle_t QueueHandle;
const int QueueElementSize = 30;

uint8_t _GiuBootDePhatAP = 0;
// bool kiemtraketnoiwifi = false;
String ID_Mac_Board = "";

void HandleLoRaWiFi(void* pvParameters) {
  // int i = 0;
  uint8_t _GiuBootDePhatAP = 0;
  for (;;) {
    if (_GiuBootDePhatAP >= 10) {
      _WiFi.NgatKetNoiWiFi();
      _WiFi.DaBatAP = true;
    }
    // #ifdef debug
    //     Serial.printf("co bat AP: %d\n",_WiFi.DaBatAP);
    // #endif
    if (LoRa.parsePacket() && _WiFi.DaBatAP != 1) {
      _ECGFIFO FIFO_RECEIVER;
      uint8_t buffer[sizeof(_ECGFIFO)];
      LoRa.readBytes(buffer, sizeof(_ECGFIFO));
      memcpy(&FIFO_RECEIVER, buffer, sizeof(_ECGFIFO));  // copy dữ liệu uint8_t sang dạng  mảng struct
      xQueueSend(QueueHandle, &FIFO_RECEIVER, 0);        // gửi qua Queue (giống như chuỗi vector nhưng nó bảo vệ dữ liệu tốt hơn)
    }
    // _Flags.TurnONFlags();
    // ThucThiTacVuTheoFLAG();
    // _Flags.TurnOFFFlags();
    vTaskDelay(pdMS_TO_TICKS(1));
  }
}
void Plotter(void* pvParameters) {
  _ECGFIFO Plotter;
  for (;;) {
    if (xQueueReceive(QueueHandle, &Plotter, portMAX_DELAY) == pdPASS) {
      /*Bản Demo */
            String data = "{\"Mac\":\"";
            data += String(Plotter.Mac);
            data += "\",\"ECGWave\":[";
            for (int i = 0; i < MaximumSample; ++i) {
              data += String(Plotter.FIFO.EcgWave[i]);
              if (i < MaximumSample - 1) data += ",";
            }

            data += "],";
            data += "\"HR\":";
            data += String(Plotter.FIFO.HR);
            data += ",\"RR\":";
            data += String(Plotter.FIFO.RR);
            data += ",\"BAT\":";
            data += String(Plotter.FIFO.Bat);
            data += ",\"Accel\":";
            data += String(Plotter.FIFO.Accel);
            data += "}";
      #ifdef debug
            Serial.println(data);
      #endif
    }
    vTaskDelay(pdMS_TO_TICKS(1));
  }
}
#pragma region Khoitao
void KhoiTao(void) {
  Serial.begin(115200);
  Serial.println("");
  pinMode(NutBoot, INPUT_PULLUP);
  // Khởi tạo bộ nhớ ROM của ESP32
  EEPROM.begin(512);
  delay(10);

  //----------------------------------------------------
#pragma region Khởi tạo WIFI
  //======================================================================
  //------ Begin: Khởi tạo để có thể cấu hình kết nối WiFi tự động -----//
  //======================================================================
  // Nếu muốn xóa thông tin WIFI đã lưu trong EEPROM thì mở dòng code này.
  // _WiFi.XoaWiFiDaLuuTrongEEPROM();
  // _ThongSoBoard.XoaEEPROM(0, 512);
  // Đoạn code này phải được gọi ở cuối cùng ở hàm setup().
  // _WiFi.DocWiFiDaLuuTrongEEPROM();
  // Dành 10s để kết nối WiFI
  // Lưu ý: Phải có thời gian chờ cho việc kết nối WIFI nếu không sẽ
  // gây ra tình trạng board bị reset và không thể phát access point (AP).
  // _WiFi.KetNoiWiFi(10);
  //======================================================================
  //------ End: Khởi tạo để có thể cấu hình kết nối WiFi tự động -------//
  //======================================================================
  ID_Mac_Board = _WiFi.LaySoMAC();
  SPI.begin(SCK_LoRa, MISO_LoRa, MOSI_LoRa);  // cấu hình cho SPI để giao tiếp với LoRa
  _LoRa_.khoitao(Region_Assian, 0x23);        //khởi tạo LoRa // bat che do dong bo
  LoRa.setSpreadingFactor(9);      // Cân bằng giữa tầm xa và tốc độ
  LoRa.setSignalBandwidth(450E3);  // Băng thông cao hơn cho tốc độ nhanh
  LoRa.setCodingRate4(5);          // Tỉ lệ mã hóa thấp hơn
  LoRa.enableCrc();                // Bật kiểm tra CRC
#ifdef debug
  Serial.printf("LoRa initialized on frequency: %.1fMHz\n", _LoRa_.FREQ / 1000000.0);
  Serial.print("Gate way Mac : ");
  Serial.println(ID_Mac_Board);
  // Serial.print(_WiFi.DaBatAP);
#endif
#pragma endregion Khởi tạo WIFI
  QueueHandle = xQueueCreate(QueueElementSize, sizeof(_ECGFIFO));
  xTaskCreatePinnedToCore(
    HandleLoRaWiFi,                     /* Task function. */
    "Giao tiếp không dây LoRa và Wifi", /* name of task. */
    10000,                              /* Stack size of task */
    NULL,                               /* parameter of the task */
    1,                                  /* priority of the task */
    &HandleWireless,                    /* Task handle to keep track of created task */
    0);                                 /* pin task to core 0 */
  xTaskCreatePinnedToCore(
    Plotter,                       /* Task function. */
    "vẽ biểu đồ ECG lên máy tính", /* name of task. */
    4096,                          /* Stack size of task */
    NULL,                          /* parameter of the task */
    1,                             /* priority of the task */
    NULL,                          /* Task handle to keep track of created task */
    1);                            /* pin task to core 1 */
}

#pragma endregion khoitao

void ChayChuongTrinhChinh(void) {
  vTaskDelay(pdMS_TO_TICKS(1));
}

void ThucThiTacVuTheoFLAG(void) {
#pragma region ThucThiTacVuTheoFLAG
//------------------------------------------------------------------------------
#pragma region Flag100ms
#ifdef _Flag_100ms
  if (_Flags.Flag.t100ms) {
    // _WiFi.KiemTraKetNoiWiFi();
    if (digitalRead(NutBoot) == LOW) {
      _GiuBootDePhatAP++;
      Serial.print("NHAN GIU LAN THU: ");
      Serial.println(_GiuBootDePhatAP);
    }
  }
#endif
#pragma endregion Flag100ms
//------------------------------------------------------------------------------
#pragma region Flag500ms
#ifdef _Flag_500ms
  if (_Flags.Flag.t500ms) {
    _WiFi.KiemTraKetNoiWiFi();
  }
#endif
#pragma endregion Flag500ms
  //------------------------------------------------------------------------------

#pragma endregion ThucThiTacVuTheoFLAG
}