#include "Arduino.h"
#pragma once

class Ultrasonic
{
public:
    int in;
    int out;
    int duration;
    int distance;

    // tunable parameters
    int max_distance;

    Ultrasonic();

    int read_distance();
};