#include <LCD.h>
#include <Wire.h>
#include <Drive.h>
#include <UltraSound.h>
#include <LiquidCrystal_I2C.h>

// ULTRASONIC SENSOR PINS
#define trigPinS 6
#define trigPinF 4
#define echoPinS 7
#define echoPinF 5

// MOTOR PINS
#define dirPinL 13
#define dirPinR 12
#define speedPinL 11
#define speedPinR 3
#define brakePinL 8
#define brakePinR 9

// L2C ADDRESS AND LCD PINS
#define i2cAddr 0x3F
#define rsPin 0
#define rwPin 1
#define enPin 2
#define backlightPin 3
#define d4Pin 4
#define d5Pin 5
#define d6Pin 6
#define d7Pin 7

LiquidCrystal_I2C lcd(i2cAddr, enPin, rwPin, rsPin, d4Pin, d5Pin, d6Pin, d7Pin);
Drive drive(brakePinL, brakePinR, dirPinL, dirPinR, speedPinL, speedPinR);
UltraSound ultraSoundS(trigPinS, echoPinS);
UltraSound ultraSoundF(trigPinF, echoPinF);

void setup()
{
  lcd.begin(16, 2);                            // LCD screen is 16 x 2
  lcd.setBacklightPin(backlightPin, POSITIVE);
  lcd.setBacklight(HIGH);                      // Switch on the backlight
  lcd.clear();                                 // Clear screen and move cursor to (0, 0)
  lcd.clear();
  lcd.print("Ready");
}

void loop() 
{
  long pingS;                                 // Left ultra-sound ping
  long pingF;                                 // Right ultra-sound ping
  long distS;                                 // Left: distance to nearest object
  long distF;                                 // Right: distance to nearest object

  pingS = ultraSoundS.ping();                // Ping for each ultra-sonic sensor
  pingF = ultraSoundF.ping();
  
  distS = ultraSoundS.microsecondsToCentimeters(pingS);   // Ping to distance
  distF = ultraSoundF.microsecondsToCentimeters(pingF);
  
  if (distS < 10 && distF > 10)               // If too close to wall
  {
    drive.forward(200, 255);
  }
  else if (distS > 12 && distF > 10)          // If too far from wall
  {
    drive.forward(255, 200);
  }
  else if (distS > 10 && distS < 12 && distF > 10)
  {
    drive.forward(255, 255);
  }
  else if (distF < 10)
  {
    drive.brake();
    drive.twistRight();
    delay(750);
  }
  
  delay(10);

}

