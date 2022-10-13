
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

    Motor(int pin1, int pin2, int pin3, int pin4, int speed){};

    void drive();

    void turn_left();
    void turn_right();
    void turn(String dir, int deg);
};