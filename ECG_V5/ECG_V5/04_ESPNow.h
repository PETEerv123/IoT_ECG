#ifndef _ESPNow_h
#define _ESPNow_h

#include "ECG_V5.h"  // Có define debug để bật/tắt các debug ra Serial.
#include <Arduino.h>
#include <ESP32_NOW.h>
#include <WiFi.h>

// VECTOR
#include <vector>
#include <algorithm>
#include <string>

#define max_length 100

class ESPNOW {
public:
  char MACMaster[max_length];
  uint8_t MACMasterDungDinhDang[6];
public:
  void khoitao_GuiFIFO(esp_now_send_cb_t cb);
};

#endif
