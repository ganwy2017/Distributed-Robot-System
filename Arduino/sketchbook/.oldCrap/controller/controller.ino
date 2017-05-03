#include <LCD.h>
#include <Wire.h>
#include <Drive.h>
#include <UltraSound.h>
#include <LiquidCrystal_I2C.h>
#include <Encoder.h>

// ULTRASONIC SENSOR PINS
#define trigPinR 4
#define trigPinL 6
#define echoPinR 5
#define echoPinL 7

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
UltraSound ultraSoundL(trigPinL, echoPinL);
UltraSound ultraSoundR(trigPinR, echoPinR);

void setup() {
  // LCD SETUP
  lcd.begin(16, 2);                             // LCD screen is 16 x 2
  lcd.setBacklightPin(backlightPin, POSITIVE);
  lcd.setBacklight(HIGH);                       // Switch on the backlight
  lcd.clear();                                  // Clear screen and move cursor to (0, 0)
  lcd.clear();
  lcd.print("Ready...");
  
  Serial.begin(9600);
}

void loop() {
  long pingL;                                             // Left ultra-sound ping
  long pingR;                                             // Right ultra-sound ping
  long distL;                                             // Left: distance to nearest object
  long distR;                                             // Right: distance to nearest object
  int vL;
  int vR;

  pingL = ultraSoundL.ping();                             // Ping for each ultra-sonic sensor
  pingR = ultraSoundR.ping();
  distL = ultraSoundL.microsecondsToCentimeters(pingL);   // Ping to distance
  distR = ultraSoundR.microsecondsToCentimeters(pingR);

  if ((distL < 15 && distL != 0) || (distR < 15 && distR != 0)){
    if (distL < distR) {
      drive.reverse(255, 255);
      delay(500);
      drive.twistRight();
    }
    else {
      drive.reverse(255, 255);
      delay(100);
      drive.twistLeft();
    }
    delay(750);
  }
  else if ((distL < 80 && distL != 0) || (distR < 80 && distL != 0)) {
    if (distL < distR) {
      vL = 255;
      vR = 50;
    }
    else {
      vL = 50;
      vR = 255;
    }
    drive.forward(vL, vR);
  }
  else {
    drive.forward(255, 255);
  }
  
}


