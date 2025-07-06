#ifndef _ChuongTrinhChinh_h
#define _ChuongTrinhChinh_h


#include "Gateway_V4.h"  // Có define debug để bật/tắt các debug ra Serial.
#include <Arduino.h>
#include <esp_now.h>
#include <iostream>
#include <vector>
#include "esp_wifi.h"

#define NutBoot 0

#define EN_LoRa 2
#define SCK_LoRa 4
#define MISO_LoRa 18
#define MOSI_LoRa 19
#define CS_LoRa 21
#define RST_LoRa 22
#define INT_LoRa 23 // chân Dio

void KhoiTao(void);               
void ChayChuongTrinhChinh(void);  

void ThucThiTacVuTheoFLAG(void);

static void OnDataRecv(const esp_now_recv_info_t* recv_info, const unsigned char* incomingData, int len); // nhận Espnoww
#endif
