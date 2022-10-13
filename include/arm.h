#include <Arduino.h>
#include <Servo.h>
#pragma once

class Arm
{
public:
    Servo myServo1; // lifting mechanism
    Servo myServo2; // claw closing mechanism
    float distance;
    float cup_distance;
    long duration;
    int servoPin1;
    int servoPin2;
    int trigPin;
    int echoPin;
    int angleOpen1;
    int angleClose1;
    int angleOpen2;
    int angleClose2;
    int closing_distance; // millimeters
    int flag;

    Arm(int pin1, int pin2);

    void grab();
    void leave();

    float MeasureDistance();
};
