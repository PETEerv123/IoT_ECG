#ifndef _ChuongTrinhChinh_h
#define _ChuongTrinhChinh_h


#include "ECG_V3.h"  // Có define debug để bật/tắt các debug ra Serial.
#include <Arduino.h>
  

#define PIN_BATTERY 4        // GPIO34 là chân ADC
#define R1 220000.0           // 100k Ohm
#define R2 100000.0           // 100k Ohm

#define NutBoot 9
#define CS_PIN_MAX30003 10  // Chân CS của MAX30003
#define CS_PIN_ADXL345 3

#define SO 5
#define SI 7
#define SCK 6
#define INT 8

#define PIN_BATTERY 4

void KhoiTao(void);               
void ChayChuongTrinhChinh(void);  

void ThucThiTacVuTheoFLAG(void);
// static int nap(unsigned int timeout_sec, int uart);

#endif
