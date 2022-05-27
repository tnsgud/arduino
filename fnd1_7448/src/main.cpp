#include <Arduino.h>

int bcd_pins[4] = {9, 8, 7, 6};

void display_number(int num) {
  int values[] = {0, 0, 0, 0};

  switch (num) {
    case 0:
      values[0] = 0;
      values[1] = 0;
      values[2] = 0;
      values[3] = 0;
      break;
    case 1:
      values[0] = 0;
      values[1] = 0;
      values[2] = 0;
      values[3] = 1;
      break;
    case 2:
      values[0] = 0;
      values[1] = 0;
      values[2] = 1;
      values[3] = 0;
      break;
    case 3:
      values[0] = 0;
      values[1] = 0;
      values[2] = 1;
      values[3] = 1;
      break;
    case 4:
      values[0] = 0;
      values[1] = 1;
      values[2] = 0;
      values[3] = 0;
      break;
    case 5:
      values[0] = 0;
      values[1] = 1;
      values[2] = 0;
      values[3] = 1;
      break;
    case 6:
      values[0] = 0;
      values[1] = 1;
      values[2] = 1;
      values[3] = 0;
      break;
    case 7:
      values[0] = 0;
      values[1] = 1;
      values[2] = 1;
      values[3] = 1;
      break;
    case 8:
      values[0] = 1;
      values[1] = 0;
      values[2] = 0;
      values[3] = 0;
      break;
    case 9:
      values[0] = 1;
      values[1] = 0;
      values[2] = 0;
      values[3] = 1;
      break;
  }

  for (int i = 0; i < 4; i++)
  {
    digitalWrite(bcd_pins[i], values[i]);
  }
}

void setup() {
  for (int i = 0; i < 4; i++)
  {
    pinMode(bcd_pins[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < 10; i++)
  {
    display_number(i);
    delay(500);
  }
}
