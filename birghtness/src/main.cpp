#include <Arduino.h>

int LED = 13;
int brightness = 0;
int fade_amount = 5;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  analogWrite(LED, brightness);
  brightness = brightness + fade_amount;
  if(brightness <= 0 || brightness >= 255) fade_amount = -fade_amount;
  delay(30);
}