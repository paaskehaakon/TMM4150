#include <Servo.h>
#include "motor.cpp"

class Ir
{
public:
  // pins for ir sensor
  int sensor_1_pin;
  int sensor_2_pin;
  int sensor_3_pin;

  Ir(int pin1, int pin2, int pin3)
  {
    // pins for ir sensor
    this->sensor_1_pin = pin1;
    this->sensor_2_pin = pin2;
    this->sensor_3_pin = pin3;

    pinMode(sensor_1_pin, INPUT);
    pinMode(sensor_2_pin, INPUT);
    pinMode(sensor_3_pin, INPUT);
  }

  int read_sensor(int pin)
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
  }
};