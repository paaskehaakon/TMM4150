#include <Arduino.h>
#include <Servo.h>
#include "motor.h"
#include "ir.h"
// GOOD

Ir::Ir()
{
  // pins for ir sensor
  this->sensor_1_pin = 1;
  this->sensor_2_pin = 2;
  this->sensor_3_pin = 3;

  pinMode(sensor_1_pin, INPUT);
  pinMode(sensor_2_pin, INPUT);
  pinMode(sensor_3_pin, INPUT);
};

int Ir::read_sensor(int pin)
{
  // reads if the ir sensor detects line
  int status_sensor = digitalRead(pin);
  if (status_sensor)
  {
    return 1;
  }
  else
  {
    return 0;
  }
};