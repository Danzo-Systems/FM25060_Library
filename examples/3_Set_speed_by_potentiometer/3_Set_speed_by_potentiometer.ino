#include <Wire.h>
#include <FM25060.h>

const int slaveAddress = 0x40;  // Change this to the address of your slave device
const int potentiometerPort = A0;

FM25060 motorController(slaveAddress, 150, 800); //Initalize motor controller object
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, 0);
  motorController.begin(); //initialize inverter
}

void loop() {
  // Define data packet to be sent
  int num = map(analogRead(potentiometerPort), 0, 1023, 0, 150);
  motorController.setSpeed(num); //set speed to 40km/h
  delay(200);
}
