#include "07_LoRa.h"

_LoRa::_LoRa(int CS, int RST, int DIO0) {
  _CS = CS;
  _RST = RST;
  _DIO = DIO0;
}
void _LoRa::khoitao(Set_Region region, int syn) {
  LoRa.setPins(_CS, _RST, _DIO);
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
void _LoRa::onDataSend(const uint8_t *_buffer, size_t _size) {
  LoRa.beginPacket();
  LoRa.write(_buffer, _size);
  LoRa.endPacket();
}