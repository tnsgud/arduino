#include <Arduino.h>

const int min = 0;
const int max = 600;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensor_reading = constrain(analogRead(A0), min, max);
  int range = map(sensor_reading, min, max, 0, 3);

  switch (range) {
  case 0:
    Serial.println("dark");
    break;

  case 1:
    Serial.println("dim");
    break;

  case 2:
    Serial.println("medium");
    break;
  
  case 3:
    Serial.println("bright");
    break;
  }

  delay(1);
}