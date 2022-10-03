#include <Arduino.h>
#include "arm.cpp"
#include "ir.cpp"
#include "robot.cpp"

void lvl1(Robot rob)
{

  rob.follow_line();   // follows the line until crossroads
  rob.cup_challenge(); // finds the cup, picks it up, returns to the other side, and returns to track
};

void lvl2(Robot rob)
{
  rob.follow_line();
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
  lvl2(rob);
  lvl3();
  lvl4();

  // victory spin
  while (true)
  {
    rob.motor.turn_left();
  }
};
void loop(){

};