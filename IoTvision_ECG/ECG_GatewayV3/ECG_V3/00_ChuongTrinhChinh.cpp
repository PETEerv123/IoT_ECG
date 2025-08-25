#include <EEPROM.h>
#include "00_ChuongTrinhChinh.h"
#include "01_Max30003.h"  // Thư viện MAX30003
#include "02_POSTGET.h"
#include "03_ThongSoBoard.h"
#include "04_ESPNOW.h"
#include "05_WIFI.h"
#include "06_Flags.h"

// #include "esp_sleep.h"
// extern "C" {
//   #include "driver/uart.h"
// }

_MAX30003 _max30003(CS_PIN_MAX30003);  // ECG
WIFI _WiFi;                            // Kết nối WiFi cho board.
Flags _Flags;                          // Cờ định thời gian thực thi cách lệnh.
ESPNOW _ESPNow;                        // Kết nối ESP-NOW giữa các ESP với nhau
POSTGET _POSTGET;                      // Các hàm thực thi POST - GET giữa device và serve.
ThongSoBoard _ThongSoBoard;            // Thông số cài đặt cho board lưu trong EEPROM.

struct ECGFIFO {
  int64_t EcgWave;  // 8 byte
  int16_t HR;       // 1 byte  0~256 bpm
  int16_t RR;       // 2 byte
  int8_t Bat;       // 1 byte // mức độ pin tiêu thụ 0-100%
  int8_t Accel;     // 1 byte ~~ 0-256 tính độ phần trăm té ngã 0-100%
};

ECGFIFO FIFO;

// std::vector<uint8_t> StoreFIFO = FIFO;
int8_t Final_VBat;
String ID_Mac_Board;  // Số ID của ESP32, đây là số IMEI của board.
uint8_t _GiuBootDePhatAP = 0;
unsigned long Esp32delaytime = 0;
int delaytime = 21;
// int64_t last_sample_time = 0;
void KhoiTao() {
  Serial.begin(115200);
  analogReadResolution(12);

  pinMode(NutBoot, INPUT);
  // Khởi tạo bộ nhớ ROM của ESP32
  EEPROM.begin(512);
  delay(10);

  // ID_Mac_Board = "ABCDEF";
  _ThongSoBoard.KhoiTao();  // lấy mac từ EPROM được lưu từ 0 -> MAc length

  strncpy(_ESPNow.MACMaster, _ThongSoBoard.MACMaster, sizeof(_ThongSoBoard.MACMaster));
  _ESPNow.khoitao();
  ID_Mac_Board = _WiFi.LaySoMAC();
#ifdef debug
  Serial.print("Mac Esp-nologo: ");
  Serial.println(ID_Mac_Board);
  Serial.print("_ESPNow.MACMaster: ");
  Serial.println(_ESPNow.MACMaster);
#endif
  pinMode(CS_PIN_MAX30003, OUTPUT);
  digitalWrite(CS_PIN_MAX30003, HIGH);  // Vô hiệu hóa MAX30003 lúc đầu

  // Khởi tạo giao tiếp SPI
  SPI.begin(SCK, SO, SI, CS_PIN_MAX30003);
  SPI.setBitOrder(MSBFIRST);   //quy định thứ tự các bit được truyền và nhận:
  SPI.setDataMode(SPI_MODE0);  // Mode 0
  _max30003.Khoitao();
  //   esp_err_t result = esp_sleep_enable_timer_wakeup(21000);

  //   if (result == ESP_OK) {
  // #ifdef debug
  //     Serial.println("Timer Wake-Up set successfully as wake-up source.");
  // #endif
  //   } else {
  // #ifdef debug
  //     Serial.println("Failed to set Timer Wake-Up as wake-up source.");
  // #endif
  //   }
}
void ChayChuongTrinhChinh() {
  if (_WiFi.DaBatAP != 1) {
    if (millis() - Esp32delaytime >= delaytime)  //test whether the period has elapsed
    {
      Esp32delaytime = millis();

      int adcValue = analogRead(PIN_BATTERY);
      float voltage = adcValue * (3.0/ 4095.0);  // 3v3 đầu vào mà sửa lại 3V cho chính xác thực tế :v
      // Tính VBAT dựa trên mạch chia áp
      float vbat = voltage * ((R1 + R2) / R2);
      int8_t percBat = int8_t((vbat - 3.6) * 100.0 / (4.2 - 3.6));
      if (percBat < Final_VBat) {
        percBat = Final_VBat;
      }
      percBat = constrain(percBat, 0, 100);
      Final_VBat = percBat;

      _max30003.Nhipdapbpm();
      FIFO.EcgWave = int64_t(_max30003.EcgWave());
      FIFO.HR = int16_t(_max30003.HR);
      FIFO.RR = int16_t(_max30003.RR);
      FIFO.Bat = percBat;
      esp_now_send(_ESPNow.MACMasterDungDinhDang, (uint8_t *)&FIFO, sizeof(FIFO));
      // #ifdef debug
      // Serial.println(_max30003.EcgWave());
      // #endif
    }
  }

  _Flags.TurnONFlags();
  ThucThiTacVuTheoFLAG();
  _Flags.TurnOFFFlags();
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
// static int nap(unsigned int timeout_sec, int uart) {

//   if (!timeout_sec) {
//     esp_sleep_enable_uart_wakeup(uart);
//     uart_set_wakeup_threshold(uart, 1);
//   } else {
//     esp_sleep_disable_wakeup_source(ESP_SLEEP_WAKEUP_UART);
//     esp_sleep_enable_timer_wakeup(1000000UL * timeout_sec);
//   }
//   esp_light_sleep_start();
// #ifdef debug
//   Serial.print("Resuming..");
// #endif
//   return 0;
// }