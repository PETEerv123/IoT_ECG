#include "01_LoRa.h"

_LoRa::_LoRa(int CS, int RST, int DIO0, int EN) {
  _CS = CS;
  _RST = RST;
  _DIO = DIO0;
  _EN = EN;
}
void _LoRa::khoitao(Set_Region region, int syn) {  // int 4 byte
  LoRa.setPins(_CS, _RST, _DIO);
  pinMode(_EN,OUTPUT);
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
#endif
    while (1);  // Dừng chương trình nếu khởi tạo thất bại
  }
#ifdef debug
  Serial.println("Khởi tạo LoRa thành công");
#endif
  LoRa.setSyncWord(syn);
}
bool _LoRa::Enable() {
  digitalWrite(_EN, HIGH);
  return true;
}
bool _LoRa::Disable() {
  digitalWrite(_C_ENS, LOW);
  return true;
}
void _LoRa::onDataSend(const uint8_t *_buffer, size_t _size) {
  LoRa.beginPacket();
  LoRa.write(_buffer, _size);
  LoRa.endPacket();
}