#include <Arduino.h>

class FM25060
{
public:
    FM25060(int _inverterAddress, int _maxSpeed, int _maxMotorSpeed); // Constructor
    void begin();  // Initialization method
    void setSpeed(float speed); // Method to set the motor speed

private:
    int maxMotorSpeed; // Maximum motor speed
    int maxSpeed; // Maximum speed
    int addr; // Inverter address
    byte packetData[4];
};
