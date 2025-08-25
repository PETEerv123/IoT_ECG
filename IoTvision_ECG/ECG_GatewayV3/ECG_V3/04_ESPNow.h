#ifndef _ESPNow_h
#define _ESPNow_h

#include "ECG_V3.h"  // Có define debug để bật/tắt các debug ra Serial.
#include <Arduino.h>
#include <ESP32_NOW.h>
#include <WiFi.h>

// VECTOR
#include <vector>
#include <algorithm>
#include <string>

#define max_length 100

// typedef struct {
//     signed long ECGWAVE;
//     float hum;
//     float pres;
// } ECG_Data; // tên cấu trúc


class ESPNOW {
public:
  char MACMaster[max_length];
  uint8_t MACMasterDungDinhDang[6];
public:
  void khoitao(void);
private:
  static void OnDataSent(const uint8_t* mac_addr, esp_now_send_status_t status);
  static void OnDataRecv(const esp_now_recv_info_t* recv_info, const unsigned char* incomingData, int len);
};

#endif
