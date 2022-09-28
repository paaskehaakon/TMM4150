#include <Arduino.h>
#include <Servo.h>

class Arm
{
public:
  int arm1;
  int arm2;
  Servo servo1;
  Servo servo2;

  Arm(int pin1, int pin2)
  {
    this->arm1 = pin1;
    this->arm2 = pin2;
    servo1.attach(arm1);
    servo2.attach(arm2);
  }
  void pickup()
  {
    // picks up the cup
  }
  void putdown()
  {
    // puts down the cup
  }
};