#ifndef _ESPNow_h
#define _ESPNow_h

#include "Gateway_V5.h"  // Có define debug để bật/tắt các debug ra Serial.
#include <Arduino.h>
#include <ESP32_NOW.h>
#include <WiFi.h>
#include "esp_wifi.h"

// VECTOR
#include <vector>
#include <algorithm>
#include <string>

#include "07_LoRa.h"
#define max_length 20

class ESPNOW {
public:
  char MACMaster[max_length];
  uint8_t MACMasterDungDinhDang[6];
  // static std::vector<std::string>receivedData;
  // static String receivedData;
  char MacAddressRC[18];
public:
  void khoitao_NhanFIFO(esp_now_recv_cb_t cb );
  // void khoitao_GuiFiFO(esp_now_send_cb_t cb);
private:
  // static void OnDataSent(const uint8_t* mac_addr, esp_now_send_status_t status);
  // static void OnDataRecv(const esp_now_recv_info_t* recv_info, const unsigned char* incomingData, int len);
};

#endif
