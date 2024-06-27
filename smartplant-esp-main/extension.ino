void toggleLed(unsigned long millis) {
  if (millisInSeconds(millis) % 2 == 0) {
    incorporatedLed.write(HIGH);
  } else {
    incorporatedLed.write(LOW);
  }
}

void log(unsigned long currentMillis, int light, int soil, int rain, int distance) {
  Serial.println("-------------------------");
  Serial.print("[WiFi] IP: ");
  Serial.print(WiFi.localIP());
  Serial.print(" - GATEWAY: ");
  Serial.println(gateway);
  Serial.print("Seconds running: ");
  Serial.println(millisInSeconds(currentMillis));
  Serial.print("Light: ");
  Serial.println(light);
  Serial.print("Soil humidity: ");
  Serial.println(soil);
  Serial.print("Rain: ");
  Serial.println(rain);
  Serial.print("Distance: ");
  Serial.println(distance);
}

void mainLoop() {
  const int currentMilis = millis();
  const int humidity = map(soilSensor.readAnalog(), 0, 4095, 0, 100);
  const int light = map(lightSensor.readAnalog(), 0, 4095, 0, 100);
  const int rain = map(rainSensor.readAnalog(), 0, 4095, 0, 100);
  const int waterQtd =  0;
 
  log(currentMilis, light, humidity, rain, waterQtd);
  //ORDER -> humidity, light, rain, water,ledState,pumpState
  sprintf(dataString, "%d,%d,%d,%d,%d,%d", humidity, light, rain, waterQtd, ledState ? 1 : 0, pumpState ? 1 : 0);
  incorporatedLed.write(ledState ? HIGH : LOW);
  if (pumpState) {
    rele.write(LOW);
    delay(5000);
    pumpState = false;
    rele.write(HIGH);
  }else{
    delay(1000);
  }
}

void testRele() {
  rele.write(pumpState ? HIGH : LOW);
  pumpState = !pumpState;
  delay(2000);
}