//
// Created by Sheldon on 3/26/2017.
//

#ifndef TRYFIRST_DISTANCESENSOR_H
#define TRYFIRST_DISTANCESENSOR_H

#include "Arduino.h"

class DistanceSensor {
public:
    DistanceSensor(int trigPin, int echoPin);

    long getDistance();

private:
    int _trigPin;
    int _echoPin;
    int _onTime;
    int _offTime;
    int _trigState;
    int _distance;
    long _duration;
    unsigned long _currentMicros;
    unsigned long _previousMicros;
};

#endif //TRYFIRST_DISTANCESENSOR_H
