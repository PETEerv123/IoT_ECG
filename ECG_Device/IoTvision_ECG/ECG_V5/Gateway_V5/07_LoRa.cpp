#include "07_LoRa.h"

_LoRa::_LoRa(int CS, int RST, int DIO0, int EN) {
  _CS = CS;
  _RST = RST;
  _DIO = DIO0;
  _EN = EN;
}
void _LoRa::khoitao(Set_Region region, int syn) {  // int 4 byte
  LoRa.setPins(_CS, _RST, _DIO);
  pinMode(_EN, OUTPUT);
  Enable();
  switch (region) {
    case Region_Assian:
      FREQ = FREQ_ASIA;
      break;
    case Region_Europe:
      FREQ = FREQ_EUROPE;
      break;
    case Region_American:
      FREQ = FREQ_America;
      break;
  }
  if (!LoRa.begin(FREQ)) {
#ifdef debug
    Serial.println("Khởi tạo Lora thất bại");
    Serial.println("Đã dừng chương trình");
#endif
    while(1);
  } else {
#ifdef debug
    Serial.println("Khởi tạo LoRa thành công");
#endif
  }
  Disable();
  // LoRa.setSignalBandwidth(250E3);  // Tăng bandwidth lên 250kHz (thay vì 125kHz)
  // LoRa.setSpreadingFactor(7);      // SF thấp nhất có thể (SF7)
  // LoRa.setCodingRate4(5);          // CR = 4/5 (thấp nhất)
  // LoRa.enableCrc();                // Bật CRC để phát hiện lỗi
  // LoRa.setTxPower(20);             // Công suất tối đa
  LoRa.setSyncWord(syn);
}
bool _LoRa::Enable() {
  digitalWrite(_EN, HIGH);
  return true;
}
bool _LoRa::Disable() {
  digitalWrite(_EN, LOW);
  return true;
}
void _LoRa::onDataSend(const uint8_t *_buffer, size_t _size) {
  LoRa.beginPacket();
  LoRa.write(_buffer, _size);
  LoRa.endPacket();
}