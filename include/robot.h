#include "motor.h"
#include "ir.h"
#include "arm.h"
#include "ultrasonic.h"

class Robot
{
public:
    // parts of the robot
    Ir ir;
    Arm arm;
    Motor motor;
    Ultrasonic ultrasonic;

    // constructor for robot
    Robot();

    void follow_line();

    void cup_challenge();
    void drive_to_search();
    void search();
};
