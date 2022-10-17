#include <Arduino.h>
#include "motor.h"
#include "ir.h"

Motor::Motor()
{
    // pins for motor
    this->analog_left_pin = 1;
    this->analog_right_pin = 2;
    this->digital_left_pin = 3;
    this->digital_right_pin = 4;
    this->speed = 20;

    // attach motor
    pinMode(analog_left_pin, OUTPUT);
    pinMode(analog_right_pin, OUTPUT);
    pinMode(digital_left_pin, OUTPUT);
    pinMode(digital_right_pin, OUTPUT);
};

void Motor::drive()
{
    digitalWrite(digital_left_pin, HIGH);
    digitalWrite(digital_right_pin, HIGH);

    analogWrite(analog_left_pin, speed);
    analogWrite(analog_right_pin, speed);
};

void Motor::turn_left()
{
    digitalWrite(digital_left_pin, HIGH);
    digitalWrite(digital_right_pin, LOW);

    analogWrite(analog_left_pin, speed);
    analogWrite(analog_right_pin, speed);
}
void Motor::turn_right()
{
    digitalWrite(digital_left_pin, LOW);
    digitalWrite(digital_right_pin, HIGH);

    analogWrite(analog_left_pin, speed);
    analogWrite(analog_right_pin, speed);
}
void Motor::turn(String dir, int deg)
{
    if (dir == "left")
    {
        digitalWrite(digital_left_pin, LOW);
        digitalWrite(digital_right_pin, HIGH);

        analogWrite(analog_left_pin, speed);
        analogWrite(analog_right_pin, speed);
    }
    else
    {
        digitalWrite(digital_left_pin, HIGH);
        digitalWrite(digital_right_pin, LOW);

        analogWrite(analog_left_pin, speed);
        analogWrite(analog_right_pin, speed);
    }
    if (deg == 180)
    {
        delay(2000); // time it takes to spin 180 degrees
    }
    else
    {
        delay(1000);
    }
    analogWrite(analog_left_pin, 0);
    analogWrite(analog_right_pin, 0);
};