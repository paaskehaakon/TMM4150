#include <Arduino.h>
#include "arm.cpp"
#include "ir.cpp"
#include "robot.cpp"

void lvl1(Robot rob)
{
  // tunable parameters
  int speed = 10;
  int distance = 10;

  rob.follow_line(speed);
  rob.motor.turn_right(speed);
  if (rob.ultrasonic.read_distance() > distance)
  {
    rob.motor.turn_left(speed);
    rob.motor.turn_left(speed);
    rob.follow_line(speed);
  }
  rob.drive_to_cup(speed);
  rob.arm.pickup();
  rob.motor.turn_right(speed);
  rob.motor.turn_right(speed);
  rob.follow_line(speed);
  rob.follow_line(speed);
  rob.motor.turn_right(speed);
  rob.follow_line(speed);
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