#include "motor.cpp"
#include "ir.cpp"
#include "arm.cpp"
#include "ultrasonic.cpp"

class Robot
{
public:
    // parts of the robot
    Ir ir = Ir(1, 2, 3);
    Arm arm = Arm(1, 2);
    Motor motor = Motor(1, 2, 3, 4, 20);
    Ultrasonic ultrasonic = Ultrasonic(1, 30);

    bool following;
    Robot()
    {
        this->following = true;
    };

    void follow_line(bool search = false)
    {
        // makes use of turn and drive in a while loop to follow the line. stops on crossroads.
        while (following)
        {
            if (ir.read_sensor(1) && !ir.read_sensor(2) && ir.read_sensor(3))
            {
                motor.drive();
            }
            if (!ir.read_sensor(1))
            {
                motor.turn_left();
            }
            if (!ir.read_sensor(3))
            {
                motor.turn_right();
            }
            if (ir.read_sensor(1) && !ir.read_sensor(2) && ir.read_sensor(3))
            {
                break;
            }
            if (ultrasonic.read_distance() < 10)
            {
                break;
            }
        }
    }

    void find_cup()
    {
        motor.turn_right();
        if (ultrasonic.read_distance() < ultrasonic.distance)
        {
            follow_line(false);
        }
    }

    void drive_to_cup()
    {
        int distance = 1000;
        while (distance > 20)
        {
            follow_line(true);
        }
    }
    void place_cup()
    {
    }
};
