#include "01_Max30003.h"

_MAX30003::_MAX30003(int cs_pin)
  : max30003(cs_pin) {}

void _MAX30003::Khoitao(void) {

  // Đọc thông tin từ MAX30003 để kiểm tra kết nối
  bool ret = max30003.max30003ReadInfo();
  if (ret) {
#ifdef debug
    Serial.println("Max30003 đọc ID thành công");
#endif
  } else {
    // Nếu không đọc được ID, vòng lặp kiểm tra liên tục với timeout 10 giây
    unsigned long startMillis = millis();
    while (!ret) {
      ret = max30003.max30003ReadInfo();
      if (millis() - startMillis > 10000) {  // Timeout sau 10 giây
#ifdef debug
        Serial.println("Max30003 đọc ID thất bại, timeout sau 10 giây");
#endif
        break;
      }
#ifdef debug
      Serial.println("Không đọc được ID, kiểm tra kết nối...");
#endif
      delay(1000);
    }
  }
#ifdef debug
  // Khởi tạo MAX30003
  Serial.println("Khởi tạo MAX30003...");
#endif
  max30003.max30003Begin();
}
signed long _MAX30003:: EcgWave() {
  max30003.getEcgSamples();
  signed long data = max30003.ecgdata;
  return data ; 
}
void _MAX30003:: Nhipdapbpm(){
  max30003.getHRandRR();
  HR = max30003.heartRate;
  RR  = max30003.RRinterval;
}
bool _MAX30003::STATUS_DCLO(){
  uint8_t statusReg[3];
  max30003.max30003RegRead(STATUS,statusReg);
  if(statusReg[3] && DCLOFF){ // nếu phát hiện DC Lead Off Detection  thì true
      return true;
  }else {return false;}
}
bool _MAX30003::STATUS_RR(){
    uint8_t statusReg[3];
  max30003.max30003RegRead(STATUS,statusReg);
  if(statusReg[1] && RTOR_INTR_MASK){ // nếu phát hiện DC Lead Off Detection  thì true
      return true;
  }else {return false;}
}