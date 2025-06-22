#include "04_ESPNow.h"

esp_now_peer_info_t peerInfo;  // khai báo để add thiết bị vào
void ESPNOW::khoitao() {
  WiFi.mode(WIFI_STA);

  for (int i = 0; i < 6; ++i) {
    sscanf(MACMaster + 2 * i, "%2hhx", &MACMasterDungDinhDang[i]);
  }
  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
#ifdef debugEspnow
    Serial.println("Error initializing ESP-NOW");
#endif
    return;
  }
  // Once ESPNow is successfully Init, we will register for Send CB to
  // get the status of Trasnmitted packet


  // Register peer
  // memset(&peerInfo, 0, sizeof(peerInfo));
  memcpy(peerInfo.peer_addr, MACMasterDungDinhDang, 6); // 
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  // Add peer
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
#ifdef debug
    Serial.println("Failed to add peer");
#endif
    return;
  }
  esp_now_register_send_cb(ESPNOW::OnDataSent);
  // Register for a callback function that will be called when data is received
  // esp_now_register_recv_cb(ESPNOW::OnDataRecv);
}
void ESPNOW::OnDataSent(const uint8_t* mac_addr, esp_now_send_status_t status) {
#ifdef debugEspnow
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Gửi dữ liệu thành công" : "Gửi dữ liệu thất bại");
#endif
}
// Callback when data is received
void ESPNOW::OnDataRecv(const esp_now_recv_info_t* recv_info, const unsigned char* incomingData, int len) {
  if (len > 0) {
#ifdef debugEspnow
    Serial.println("Đã nhận phản hồi Esp32 Gateway");
#endif
  }
}