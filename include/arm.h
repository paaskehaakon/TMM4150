#include <Arduino.h>
#include <Servo.h>
#pragma once

class Arm
{
public:
    Servo myServo1; // lifting mechanism
    Servo myServo2; // claw closing mechanism
    float distance = 0;
    float cup_distance = 0;
    long duration = 0;
    int servoPin1 = 9;
    int servoPin2 = 11;
    int trigPin = 6;
    int echoPin = 5;
    int angleOpen1 = 0;
    int angleClose1 = 169;
    int angleOpen2 = 0;
    int angleClose2 = 170;
    int closing_distance = 15; // millimeters
    int flag = 0;

    Arm();

    void grab();
    void leave();

    float MeasureDistance();
};
