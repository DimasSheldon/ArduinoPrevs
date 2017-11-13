#include <TheRobot.h>


TheRobot theRobot(5, 6, 4, 7); //enL, enR, dirL, dirR
char command = '\0';

void setup() {
  Serial.begin(38400);
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();

    swcitch (command) {
    case 'w':
    case'W':
      Serial.println("Forward");
      theRobot.forward();
      command = '\0';
      break;
    case 's':
    case 'S':
      Serial.println("Backward");
      theRobot.backward();
      command = '\0';
      break;
    case 'a':
    case 'A':
      Serial.println("Left");
      theRobot.turnLeft();
      command = '\0';
      break;
    case 'd':
    case 'D':
      Serial.println("Right");
      theRobot.turnRight();
      command = '\0';
      break;
    case 'q':
    case 'Q':
      Serial.println("Stop");
      theRobot.noMove();
      command = '\0';
      break;
    default:
      break;
    }
  }
}
