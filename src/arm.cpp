#include <Arduino.h>
#include <Servo.h>

// NOT THE FINAL IMPLEMENTATION
// ANDREA WILL FIX LATER

class Arm
{
public:
  Servo myServo1; // lifting mechanism
  Servo myServo2; // claw closing mechanism
  float distance = 0;
  float cup_distance = 0;
  long duration = 0;
  int servoPin1 = 9;
  int servoPin2 = 11;
  int trigPin = 6;
  int echoPin = 5;
  int angleOpen1 = 0;
  int angleClose1 = 169;
  int angleOpen2 = 0;
  int angleClose2 = 170;
  int closing_distance = 15; // millimeters
  int flag = 0;

  Arm(int pin1, int pin2)
  {
    // constructor
    myServo1.attach(servoPin1);
    myServo1.write(angleOpen1);
    myServo2.attach(servoPin2);
    myServo2.write(angleOpen2);
  }

  void grab()
  {
    myServo2.write(angleClose2);
    delay(1500);
    myServo1.write(angleClose1);
    delay(2000);
  }

  void leave()
  {
    myServo1.write(angleOpen1);
    delay(1500);
    myServo2.write(angleOpen2);
    delay(2000);
  }

  float MeasureDistance()
  {
    digitalWrite(trigPin, LOW);  // Clears the trigPin condition
    delayMicroseconds(2);        // microseconds
    digitalWrite(trigPin, HIGH); // Sets the trigPin HIGH (ACTIVE) for 10
    delayMicroseconds(10);       // microseconds
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave
                                       // travel time in microseconds.
    distance = duration * 0.343 / 2;   // Calculating the distance : speed of sound
                                       // wave divided by 2 (go and back).
    Serial.print("Distance: ");        // Displays the distance on the Serial Monitor
    Serial.print(distance);
    Serial.println(" mm");
    return distance;
  }

  void loop()
  {
    // put your main code here, to run repeatedly:
    cup_distance = MeasureDistance(); // in mm
    if (cup_distance < closing_distance && flag == 0)
    {
      grab();
      flag = 1;
    }
    if (flag == 1)
    { // flag is only for the trials
      delay(1500);
      leave();
      flag = 0;
    }
  }
};