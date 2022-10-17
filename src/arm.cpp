#include <Arduino.h>
#include "arm.h"
#include <Servo.h>

// NOT THE FINAL IMPLEMENTATION
// ANDREA WILL FIX LATER

Arm::Arm()
{
  // constructor
  /* myServo1.attach(servoPin1);
  myServo1.write(angleOpen1);
  myServo2.attach(servoPin2);
  myServo2.write(angleOpen2); */
}

void Arm::grab()
{
  /* myServo2.write(angleClose2);
  delay(1500);
  myServo1.write(angleClose1);
  delay(2000); */
}

void Arm::leave()
{
  /* myServo1.write(angleOpen1);
  delay(1500);
  myServo2.write(angleOpen2);
  delay(2000); */
}

/* float Arm::MeasureDistance()
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
} */

/* void loop()
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
} */
