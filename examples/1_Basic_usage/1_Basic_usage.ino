#include "FM25060.h"
#include <Wire.h>


int i2cAdress = 15; //set adress of the motor controller 
int maxSpeed = 150; //maximal speed that can be shown on Hasler
int maxMotorSpeed = 1000; //Rotational speed of the motor that translates to maximal speed on Hasler

FM25060 motorController(i2cAdress, maxSpeed, maxMotorSpeed); //Initalize motor controller object

void setup() {
  
  motorController.begin(); //initialize inverter
  motorController.setSpeed(0); //set speed to 0km/h

}

void loop() {
  motorController.setSpeed(40); //set speed to 40km/h
  delay(5000);
  motorController.setSpeed(80); //set speed to 80km/h
  delay(5000);

}
