#include "Arduino.h"
#include "UltraSound.h"

UltraSound::UltraSound(int trigPin, int echoPin)
{
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	_trigPin = trigPin;
	_echoPin = echoPin;
}

int UltraSound::ping(int timeout)
{
	// Generates pulse on _trigPin 
	// Returns the time to before an echo is detected on _echoPin in microseconds
	// Default timeout of 23200 microseconds corresponds to the 400cm maximum 
	// effective range of the HC-SR04 sonar
	digitalWrite(_trigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(_trigPin, HIGH);
	delayMicroseconds(5);
	digitalWrite(_trigPin, LOW);
	return pulseIn(_echoPin, HIGH, timeout); 
}

int UltraSound::centimetersInAir(int microseconds)
{
	// Speed = 29 microseconds per centimeter
	// Divide by two to account for return journey 
	return microseconds / 58;
}

int UltraSound::inchesInAir(int microseconds)
{
	// Speed = 74 microseconds per inch
	// Divide by two to account for return journey 
	return microseconds / 148;
}