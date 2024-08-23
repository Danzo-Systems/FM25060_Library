#include <Wire.h>
#include <FM25060.h>

const int slaveAddress = 0x40;  // Change this to the address of your slave device
FM25060 motorController(slaveAddress, 150, 800); //Initalize motor controller object
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, 0);
  Wire.begin();        // Initialize I2C communication as master
  Serial.begin(9600);  // Initialize serial communication for debugging
  motorController.begin(); //initialize inverter
}

void loop() {
  // Define data packet to be sent

  if (Serial.available() > 2){
    String data = Serial.readStringUntil('\n');
    Serial.flush();
    uint32_t num = data.toInt();
    motorController.setSpeed(num); //set speed to 40km/h

    // Send data packet to slave device
    Serial.println("Beginning transmission...\n");
    Serial.println(String(num));
    Serial.println("Sending data...\n");
    Serial.println("Ending transmission...\n");
  }

}
