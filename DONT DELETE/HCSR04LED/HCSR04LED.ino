 /*
 * Distance sensor HCSR-04 tester
 * Author       : Dimas Sheldon
 * Date Created : March 26, 2017
 */
#include <DistanceSensor.h>
#include <BlinkLED.h>
#define trigPin 2
#define echoPin 3
#define trigPinL 8
#define echoPinL 9
#define trigPinR 10
#define echoPinR 11
#define ledPin 12
#define ledPin1 13
DistanceSensor sensor(trigPin, echoPin);
DistanceSensor sensorL(trigPinL, echoPinL);
DistanceSensor sensorR(trigPinR, echoPinR);
BlinkLED led(ledPin, 100,1000);
BlinkLED led1(ledPin1, 50,750);
long distance = 0;
long distanceL = 0;
long distanceR = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  led.doBlink();
  led1.doBlink();
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
