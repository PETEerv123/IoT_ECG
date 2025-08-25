#ifndef _ChuongTrinhChinh_h
#define _ChuongTrinhChinh_h

#include "Gateway_Master_V5.h"  // Có define debug để bật/tắt các debug ra Serial.
#include <Arduino.h>
#include <Arduino_JSON.h>  // Thư viện xử lý dữ liệu kiểu JSON
#include <Wire.h>          // Để kết nối I2C với mô-đun RTC (thời gian thực),
                           // mô-đun đọc cảm biến nhiệt độ & độ ẩm SHT3x.
#include "esp_wifi.h"
#define NutBoot 0

#define EN_LoRa 2
#define SCK_LoRa 4
#define MISO_LoRa 18
#define MOSI_LoRa 19
#define CS_LoRa 21
#define RST_LoRa 22
#define INT_LoRa 23 // chân Dio

// #define SCK_LoRa   18
// #define MISO_LoRa  19
// #define MOSI_LoRa  23
// #define CS_LoRa     5
// #define RST_LoRa    4

#define SCL 22
#define SDA 21
void KhoiTao(void);
void ChayChuongTrinhChinh(void);

void ThucThiTacVuTheoFLAG(void);


#endif
