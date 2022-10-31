#include <Arduino.h>
#include "motor.h"
#include "ir.h"

Motor::Motor()
{
    // pins for motor A
    this->digital_left_pin = 12;
    this->break_left_pin = 9;
    this->analog_left_pin = 3;

    // pins for motor B
    this->digital_right_pin = 13;
    this->break_right_pin = 8;
    this->analog_right_pin = 11;

    this->speed = 20;

    // attach motor B
    pinMode(digital_left_pin, OUTPUT);
    pinMode(break_left_pin, OUTPUT);
    // attach motor B
    pinMode(digital_right_pin, OUTPUT);
    pinMode(break_right_pin, OUTPUT);
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

void Motor::test()
{

    // Motor A forward @ full speed
    digitalWrite(digital_left_pin, HIGH); // Establishes backward direction of Channel A
    digitalWrite(break_left_pin, LOW);    // Disengage the Brake for Channel A
    analogWrite(analog_left_pin, 255);    // Spins the motor on Channel A at half speed

    // Motor B forward @ full speed
    digitalWrite(digital_right_pin, HIGH); // Establishes forward direction of Channel B
    digitalWrite(break_right_pin, LOW);    // Disengage the Brake for Channel B
    analogWrite(analog_right_pin, 255);    // Spins the motor on Channel B at full speed
}