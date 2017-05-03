/*
  Drive.cpp - Library for dual motor control of a four wheeled vehicle.
  Created by Samuel T. Westlake, February 4, 2017.
*/
#include "Arduino.h"
#include "Drive.h"

Drive::Drive(int brakePinL, int brakePinR, int dirPinL, int dirPinR, int speedPinL, int speedPinR)
{
	pinMode(brakePinL, OUTPUT);
	pinMode(brakePinR, OUTPUT);
	pinMode(dirPinL, OUTPUT);
	pinMode(dirPinR, OUTPUT);
	pinMode(speedPinL, OUTPUT);
	pinMode(speedPinR, OUTPUT);
	
	_brakePinL = brakePinL;
	_brakePinR = brakePinR;
	_dirPinL = dirPinL;
	_dirPinR = dirPinR;
	_speedPinL = speedPinL;
	_speedPinR = speedPinR;
}

void Drive::brake()
{
	digitalWrite(_brakePinL, HIGH);
	digitalWrite(_brakePinR, HIGH);
}

void Drive::forward(int vL, int vR)
{
	digitalWrite(_brakePinL, LOW);
	digitalWrite(_brakePinR, LOW);
	digitalWrite(_dirPinL, HIGH);
	digitalWrite(_dirPinR, HIGH);
	analogWrite(_speedPinL, vL);
	analogWrite(_speedPinR, vR);
}

void Drive::reverse(int vL, int vR)
{
	digitalWrite(_brakePinL, LOW);
	digitalWrite(_brakePinR, LOW);
	digitalWrite(_dirPinL, LOW);
	digitalWrite(_dirPinR, LOW);
	analogWrite(_speedPinL, vL);
	analogWrite(_speedPinR, vR);
}

void Drive::twistRight()
{
	digitalWrite(_brakePinL, LOW);
	digitalWrite(_brakePinR, LOW);
	digitalWrite(_dirPinL, HIGH);
	digitalWrite(_dirPinR, LOW);
	analogWrite(_speedPinL, 255);
	analogWrite(_speedPinR, 255);
}

void Drive::twistLeft()
{
	digitalWrite(_brakePinL, LOW);
	digitalWrite(_brakePinR, LOW);
	digitalWrite(_dirPinL, LOW);
	digitalWrite(_dirPinR, HIGH);
	analogWrite(_speedPinL, 255);
	analogWrite(_speedPinR, 255);
}