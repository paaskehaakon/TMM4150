#include <Arduino.h>
#include "arm.h"
#include <Servo.h>

Servo grabberServo;
Servo lifterServo;
// actually there are two servos for lifting wired on the same control pin, so
// I just need to declare one
int grabberPin = 11;
int lifterPin = 9;
int Close = 40;
int Open = 10;
int High = 0;
int Low = 130;
// these are the angles for servos rotation, related to actions

Arm::Arm()
{
  this->grabberServo = grabberServo;
  this->lifterServo = lifterServo;
  this->grabberPin = 11;
  this->lifterPin = 9;
  this->Close = 40;
  this->Open = 10;
  this->High = 0;
  this->Low = 130;

  grabberServo.attach(grabberPin);
  lifterServo.attach(lifterPin);
  grabberServo.write(Close);
  lifterServo.write(Low);
}

void Arm::grab()
{
  grabberServo.write(Open);
  // (INSERT DRIVE FUNCTION: now the robot should drive forward to embrace the cup)
  grabberServo.write(Close);
  delay(1000);
  lifterServo.write(High);
}

void Arm::leave()
{
  lifterServo.write(Low);
  delay(1000);
  grabberServo.write(Open);
  // (INSERT DRIVE FUNCTION: now the robot should drive backwards so afterwards it
  // can close the clamp without the cup in between)
  grabberServo.write(Close);
}