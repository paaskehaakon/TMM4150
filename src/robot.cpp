#include "motor.h"
#include "ir.h"
#include "arm.h"
#include "ultrasonic.h"
#include "robot.h"

Robot::Robot()
{
    Serial.begin(9600);
    this->ir = Ir();
    this->arm = Arm();
    this->motor = Motor();
    this->ultrasonic = Ultrasonic();
};

void Robot::follow_line()
{
    // makes use of turn and drive in a while loop to follow the line. stops on crossroads.
    while (true)
    {
        if (ir.read_sensor(1) && !ir.read_sensor(2) && ir.read_sensor(3))
        {
            motor.drive();
        }
        if (!ir.read_sensor(1))
        {
            motor.turn_left();
        }
        if (!ir.read_sensor(3))
        {
            motor.turn_right();
        }
        if (ir.read_sensor(1) && !ir.read_sensor(2) && ir.read_sensor(3))
        {
            break;
        }
        if (ultrasonic.read_distance() < 10)
        {
            break;
        }
    }
};

void Robot::cup_challenge()
{
    // finds and picks the cup up
    int cup_position;
    motor.turn("right", 90);
    if (ultrasonic.read_distance() > ultrasonic.max_distance)
    {
        cup_position = 1;
        follow_line();
    }
    else
    {
        cup_position = 0;
        motor.turn("right", 180);
        follow_line();
    }
    arm.grab();

    // places the cup on the oposite side
    motor.turn("right", 180);
    follow_line();
    follow_line();
    arm.leave();

    // returns to track
    motor.turn("right", 180);
    follow_line();
    if (cup_position == 0)
    {
        motor.turn("left", 90);
    }
    else
    {
        motor.turn("right", 90);
    }
    follow_line();
}
void Robot::drive_to_search()
{
    motor.drive();
    delay(1000); // Delay to get to the middle of the course
}
void Robot::search()
{
}
