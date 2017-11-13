/*
   Robot.h - Library for controlling any 2 WD mobile platform.
   Created by Dimas Sheldon, January 30, 2017.
   Released into public domain
*/
#ifndef TheRobot_h
#define TheRobot_h

#include "Arduino.h"

class TheRobot {

	public:
	    TheRobot(int enL, int enR, int dirL, int dirR);
    void forward();
    void backward();
    void turnLeft();
    void turnRight();
    void noMove();
	
	void forward(int speed);
    void backward(int speed);
    void turnLeft(int speed);
    void turnRight(int speed);
  private:
    int _enL;
    int _enR;
    int _dirL;
    int _dirR;
};

#endif