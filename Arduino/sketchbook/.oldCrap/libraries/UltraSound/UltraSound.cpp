#include "Arduino.h"
#include "UltraSound.h"

UltraSound::UltraSound(int trigPin, int echoPin)
{
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	_trigPin = trigPin;
	_echoPin = echoPin;
}

long UltraSound::ping()
{
	digitalWrite(_trigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(_trigPin, HIGH);
	delayMicroseconds(5);
	digitalWrite(_trigPin, LOW);
	return pulseIn(_echoPin, HIGH); 
}

long UltraSound::microsecondsToCentimeters(long microseconds)
{
	// Speed = 29 microseconds per centimeter
	// Divide by two to account for return journey 
	return microseconds / 29 / 2;
}