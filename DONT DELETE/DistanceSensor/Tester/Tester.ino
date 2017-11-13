/*
 * Distance sensor HCSR-04 tester
 * Author       : Dimas Sheldon
 * Date Created : March 26, 2017
 */
#include <DistanceSensor.h>

#define trigPin 2
#define echoPin 3
#define trigPinL 8
#define echoPinL 9
#define trigPinR 10
#define echoPinR 11

DistanceSensor sensor(trigPin, echoPin);
DistanceSensor sensorL(trigPinL, echoPinL);
DistanceSensor sensorR(trigPinR, echoPinR);
long distance = 0;
long distanceL = 0;
long distanceR = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  distance = sensor.getDistance();
  distanceL = sensorL.getDistance();
  distanceR = sensorR.getDistance();

  Serial.print("Mid distance: ");
  Serial.println(distance);
  Serial.print("Left distance: ");
  Serial.println(distanceL);
  Serial.print("Right distance: ");
  Serial.println(distanceR);
}
