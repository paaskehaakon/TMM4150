#include <Arduino.h>
#include <Servo.h>
#pragma once

class Arm
{
public:
    Servo grabberServo;
    Servo lifterServo;
    int grabberPin;
    int lifterPin;
    int Close;
    int Open;
    int High;
    int Low;

    Arm();

    void grab();
    void leave();

    float MeasureDistance();
};
