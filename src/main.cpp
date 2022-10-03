#include <Arduino.h>
#include "arm.cpp"
#include "ir.cpp"
#include "robot.cpp"

void lvl1(Robot rob)
{

  rob.follow_line();                                            // follows line until crossroads
  rob.motor.turn_right();                                       // turns one way to look for the cup
  if (rob.ultrasonic.read_distance() > rob.ultrasonic.distance) // if the cup is not there. turn the other way.
  {
    rob.motor.turn_left(); // dont think this will work. need a way for the robot to turn 180 deg around.
    rob.motor.turn_left();
    rob.follow_line();
  }
  rob.drive_to_cup();
  rob.motor.turn_right();
  rob.motor.turn_right();
  rob.follow_line();
  rob.follow_line();
  rob.motor.turn_right();
  rob.follow_line();
};
void lvl2()
{
}
void lvl3()
{
}
void lvl4()
{
}

void setup()
{
  Robot rob;
  lvl1(rob);
  lvl2();
  lvl3();
  lvl4();
};
void loop(){};