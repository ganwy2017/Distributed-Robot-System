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
		long ping();
		long microsecondsToCentimeters(long microseconds);
	private:
		int _trigPin;
		int _echoPin;
};

#endif