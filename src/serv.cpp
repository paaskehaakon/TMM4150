#include "serv.h"
#include <Arduino.h>

Serv::Serv()
{
    this->pin1 = 5;
    this->pin2 = 6;

    serv1.attach(pin1);
    serv2.attach(pin2);
}

void Serv::drive()
{
    serv1.write(45);  // rotate the motor counterclockwise
    serv2.write(135); // rotate the motor counterclockwise
}

void Serv::turn_left()
{
    serv1.write(45); // rotate the motor counterclockwise
    serv2.write(90); // rotate the motor counterclockwise
}

void Serv::turn_right()
{
    serv1.write(90); // rotate the motor counterclockwise
    serv2.write(45); // rotate the motor counterclockwise
}
