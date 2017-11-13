#include <Actuator.h>

#define enL 5
#define enR 6
#define dirL 4
#define dirR 7

Actuator motors(enL, enR, dirL, dirR);

char command = '\0';

void setup() {
  Serial.begin(9600);
}

void loop() {
  //  for (int i = 0; i<=255; i++) {
  //    motors.forward(i);
  //    delay(10);
  //  }
  //  for (int i = 255; i>=0; i--) {
  //    motors.forward(i);
  //    delay(10);
  //  }
  if (Serial.available() > 0) {
    command = Serial.read();
    switch (command) {
      case 'w':
      case 'W':
        Serial.println("Move forward");
        motors.forward();
        break;

      case 's':
      case 'S':
        Serial.println("Move backward");
        motors.reverse();
        break;

      case 'a':
      case 'A':
        Serial.println("Turn left");
        motors.left();
        break;

      case 'd':
      case 'D':
        Serial.println("Turn right");
        motors.right();
        break;

      case 'q':
        Serial.println("Stop");
        motors.stop();
        break;

      default:
//        Serial.println("Command not listed");
//        motors.stop();
        break;
    }
  }
}
