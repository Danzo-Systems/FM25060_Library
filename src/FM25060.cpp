// FM25060.cpp
#include <Arduino.h>
#include "FM25060.h"
#include <Wire.h>

float factor = 312500;
byte packetData[4] = { 0x0 };


FM25060::FM25060(int _inverterAddress, int _maxSpeed, int _maxMotorSpeed)
{
  maxMotorSpeed = _maxMotorSpeed;
  maxSpeed = _maxSpeed;
  addr = _inverterAddress;
}

void FM25060::begin()
{
    Wire.begin();
}

void FM25060::setSpeed(float speed)
{
    float calculatedFactor = factor /( speed / 800 * maxMotorSpeed / 150 * maxSpeed);
    uint32_t delayValue = (int)calculatedFactor;
    packetData[3] = (delayValue >> 24) & 0xFF;
    packetData[2] = (delayValue >> 16) & 0xFF;
    packetData[1] = (delayValue >> 8) & 0xFF;
    packetData[0] = delayValue & 0xFF;
    // Sending the delayValue as two bytes
    Wire.beginTransmission(addr);
    Wire.write(packetData, sizeof(packetData));
    Wire.endTransmission(true);
}
