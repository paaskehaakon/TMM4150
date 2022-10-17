
#include <Arduino.h>
#pragma once
class Motor
{
public:
    // pins for motor
    int analog_left_pin;
    int analog_right_pin;
    int digital_left_pin;
    int digital_right_pin;

    // tunable parameters
    int speed;

    Motor();

    void drive();

    void turn_left();
    void turn_right();
    void turn(String dir, int deg);
};