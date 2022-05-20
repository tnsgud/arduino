#include <Arduino.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  char sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  delay(1);

}