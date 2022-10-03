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

    // constructor for robot
    Robot()
    {
        Serial.begin(9600);
    };

    void follow_line()
    {
        // makes use of turn and drive in a while loop to follow the line. stops on crossroads.
        while (true)
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

    void cup_challenge()
    {
        // finds and picks the cup up
        int cup_position;
        motor.turn_right();
        if (ultrasonic.read_distance() > ultrasonic.max_distance)
        {
            cup_position = 1;
            follow_line();
        }
        else
        {
            cup_position = 0;
            motor.turn_around();
            follow_line();
        }
        arm.grab();

        // places the cup on the oposite side
        motor.turn_around();
        follow_line();
        follow_line();
        arm.leave();

        // returns to track
        motor.turn_around();
        follow_line();
        if (cup_position == 0)
        {
            motor.turn_left();
        }
        else
        {
            motor.turn_right();
        }
        follow_line();
    }

    void place_cup()
    {
    }
};
