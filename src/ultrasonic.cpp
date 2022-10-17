#include "Arduino.h"
#include "ultrasonic.h"

Ultrasonic::Ultrasonic()
{
    this->in = 1;
    this->out = 2;
    pinMode(in, INPUT);
    pinMode(out, OUTPUT);
};

int Ultrasonic::read_distance()
{
    // for clearing trigpin condition
    digitalWrite(out, LOW);
    delayMicroseconds(2);
    digitalWrite(out, HIGH);
    delayMicroseconds(10);
    digitalWrite(out, LOW);

    // calculation the distance
    duration = pulseIn(in, HIGH);
    distance = duration * 0.034 / 2;
    delay(100);
    return distance;
};
