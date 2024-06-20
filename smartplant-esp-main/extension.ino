void toggleLed(unsigned long millis) {
  if (millisInSeconds(millis) % 2 == 0) {
    incorporatedLed.write(HIGH);
  } else {
    incorporatedLed.write(LOW);
  }
}

void log(unsigned long currentMillis, int light, int soil,int rain) {
  if (currentMillis % 1000 == 0 && currentMillis % 2 == 0) {
    Serial.println("-------------------------");
    Serial.print("[WiFi] Connected with IP: ");
    Serial.println(WiFi.localIP()); 
    Serial.print("Seconds running: ");
    Serial.println(millisInSeconds(currentMillis));
    Serial.print("Light: ");
    Serial.println(light);
    Serial.print("Soil humidity: ");
    Serial.println(soil);
    Serial.print("Rain: ");
    Serial.println(rain);
    Serial.print("Distance: ");
    Serial.println(distance());
  }
}