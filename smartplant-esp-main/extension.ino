void toggleLed(unsigned long millis) {
  if (millisInSeconds(millis) % 2 == 0) {
    incorporatedLed.write(HIGH);
  } else {
    incorporatedLed.write(LOW);
  }
}

void log(unsigned long currentMillis, Pin lightSensor, Pin soilSensor,Pin rainSensor) {
  if (currentMillis % 1000 == 0 && currentMillis % 2 == 0) {
    Serial.println("___________________________");
    Serial.print("Seconds running: ");
    Serial.println(millisInSeconds(currentMillis));
    Serial.print("Light: ");
    Serial.println(lightSensor.readAnalog());
    Serial.print("Soil humidity: ");
    Serial.println(soilSensor.readAnalog());
    Serial.print("Rain: ");
    Serial.println(rainSensor.readAnalog());
  }
}