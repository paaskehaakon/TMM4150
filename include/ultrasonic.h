#include "Arduino.h"

class Ultrasonic
{
public:
    int in;
    int out;
    int duration;
    int distance;

    // tunable parameters
    int max_distance;

    Ultrasonic(int in, int out);

    int read_distance();
};