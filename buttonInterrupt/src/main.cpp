#include <Arduino.h>

const byte ledPin = 13;
const byte interruptPin = 2;
volatile boolean state = LOW;

void blink() {
  state = !state;
}

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, RISING);
}

// attachInterrupt(인터럽트 핀번호, 실행할 함수, 모드) : 하드뒈어 인터럽트
// digitalPinToInterrupt : 디지털 핀 번호를 넣으면 인터럽트 핀 번호로 바꿔줌

void loop() {
  if(state) {
    for (int i = 0; i < 3; i++)
    {
      digitalWrite(ledPin, HIGH);
      delay(500);
      digitalWrite(ledPin, LOW);
      delay(500);
    }
    state = !state;
  }
  // digitalWrite(ledPin, state);
}