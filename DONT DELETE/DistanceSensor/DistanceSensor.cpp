//
// Created by Sheldon on 3/26/2017.
//
#include "DistanceSensor.h"

DistanceSensor::DistanceSensor(int trigPin, int echoPin) {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  _trigPin = trigPin;
  _echoPin = echoPin;
  _previousMicros = 0;
  _onTime = 10;
  _offTime = 2;
  _distance = 0;
}

long DistanceSensor::getDistance() {
  _currentMicros = micros();
  _trigState = LOW;
  digitalWrite(_trigPin, _trigState);

  for (int i = 0; i < 2; i++) {
    if ((_trigState == HIGH) && (_currentMicros - _previousMicros >= _onTime)) {
      _trigState = LOW;  // Turn it off
      _previousMicros = _currentMicros;
      digitalWrite(_trigPin, _trigState);
    } else if ((_trigState == LOW) && (_currentMicros - _previousMicros >= _offTime)) {
      _trigState = HIGH;  // turn it on
      _previousMicros = _currentMicros ;
      digitalWrite(_trigPin, _trigState);
    }
  }

  _duration = pulseIn(_echoPin, HIGH);
  //_distance = (_duration / 2) / 29.1;
  _distance = (_duration*0.034)/2;
  return _distance;
}