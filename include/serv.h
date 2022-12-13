#include <Arduino.h>
#include <Servo.h>
#pragma once

class Serv
{
public:
    int pin1;
    int pin2;
    Servo serv1;
    Servo serv2;

    Serv();
    void turn_left();
    void turn_right();
    void drive();
    void follow_line();
};