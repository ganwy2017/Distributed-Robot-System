#include <Encoder.h>
#include <Drive.h>
#include <UltraSound.h>

// ENCODER PINS
#define pinA 2
#define pinB A2

// MOTOR PINS
#define dirPinL 13
#define dirPinR 12
#define speedPinL 11
#define speedPinR 3
#define brakePinL 8
#define brakePinR 9

// ULTRASONIC SENSOR PINS
#define trigPinL 6
#define trigPinR 4
#define echoPinL 7
#define echoPinR 5

Encoder encoder(pinB);
UltraSound ultraSoundL(trigPinL, echoPinL);
UltraSound ultraSoundR(trigPinR, echoPinR);
Drive drive(brakePinL, brakePinR, dirPinL, dirPinR, speedPinL, speedPinR);


void setup() 
{ 
  attachInterrupt(digitalPinToInterrupt(pinA), test, RISING);
  Serial.begin (9600);
} 

void loop() 
{ 
  long pos;                                   // Shaft position from encoder
  long pingL;                                 // Left ultra-sound ping
  long pingR;                                 // Right ultra-sound ping
  long distL;                                 // Left: distance to nearest object
  long distR;                                 // Right: distance to nearest object

  pingL = ultraSoundL.ping();                // Ping for each ultra-sonic sensor
  pingR = ultraSoundR.ping();
  
  distL = ultraSoundL.microsecondsToCentimeters(pingL);   // Ping to distance
  distR = ultraSoundR.microsecondsToCentimeters(pingR);

  if (distL < 10 || distR < 10)
  {
    drive.reverse();
  }
  else
  {
    drive.forward(255, 255);
  }    
}

void test()
{
  encoder.update();
}


