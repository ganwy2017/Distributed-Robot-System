/*
  Drive.cpp - Library for dual motor control of a four wheeled vehicle.
  Created by Samuel T. Westlake, February 4, 2017.
*/
#ifndef Drive_h
#define Drive_h

#include "Arduino.h"

class Drive
{
	public:
		Drive(int brakePinL, int brakePinR, int dirPinL, int dirPinR, int speedPinL, int speedPinR);
		void brake();
		void forward(int vL, int vR);
		void reverse(int vL, int vR);
		void twistRight();
		void twistLeft();
	private:
		int _brakePinL;
		int _brakePinR;
		int _dirPinL;
		int _dirPinR;
		int _speedPinL;
		int _speedPinR;
};

#endif
