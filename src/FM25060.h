#ifndef FM25060_H
#define FM25060_H

#include "Arduino.h"

class FM25060
{
public:
    FM25060(int inverterAddress, int maxSpeed, int maxMotorSpeed); // Constructor
    void begin();  // Initialization method
    void setSpeed(float speed); // Method to set the motor speed

private:
    int maxMotorSpeed; // Maximum motor speed
	int maxSpeed; // Maximum speed
    byte addr; // Inverter address
};

#endif
