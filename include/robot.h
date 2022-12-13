#include "motor.h"
#include "ir.h"
#include "arm.h"
#include "ultrasonic.h"
#include "serv.h"
#pragma once

class Robot
{
public:
    // parts of the robot
    Ir ir;
    Arm arm;
    Motor motor;
    Ultrasonic ultrasonic;
    Servo servo1;
    Servo servo2;

    // constructor for robot
    Robot();

    void follow_line();
    void follow_servo();

    void cup_challenge();
    void drive_to_search();
    void search();
};
