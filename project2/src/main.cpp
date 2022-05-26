#include <Arduino.h>

const int debounceDelay = 10;

const int led1 = 6;
const int led2 = 7;
const int led3 = 8;
const int led4 = 9;

const int sw1 = 2;
const int sw2 = 3;
const int sw3 = 5;
const int sw4 = 6;

byte last_sw1_state = HIGH;
byte last_sw2_state = HIGH;
byte last_sw3_state = HIGH;
byte last_sw4_state = HIGH;

byte sw1_state;
byte sw2_state;
byte sw3_state;
byte sw4_state;

bool led1_flag;
bool led2_flag;

const int ON = 219;
const int OFF = 0;

boolean debounce(int pin) {
  boolean state;
  boolean previousState;

  previousState = digitalRead(pin);
  for (int i = 0; i < debounceDelay; i++)
  {
    delay(1);
    state = digitalRead(pin);
    if(state != previousState) {
      i = 0;
      previousState = state;
    }
  }
  
  return state;
}

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(sw3, INPUT);
  pinMode(sw4, INPUT);
}

void loop() {
  sw1_state = debounce(sw1);
  sw2_state = debounce(sw2);
  sw3_state = debounce(sw3);
  sw4_state = debounce(sw4);

  if(sw1_state != last_sw1_state) {
    last_sw1_state = sw1_state;
    if(led1_flag && sw1_state == LOW) {
      analogWrite(led1, OFF);
    }else {
      analogWrite(led1, ON);
    }
    // led1_flag = !led1_flag;
  }

  if(sw2_state != last_sw2_state) {
    for (int i = 0; i < 2; i++){
      analogWrite(led2, ON);
      delay(100);
      analogWrite(led2, OFF);
    }
  }

}