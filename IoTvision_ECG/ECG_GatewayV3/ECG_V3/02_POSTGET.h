#ifndef _POSTGET_h
#define _POSTGET_h

#include "ECG_V3.h"         // Có define debug để bật/tắt các debug ra Serial.
#include <Arduino.h>     // Để khai báo kiểu String
#include <HTTPClient.h>  // Cho phép khai báo kiểu HTTPClient
#include "WiFi.h"  // Thư viện WiFi của ESP32.
#include <ArduinoJson.h>

class POSTGET {
private:
  // WiFiClient client;
  HTTPClient http;
  bool isConnected = false;
public:
  bool POSTDuLieuBoard(String ID, String DuLieu);
  String GETLenhGuiXuongBoard(String ID);
  void CapNhatCODETrongDatabaseTrenServer(String ID, String DuLieu);
};

#endif
