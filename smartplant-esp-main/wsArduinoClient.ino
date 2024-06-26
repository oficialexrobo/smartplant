#include <ArduinoHttpClient.h>

// char serverAddress[] = "echo.websocket.org";
int port = 8080;

WiFiClient wifi;
WebSocketClient client = WebSocketClient(wifi, gateway, port);

void clientSendData() {
  client.beginMessage(TYPE_TEXT);
  client.print(dataString);
  client.endMessage();
}

void loopWebSocketClient() {
  Serial.println("starting WebSocket client");
  client.begin();

  while (client.connected()) {
    Serial.print("Sending data ");

    clientSendData();


    // check if a message is available to be received
    int messageSize = client.parseMessage();

    if (messageSize > 0) {
      Serial.println("Received a message:");
      Serial.println(client.readString());
    }

    // wait 5 seconds
    delay(5000);
  }

  Serial.println("disconnected");
}
