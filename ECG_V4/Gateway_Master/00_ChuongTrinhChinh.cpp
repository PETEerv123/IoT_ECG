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
struct ECGFIFO {
  int32_t EcgWave;  // 8 byte
  int16_t HR;       // 1 byte  0~256 bpm
  int16_t RR;       // 2 byte
  int8_t Bat;       // 1 byte // mức độ pin tiêu thụ 0-100%
  int8_t Accel;     // 1 byte ~~ 0-256 tính độ phần trăm té ngã 0-100%
};
// static std::vector<ECGFIFO> ManagerBoard;


uint8_t _GiuBootDePhatAP = 0;
bool kiemtraketnoiwifi = false;

String ID_Mac_Board = "";
#pragma region Khoitao
void KhoiTao(void) {
  Serial.begin(115200);
  Serial.println("");
  pinMode(NutBoot, INPUT_PULLUP);
  // Khởi tạo bộ nhớ ROM của ESP32
  EEPROM.begin(1024);
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
                                              // if (_LoRa_.Enable()) {

  _LoRa_.Enable();                                                
  LoRa.setSpreadingFactor(10);       // Giảm từ 12 -> 10 (cân bằng tốc độ/khoảng cách)
  LoRa.setSignalBandwidth(405E3);    // Tăng băng thông
  LoRa.setCodingRate4(6);            // CR 4/6 (giảm sửa lỗi để tăng tốc độ)
  LoRa.setTxPower(17);               // Giảm công suất để giảm nhiễu
  LoRa.enableCrc();                  // Bật CRC phần cứng
#ifdef debug
  Serial.printf("LoRa initialized on frequency: %.1fMHz\n", _LoRa_.FREQ / 1000000.0);
  Serial.print("Gate way Mac : ");
  Serial.println(ID_Mac_Board);
#endif
#pragma endregion Khởi tạo WIFI
}

#pragma endregion khoitao

void ChayChuongTrinhChinh(void) {
    if (LoRa.parsePacket()) {
    ECGFIFO FIFO_RECEIVER[20];
    uint8_t buffer[sizeof(ECGFIFO) * 20];
    LoRa.readBytes(buffer, sizeof(ECGFIFO)*20);
    memcpy(&FIFO_RECEIVER, buffer, sizeof(ECGFIFO) * 20);  // nạp vào struct
// #ifdef debug
    // for (int i = 0; i < 20; i++) {
    //   Serial.println(FIFO_RECEIVER[i].EcgWave);
    //   delay(20);
    // }
// #endif
  }
  // if (_GiuBootDePhatAP >= 10) {
  //   _WiFi.NgatKetNoiWiFi();
  //   kiemtraketnoiwifi = true;
  // }
  // if (_WiFi.DaBatAP == true) {
  //   kiemtraketnoiwifi = false;
  // }
  // _Flags.TurnONFlags();
  // ThucThiTacVuTheoFLAG();
  // _Flags.TurnOFFFlags();
  // try to parse packet
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
  // if (kiemtraketnoiwifi == true) {
  if (_Flags.Flag.t500ms) {
    _WiFi.KiemTraKetNoiWiFi();
  }
  // }
#endif
#pragma endregion Flag500ms
  //------------------------------------------------------------------------------

#pragma endregion ThucThiTacVuTheoFLAG
}