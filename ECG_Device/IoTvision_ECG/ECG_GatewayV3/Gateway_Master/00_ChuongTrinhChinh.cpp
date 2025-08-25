#include <EEPROM.h>
#include "WiFi.h"
#include "00_ChuongTrinhChinh.h"

#include "02_POSTGET.h"

#include "05_WiFi.h"
#include "06_Flags.h"



WIFI _WiFi;
Flags _Flags;
POSTGET _POSTGET;  // Các hàm thực thi POST - GET giữa device và serve.


#define NutBoot 0
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
  _WiFi.DocWiFiDaLuuTrongEEPROM();
  // Dành 10s để kết nối WiFI
  // Lưu ý: Phải có thời gian chờ cho việc kết nối WIFI nếu không sẽ
  // gây ra tình trạng board bị reset và không thể phát access point (AP).
  _WiFi.KetNoiWiFi(10);
  //======================================================================
  //------ End: Khởi tạo để có thể cấu hình kết nối WiFi tự động -------//
  //======================================================================
  ID_Mac_Board = _WiFi.LaySoMAC();
#ifndef debug
  Serial.print("Mac Board : ");
  Serial.println(ID_Mac_Board);
  Serial.print("");
#endif
#pragma endregion Khởi tạo WIFI
}

#pragma endregion khoitao

void ChayChuongTrinhChinh(void) {

}
