

class Ultrasonic
{
public:
    int pin;
    int duration;
    int distance;
    Ultrasonic(int pin)
    {
        this->pin = pin;
        pinMode(pin, INPUT);
    }

    int read_distance()
    {
        duration = pulseIn(pin, HIGH);   // Reads the echoPin, returns the sound wave travel time in microseconds.
        distance = duration * 0.034 / 2; // Calculating the distance : speed of sound wave divided by 2 (go and back).
        return distance;
    }
};