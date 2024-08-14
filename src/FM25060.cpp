#include "Arduino.h"
#include "FM25060.h"
#include <Wire.h>

float factor = 312500;

FM25060::FM25060(int inverterAddress, int maxSpeed, int maxMotorSpeed)
    : addr(inverterAddress), maxMotorSpeed(maxMotorSpeed), maxSpeed(maxSpeed)
{
    // Constructor initialization
}

void FM25060::begin()
{
    Wire.begin();
}

void FM25060::setSpeed(float speed)
{
    float calculatedFactor = factor / speed / 800 * maxMotorSpeed / 150 * maxSpeed;
    int delayValue = (int)calculatedFactor;

    // Sending the delayValue as two bytes
    Wire.beginTransmission(addr);
    Wire.write((byte)(delayValue >> 8)); // High byte
    Wire.write((byte)(delayValue & 0xFF)); // Low byte
    Wire.endTransmission(true);
}
