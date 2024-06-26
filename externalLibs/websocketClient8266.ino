//ESP8266-Websocket-master
//https://github.com/morrissinger/ESP8266-Websocket
#include <WebSocketClient.h>

// WiFiClient client;

char path[] = "/";
char host[] = "echo.websocket.org";

WebSocketClient webSocketClient;


void setupWSClient() {

  if (client.connect(gateway, 8080)) {
    Serial.println("Connected");
  } else {
    Serial.println("Connection failed.");
    while (1) {
      // Hang on failure
    }
  }

  // Handshake with the server
  webSocketClient.path = path;
  webSocketClient.host = host;
  if (webSocketClient.handshake(client)) {
    Serial.println("Handshake successful");
  } else {
    Serial.println("Handshake failed.");
    while (1) {
      // Hang on failure
    }
  }
}


void loopWSClient() {
  String data;

  if (client.connected()) {

    webSocketClient.getData(data);
    if (data.length() > 0) {
      Serial.print("Received data: ");
      Serial.println(data);
    }

    data = String(dataString);

    webSocketClient.sendData(data);

  } else {
    Serial.println("Client disconnected.");
    while (1) {
      // Hang on disconnect.
    }
  }

  delay(3000);
}