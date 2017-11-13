#include <Actuator.h>
#include <BlinkLED.h>
#include <DistanceSensor.h>

#define trigPin 2
#define echoPin 3
#define enL 5
#define enR 6
#define dirL 4
#define dirR 7
#define trigPinL 8
#define echoPinL 9
#define trigPinR 10
#define echoPinR 11
#define trigPinB A2
#define echoPinB A3
#define ledPin 12
#define ledPin1 13

Actuator motors(enL, enR, dirL, dirR);
BlinkLED led(ledPin, 100, 1000);
BlinkLED led1(ledPin1, 50, 750);
DistanceSensor sensor(trigPin, echoPin);
DistanceSensor sensorL(trigPinL, echoPinL);
DistanceSensor sensorR(trigPinR, echoPinR);
DistanceSensor sensorB(trigPinB, echoPinB);

int distance;
int distanceL;
int distanceR;
int distanceB;
char command = '\0';

void setup() {
  Serial.begin(38400);
  delay(2000);
  Serial.println("Robot Ready");
}

void loop() {
  led.doBlink();
  led1.doBlink();
  if (Serial.available() > 0) {
    command = Serial.read();
    switch (command) {
      case 'w':
      case 'W':
        Serial.println("Move forward");
        motors.forward();
        command = '\0';
        break;
      case 's':
      case 'S':
        Serial.println("Move backward");
        motors.reverse();
        command = '\0';
        break;
      case 'a':
      case 'A':
        Serial.println("Turn left");
        motors.left();
        command = '\0';
        break;
      case 'd':
      case 'D':
        Serial.println("Turn right");
        motors.right();
        command = '\0';
        break;
      case 'q':
        Serial.println("Stop");
        motors.stop();
        command = '\0';
        break;
      default:
        break;
    }
  }

  distance = sensor.getDistance();
  distanceL = sensorL.getDistance();
  distanceR = sensorR.getDistance();
  distanceB = sensorB.getDistance();

  if (distance <= 20) {
    while (true) {
      motors.reverse();
      distance = sensor.getDistance();
      if (distance > 20) {
        motors.stop();
        return false;
      }
    }
  }
  if (distanceL <= 20) {
    while (true) {
      motors.right();
      distanceL = sensorL.getDistance();
      if (distanceL > 20) {
        motors.stop();
        return false;
      }
    }
  }
  if (distanceR <= 20) {
    while (true) {
      motors.left();
      distanceR = sensorR.getDistance();
      if (distanceR > 20) {
        motors.stop();
        return false;
      }
    }
  }
if (distanceB <= 20) {
    while (true) {
      motors.stop();
      delay(250);
      motors.right();
      delay(500);
      distanceB = sensorB.getDistance();
      if (distanceB > 20) {
        motors.stop();
        return false;
      }
    }
  }
//  else if (distance <= 20 && distanceL <= 20 && distanceR <= 20) {
//    while (true) {
//      motors.reverse();
//      distance = sensor.getDistance();
//      distanceL = sensorL.getDistance();
//      distanceR = sensorR.getDistance();
//      if (distance > 20 && distanceL > 20 && distanceR > 20) {
//        motors.stop();
//        return false;
//      }
//    }
//  }
}

