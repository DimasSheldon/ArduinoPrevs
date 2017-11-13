#include <Actuator.h>
#include <BlinkLED.h>

#define enFL 5
#define enFR 6
#define dirFL 4
#define dirFR 7
#define enRL 9
#define enRR 10
#define dirRL 8
#define dirRR 11
#define ledPin 13
Actuator frontActuator(enFL, enFR, dirFL, dirFR);
Actuator rearActuator(enRL, enRR, dirRL, dirRR);
BlinkLED led(ledPin, 100, 1000);
char command = '\0';

void setup() {
  Serial.begin(38400);
}

void loop() {
  led.doBlink();
  if (Serial.available() > 0) {
    command = Serial.read();
    switch (command) {
      case 'w':
      case 'W':
        Serial.println("Move forward");
        frontActuator.forward();
        rearActuator.forward();
        command = '\0';
        break;
      case 's':
      case 'S':
        Serial.println("Move backward");
        frontActuator.reverse();
        rearActuator.reverse();
        command = '\0';
        break;
      case 'a':
      case 'A':
        Serial.println("Turn left");
        frontActuator.left();
        rearActuator.left();
        command = '\0';
        break;
      case 'd':
      case 'D':
        Serial.println("Turn right");
        frontActuator.right();
        rearActuator.right();
        command = '\0';
        break;
      case 'q':
        Serial.println("Stop");
        frontActuator.stop();
        rearActuator.stop();
        command = '\0';
        break;
      default:
        break;
    }
  }
}
