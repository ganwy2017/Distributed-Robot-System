/*
  Encoder.cpp - Library for updating position from encoder.
  Created by Samuel T. Westlake, February 7, 2017.
*/
#include "Arduino.h"
#include "Encoder.h"

Encoder::Encoder(int pinB)				
{
	pinMode(pinB, INPUT);
	_pinB = pinB;			// Channel B (used for directon)
	_pos = 0;				// Position counter
}

int Encoder::update()		// Call when there is a low -> high transition on channelA
{
	if (digitalRead(_pinB) == LOW)
	{
		_pos++;
	}
	else 
	{
		_pos--;
	}
	
	Serial.print(_pos);
	Serial.print("\n");
	return _pos;
}
