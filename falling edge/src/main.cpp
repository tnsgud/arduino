#include <Arduino.h>

const int BUTTON =2;
const int LED =13;

boolean buttonState =LOW;
boolean lastButtonState =LOW;
boolean ledState =LOW;


void setup() {
  pinMode(BUTTON,INPUT);
  pinMode(LED,OUTPUT);
}

void loop() {
  buttonState = digitalRead(BUTTON);
  ledState = digitalRead(LED);

  if(buttonState != lastButtonState){
    if(buttonState == HIGH){
      ledState = !ledState;
      digitalWrite(LED, ledState);
    }
    delay(50);
  }
  lastButtonState = buttonState;
}