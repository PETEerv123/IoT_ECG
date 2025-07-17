#ifndef _01_LoRa_H
#define _01_LoRa_H
#include "Gateway_Master_V5.h"
#include "LoRa.h"
#include "SPI.h"

// thư viện sài cho espnow nhằm tăng cường tốc đô truyền
#define FREQ_ASIA 433000000 //433E6 for Asia
#define FREQ_EUROPE 868000000 //868E6 for Europe
#define FREQ_America 915000000 // 915E6 for North America
enum Set_Region {Region_Assian,
                 Region_Europe,
                 Region_American
};

class _LoRa{
  private: 
    int _CS , _RST, _DIO, _EN;
  public:
    // bool DabatAP;
    unsigned int FREQ;
    _LoRa(int CS, int RST , int DIO0, int EN);
    void khoitao(Set_Region region, int syn);
    bool Enable();
    bool Disable();
    void onDataSend(const uint8_t *_buffer, size_t _size);
};

#endif