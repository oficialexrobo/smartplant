void onWebSocketEvent(AsyncWebSocket* server, AsyncWebSocketClient* client, AwsEventType type, void* arg, uint8_t* data, size_t len) {
  if (type == WS_EVT_CONNECT) {
    Serial.print("Device connected!");
  } else if (type == WS_EVT_DISCONNECT) {
    Serial.println("Device disconnected!");
  } else if (type == WS_EVT_DATA) {
    // HERE YOU MAY CONTROLL THE PUMP MANUALLY
  }
}
