/*
  UltraSound.cpp - Library for control of ultrasonic sensor.
  Created by Samuel T. Westlake, February 4, 2017.
*/
#ifndef UltraSound_h
#define UltraSound_h

#include "Arduino.h"

class UltraSound
{
	public:
		UltraSound(int trigPin, int echoPin);
		int ping(int=23200);
		int centimetersInAir(int microseconds);
		int inchesInAir(int microseconds);
	private:
		int _trigPin;
		int _echoPin;
};

#endif