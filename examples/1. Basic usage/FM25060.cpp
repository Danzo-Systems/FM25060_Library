#include "Arduino.h"
 #include "FM25060.h"

float factor = 312500;
int maxMotorSpeed;
byte addr;
FM25060::FM25060(int inverterAddres, int maxSpeed, int maxMotorSpeed)
{
    FM25060:maxMotorSpeed = maxMotorSpeed;
    addr = inverterAddres;
}

void FM25060::begin()
{
}

void FM25060::setSpeed(float speed)
{
    float calculatedFactor = factor / speed / 800 * maxMotorSpeed;
    int delayValue = (int)calculatedFactor;
    Wire.beginTransmission(addr);
    Wire.write(delayValue, sizeof(delayValue));
    Wire.endTransmission(true);
}

