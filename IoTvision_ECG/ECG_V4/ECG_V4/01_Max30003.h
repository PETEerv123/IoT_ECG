#ifndef _01_Max30003_H

#define _01_Max30003_H

#include "Max30003.h"  // Thư viện MAX30003
#include "Arduino.h"
#include "SPI.h"  // Thư viện SPI

class _MAX30003 {
private:
  MAX30003 max30003;  // Khởi tạo đối tượng từ lớp MAX30003
  
public:
  _MAX30003(int cs_pin);
  void Khoitao(void);
  signed long EcgWave();
  void Nhipdapbpm();
  bool STATUS_DCLO();
  bool STATUS_RR();
  unsigned int HR;
  unsigned int RR;
};
#endif