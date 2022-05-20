#include <Arduino.h>

//LED1 = 1초마다 led2 = 버튼으로 제어
const byte btn1 = 3, led1 = 12, led2 = 13;

unsigned long time = 1000;

boolean led1State = false, led2State = false, pre_btn_state = false, btn_state;

void setup() {
  pinMode(btn1, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  digitalWrite(led1, led1State);
  digitalWrite(led2, led2State);
}

void loop() {
  btn_state = digitalRead(btn1);
  led2State = digitalRead(led2);

  if(btn_state != pre_btn_state){
    if(btn_state == HIGH){
      led2State = !led2State;
      digitalWrite(led2, led2State);
    }
  }

  digitalWrite(led1, led1State);
  if(millis()%time == 0) {
    led1State = !led1State;
  }
  //delay(time);
  pre_btn_state = btn_state;
}