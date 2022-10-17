#include <Arduino.h>
#include "arm.h"
#include "ir.h"
#include "robot.h"
#include "motor.h"
#include "ultrasonic.h"

void lvl1(Robot rob)
{

  rob.follow_line();   // follows the line until crossroads
  rob.cup_challenge(); // finds the cup, picks it up, returns to the other side, and returns to track
};

void lvl2(Robot rob)
{
  rob.follow_line();
}

void lvl3(Robot rob)
{
  rob.motor.turn("left", 90);
  rob.follow_line();
  rob.motor.drive(); // first obstacle
  delay(500);        // power through to get over the bump
  rob.follow_line();
  rob.motor.drive(); // second obstacle
  delay(500);        // power through to get over the bump
  rob.follow_line(); // get over the sand pit. DONT KNOW IF THIS WORKS
}

void lvl4(Robot rob)
{
  rob.motor.turn("left", 90);
  rob.follow_line();
  rob.follow_line();
  rob.follow_line();
}

void setup()
{
  Robot rob;
  lvl1(rob);
  lvl2(rob);
  lvl3(rob);
  lvl4(rob);

  // victory spin
  while (true)
  {
    rob.motor.turn_left();
  }
};
void loop()
{
  delay(1000);
};