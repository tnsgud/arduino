#include <Arduino.h>

const int BUTTON =2;

boolean buttonState =LOW;
boolean lastButtonState =LOW;

int cnt = 0;

void setup() {
  pinMode(BUTTON,INPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(BUTTON);

  if(buttonState != lastButtonState){
    if(buttonState == LOW){
      cnt++;
      Serial.println(cnt);
    }
    delay(50);
  }
  lastButtonState = buttonState;
}