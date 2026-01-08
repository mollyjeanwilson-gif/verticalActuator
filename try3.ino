//This sketch uses a helper class to make the MPR121 easier to use
// The helper is in the MPR121_Helper.h tab - you don't need to modify it
// Just use the simple commands like touch.isNewTouch(0)

#include <Wire.h>
#include "Adafruit_MPR121.h"
#include "MPR121_Helper.h"

int E1 = 6;
int M1 = 7;

// Create the sensor
Adafruit_MPR121 cap = Adafruit_MPR121();
// Create the touch helper object
MPR121_Helper touch(&cap);

// constant variable for number of electrodes
const int NUM_ELECTRODES = 12;

void setup() {
 Serial.begin(9600);
 while (!Serial) { delay(10); }
 Wire.begin();
 Serial.println("MPR121 Touch Sensor Example");
  pinMode(M1, OUTPUT);
  //is the sensor detected?
 if (!cap.begin(0x5A)) {
   Serial.println("MPR121 not found, check wiring?");
   while (1);
 }
 Serial.println("MPR121 found!");
 cap.setAutoconfig(true);
}
void loop() {
 // Update touch data once per loop
 touch.updateTouchData();
 
   //is an electrode ONE touched
   if (touch.isNewTouch(6)) {
     digitalWrite(M1, HIGH);
    analogWrite(E1, 0);
   }
  
   //is an electrode ONE released
   if (touch.isNewRelease(6)) {
     digitalWrite(M1, HIGH);
      analogWrite(E1, 255);
   }
 }

 /*// Update touch data once per loop
 touch.updateTouchData();
  
   if (touch.isNewTouch(0)) {
   digitalWrite(M1, HIGH);
    analogWrite(E1, 0);
   } else {
  digitalWrite(M1, HIGH);
  analogWrite(E1, 255);
   }
  delay(100);
}*/