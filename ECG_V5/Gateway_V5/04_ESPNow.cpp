#include "04_ESPNow.h"

esp_now_peer_info_t peerInfo;  // khai báo để add thiết bị vào
// std::vector<std::string> ESPNOW::receivedData;

// String ESPNOW::receivedData = "";
char MacAddressRC[18];
void ESPNOW::khoitao_NhanFIFO(esp_now_recv_cb_t cb) {


  // WiFi.disconnect();

  for (int i = 0; i < 6; ++i) {
    sscanf(MACMaster + 2 * i, "%2hhx", &MACMasterDungDinhDang[i]);
  }
  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
#ifdef debug
    Serial.println("Error initializing ESP-NOW");
#endif
    return;
  }
  // memset(&peerInfo, 0, sizeof(peerInfo));
  //copy chuỗi mảng char sang peerInfo
  memcpy(peerInfo.peer_addr, MACMasterDungDinhDang, 6);  //
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  // Add peer
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
#ifdef debug
    Serial.println("Failed to add peer");
#endif
    return;
  }
  esp_now_register_recv_cb(cb);

  // esp_now_register_send_cb(ESPNOW::OnDataSent);
  // Register for a callback function that will be called when data is received
}

//call back when data is send
// void ESPNOW::OnDataSent(const uint8_t* mac_addr, esp_now_send_status_t status) {
// #ifdef debugEspnow
//   Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Gửi dữ liệu thành công" : "Gửi dữ liệu thất bại");
// #endif
// }
// // Callback when data is received
// void ESPNOW::OnDataRecv(const esp_now_recv_info_t* recv_info, const unsigned char* incomingData, int len) {
//   // receivedData.clear();
//   // receivedData.push_back(std::string((const char*)incomingData,len));
//   snprintf(MacAddressRC, sizeof(MacAddressRC), "%02x:%02x:%02x:%02x:%02x:%02x",
//            recv_info->src_addr[0], recv_info->src_addr[1], recv_info->src_addr[2], recv_info->src_addr[3], recv_info->src_addr[4], recv_info->src_addr[5]);

//   memcpy(&FIFO_RECEIVER, incomingData, sizeof(FIFO_RECEIVER));
//   ManagerBoard[0].EcgWave = FIFO_RECEIVER.EcgWave;
//   ManagerBoard[0].HR = FIFO_RECEIVER.HR;
//   ManagerBoard[0].RR = FIFO_RECEIVER.RR;
//   ManagerBoard[0].Bat = FIFO_RECEIVER.Bat;

// #ifdef debug
//   Serial.print(ManagerBoard[0].EcgWave);
//   Serial.print(" ");
//   Serial.print(ManagerBoard[0].HR);
//   Serial.print(" ");
//   Serial.print(ManagerBoard[0].RR);
//   Serial.print(" ");
//   Serial.print(ManagerBoard[0].Bat);
//   Serial.println();
// #endif
// }
