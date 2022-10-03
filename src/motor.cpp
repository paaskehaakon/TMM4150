#include <Arduino.h>
class Motor
{
public:
    // pins for motor
    int analog_left_pin;
    int analog_right_pin;
    int digital_left_pin;
    int digital_right_pin;

    // tunable parameters
    int speed;

    Motor(int pin1, int pin2, int pin3, int pin4, int speed)
    {
        // pins for motor
        this->analog_left_pin = pin1;
        this->analog_right_pin = pin2;
        this->digital_left_pin = pin3;
        this->digital_right_pin = pin4;
        this->speed = speed;

        // attach motor
        pinMode(analog_left_pin, OUTPUT);
        pinMode(analog_right_pin, OUTPUT);
        pinMode(digital_left_pin, OUTPUT);
        pinMode(digital_right_pin, OUTPUT);
    };

    void drive()
    {
        digitalWrite(digital_left_pin, HIGH);
        digitalWrite(digital_right_pin, HIGH);

        analogWrite(analog_left_pin, speed);
        analogWrite(analog_right_pin, speed);
    };

    void turn_left()
    {
        digitalWrite(digital_left_pin, HIGH);
        digitalWrite(digital_right_pin, LOW);

        analogWrite(analog_left_pin, speed);
        analogWrite(analog_right_pin, speed);
    }
    void turn_right()
    {
        digitalWrite(digital_left_pin, LOW);
        digitalWrite(digital_right_pin, HIGH);

        analogWrite(analog_left_pin, speed);
        analogWrite(analog_right_pin, speed);
    }
    void turn_around()
    {
        // TODO
    }
};