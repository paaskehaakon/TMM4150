

class Ultrasonic
{
public:
    int in;
    int out;
    int duration;
    int distance;

    // tunable parameters
    int max_distance = 0;

    Ultrasonic(int in, int out)
    {
        this->in = in;
        this->out = out;
        pinMode(in, INPUT);
        pinMode(out, OUTPUT);
    }

    int read_distance()
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
};