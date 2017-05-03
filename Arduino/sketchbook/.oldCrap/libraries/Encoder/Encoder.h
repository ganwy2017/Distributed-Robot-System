/*
  Encoder.cpp - Library for updating position from encoder.
  Created by Samuel T. Westlake, February 7, 2017.
*/
#ifndef Encoder_h
#define Encoder_h

#include "Arduino.h"

class Encoder
{
	public:
		Encoder(int pinB);
		int update();
	private:
		int _pinB;
		int _pos;
};

#endif