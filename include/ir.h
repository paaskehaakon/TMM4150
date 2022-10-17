#include <Arduino.h>
#pragma once
class Ir
{
public:
    // pins for ir sensor
    int sensor_1_pin;
    int sensor_2_pin;
    int sensor_3_pin;

    Ir();
    int read_sensor(int pin);
};