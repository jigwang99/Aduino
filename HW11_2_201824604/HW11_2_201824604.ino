#include <ADXL345.h>
#include <Wire.h>

ADXL345 adxl;
int ledPin = 8;
int ledState = LOW;
int toggleCount = 0;
int x, y, z;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  adxl.powerOn();

  //set activity/ inactivity thresholds (0-255)
  adxl.setActivityThreshold(75); //62.5mg per increment
  adxl.setInactivityThreshold(75); //62.5mg per increment
  adxl.setTimeInactivity(10); // how many seconds of no activity is inactive?
 
  //look of activity movement on this axes - 1 == on; 0 == off 
  adxl.setActivityX(1);
  adxl.setActivityY(1);
  adxl.setActivityZ(1);
 
  //look of inactivity movement on this axes - 1 == on; 0 == off
  adxl.setInactivityX(1);
  adxl.setInactivityY(1);
  adxl.setInactivityZ(1);
 
  //look of tap movement on this axes - 1 == on; 0 == off
  adxl.setTapDetectionOnX(0);
  adxl.setTapDetectionOnY(0);
  adxl.setTapDetectionOnZ(1);
 
  //set values for what is a tap, and what is a double tap (0-255)
  adxl.setTapThreshold(50); //62.5mg per increment
  adxl.setTapDuration(15); //625us per increment
 
  //set values for what is considered freefall (0-255)
  adxl.setFreeFallThreshold(7); //(5 - 9) recommended - 62.5mg per increment
  adxl.setFreeFallDuration(45); //(20 - 70) recommended - 5ms per increment
 
  //setting all interrupts to take place on int pin 1
  //I had issues with int pin 2, was unable to reset it
  adxl.setInterruptMapping( ADXL345_INT_SINGLE_TAP_BIT,   ADXL345_INT1_PIN );
 
  //register interrupt actions - 1 == on; 0 == off  
  adxl.setInterrupt( ADXL345_INT_SINGLE_TAP_BIT, 1);

  adxl.readXYZ(&x, &y, &z);
}

int isShake(){
  int current_X, current_Y, current_Z;
  adxl.readXYZ(&current_X, &current_Y, &current_Z);
  int result = abs(x - current_X) + abs(y - current_Y) + abs(z - current_Z);
  adxl.readXYZ(&x, &y, &z); 
  if(result > 100)
    return true;
  else
    return false;
}

void loop() {
  
  byte interrupts = adxl.getInterruptSource();
  
  if(isShake()){
    ledState = !ledState;
    digitalWrite(ledPin, ledState);

    toggleCount++;
    Serial.print("Toggle Count: ");
    Serial.println(toggleCount);
    delay(2000);
  }
}
