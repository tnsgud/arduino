#include <Arduino.h>

const int debounceDelay = 10;

const int led1 = 6;
const int led2 = 7;
const int led3 = 8;

const int sw1 = 2;
const int sw2 = 3;
const int sw3 = 5;

byte last_sw1_state = HIGH;
byte last_sw2_state = HIGH;
byte last_sw3_state = HIGH;

byte sw1_state;
byte sw2_state;
byte sw3_state;

bool led1_flag;
bool led2_flag;

const int fade[8] = {0, 37, 73, 110, 146, 182, 219, 255};

void initialize() {
  analogWrite(led1, 255);
  analogWrite(led2, 0);
  analogWrite(led3, 0);
  led1_flag = true;
  led2_flag = false;
  Serial.println("Initialize");
}

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

void led1_fade_out_led2_fade_in() {
  for (int i = 0; i < 8; i++) {
    analogWrite(led2, fade[i]);
    analogWrite(led1, fade[7-i]);
    delay(125);
  }
  led1_flag = false;
  led2_flag = true;
}

void led3_2_times_blink() {
  for (int i = 0; i < 2; i++)
  {
    analogWrite(led3, 255);
    delay(1000);
    analogWrite(led3, 0);
    delay(1000);
  }
}

void led1_fade_in_led2_fade_out() {
  for (int i = 0; i < 8; i++)
  {
    analogWrite(led1, fade[i]);
    analogWrite(led2, fade[7-i]);
    delay(125);
  }

  led1_flag = true;
  led2_flag = false;
}

void all_led_2_times_blink_then_led1_on_led2_led3_off() {
  for (int i = 0; i < 2; i++)
  {
    analogWrite(led1, 255);
    analogWrite(led2, 255);
    analogWrite(led3, 255);
    delay(1000);
    analogWrite(led3, 0);
    analogWrite(led2, 0);
    analogWrite(led1, 0);
    delay(1000);
  }

  analogWrite(led1, 255);

  led1_flag = true;
  led2_flag = false;  
}

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  initialize();  
}

void loop() {
  sw1_state = debounce(sw1);
  sw2_state = debounce(sw2);
  sw3_state = debounce(sw3);

  if(sw1_state != last_sw1_state) {
    last_sw1_state = sw1_state;
    
    if(sw1_state == LOW && led1_flag && !led2_flag) {
      Serial.println("SW1 condition 1 pressed");
      led1_fade_out_led2_fade_in();
    }else if(sw1_state == LOW && !led1_flag && led2_flag) {
      Serial.println("SW1 condition 2 pressed");
      led3_2_times_blink();
    }
  }

  if(sw2_state != last_sw2_state) {
    last_sw2_state = sw2_state;

    if(sw2_state == LOW && !led1_flag && led2_flag) {
      Serial.println("SW2 condition 1 pressed");
      led1_fade_in_led2_fade_out();
    }else if(sw2_state == LOW && led1_flag && !led2_flag) {
      Serial.println("SW2 condition 2 pressed");
      led3_2_times_blink();
    }
  }

  if(sw3_state != last_sw3_state) {
    last_sw3_state = sw3_state;

    if(sw3_state == LOW) {
      Serial.println("SW3 condition pressed");
      all_led_2_times_blink_then_led1_on_led2_led3_off();
    }
  }
}