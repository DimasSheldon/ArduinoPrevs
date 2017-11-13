#include "BlinkLED.h"

int led1Pin = 3;
BlinkLED led1(led1Pin, 250, 150);
void setup() {
}

void loop() {
  led1.doBlink();
}
