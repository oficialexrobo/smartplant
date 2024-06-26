//GET DIMENSIONS WHEN YOU HAVE THE BOTTLE ON HAND TO HAS SURE
const float fullHeight = 25.0f;
const float radius = 5.2f;
const int trigger = 10;
const int echo = 11;

//SHOULD RETURN THE VALUES IN ML
float qtd(float height) {
  return pow(radius, 2) * 3.1415f * (fullHeight - height);
}

//SHOULD RETURN THE VALUES IN PERCENT (0 TO 100)
float mappedQtd(float height) {
  if (height < 3) {
    return 100.0f;
  }
  return map(qtd(height), 0, 2000, 0, 100);
}

float distance() {
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  return pulseIn(echo, HIGH);
}


void setup() {
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  Serial.println("----------------------");
  Serial.println(distance() * 0.01723 );
  Serial.println(mappedQtd(distance() * 0.017230 ));
  delay(1000);
  
}
