#include <EEPROM.h>
#include "00_ChuongTrinhChinh.h"
#include "03_ThongSoBoard.h"
#include "04_ESPNOW.h"
#include "05_WIFI.h"
#include "06_Flags.h"
#include "07_LoRa.h"

_LoRa _LoRa_(CS_LoRa, RST_LoRa, INT_LoRa);
WIFI _WiFi;
Flags _Flags;                // Cờ định thời gian thực thi cách lệnh.
ESPNOW _ESPNow;              // Kết nối ESP-NOW giữa các ESP với nhau
ThongSoBoard _ThongSoBoard;  // Thông số cài đặt cho board lưu trong EEPROM.

struct ECGFIFO {
  int64_t EcgWave;  // 8 byte
  int16_t HR;       // 1 byte  0~256 bpm
  int16_t RR;       // 2 byte
  int8_t Bat;       // 1 byte // mức độ pin tiêu thụ 0-100%
  int8_t Accel;     // 1 byte ~~ 0-256 tính độ phần trăm té ngã 0-100%
};
// static std::vector<ECGFIFO> ManagerBoard;

ECGFIFO FIFO_RECEIVER;
ECGFIFO Board1, Board2, Board3, Board4, Board5;

ECGFIFO ManagerBoard[5] = { Board1, Board2, Board3, Board4, Board5 };

String ID_Mac_Board;  // Số ID của ESP32, đây là số IMEI của board.
uint8_t _GiuBootDePhatAP = 0;
unsigned long Esp32delaytime = 0;
int delaytime = 21;
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

  SPI.begin(SCK_LoRa, MISO_LoRa, MOSI_LoRa);  // cấu hình cho SPI để giao tiếp với LoRa
  _LoRa_.khoitao(Region_Assian, 0xF2);        //khởi tạo LoRa

  // WiFi.disconnect();
  // if (_LoRa_.DabatAP) {                    // nếu kh có kích hoạt đc LoRa thì hk mở Espnoww
  _ESPNow.khoitao_NhanFIFO(OnDataRecv);  // nhận
  // }
  ID_Mac_Board = _WiFi.LaySoMAC();

#ifdef debug
  Serial.printf("LoRa initialized on frequency: %.1fMHz\n", _LoRa_.FREQ / 1000000.0);
  Serial.print("Gate way Mac : ");
  Serial.println(ID_Mac_Board);
#endif
}
void ChayChuongTrinhChinh() {
  _Flags.TurnONFlags();
  ThucThiTacVuTheoFLAG();
  _Flags.TurnOFFFlags();
}
void OnDataRecv(const esp_now_recv_info_t* recv_info, const unsigned char* incomingData, int len) {
  // receivedData.clear();
  // receivedData.push_back(std::string((const char*)incomingData,len));
  snprintf(_ESPNow.MacAddressRC, sizeof(_ESPNow.MacAddressRC), "%02x:%02x:%02x:%02x:%02x:%02x",
           recv_info->src_addr[0], recv_info->src_addr[1], recv_info->src_addr[2], recv_info->src_addr[3], recv_info->src_addr[4], recv_info->src_addr[5]);

  memcpy(&FIFO_RECEIVER, incomingData, sizeof(FIFO_RECEIVER));
  ManagerBoard[0].EcgWave = FIFO_RECEIVER.EcgWave;
  ManagerBoard[0].HR = FIFO_RECEIVER.HR;
  ManagerBoard[0].RR = FIFO_RECEIVER.RR;
  ManagerBoard[0].Bat = FIFO_RECEIVER.Bat;

#ifdef debug
  Serial.print(ManagerBoard[0].EcgWave);
  Serial.print(" ");
  Serial.print(ManagerBoard[0].HR);
  Serial.print(" ");
  Serial.print(ManagerBoard[0].RR);
  Serial.print(" ");
  Serial.print(ManagerBoard[0].Bat);
  Serial.println();
#endif
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
