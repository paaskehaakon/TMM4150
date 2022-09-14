#include <Arduino.h>
#include <Servo.h>
Servo myServo;

int const trigPin = 6;
int const echoPin = 5;
long duration = 0;        // Variable for the duration of sound wave travel
float distance = 0;         // Variable for the distance measurement(pb var)
int angle = 89;         // Sets the angle of the servo motor to close
int distanceLevel_I = 100;
int distanceLevel_II = 60;
int distanceLevel_III = 20;

//Pins for paperbot
int const redLEDPin = 1;
int const yellowLEDPin = 2;
int const greenLEDPin = 3;
int const servoPin = 4;

int redValue = LOW;
int yellowValue = LOW;
int greenValue = LOW;

int const switchPin = 7;
boolean switchState = LOW;

int robotMode = 0;
int second = 0;

void launchModeTraffic(int yellowLEDPin){
  digitalWrite(yellowLEDPin, HIGH);
  delay(500);
  digitalWrite(yellowLEDPin, LOW);
  delay(500);
  digitalWrite(yellowLEDPin, HIGH);
  delay(500);
  digitalWrite(yellowLEDPin, LOW);
  delay(500);
  Serial.println("-----TRAFFIC MODE-----");
}

void launchModeRace(int redLEDPin){
  digitalWrite(redLEDPin, HIGH);
  delay(500);
  digitalWrite(redLEDPin, LOW);
  delay(500);
  digitalWrite(redLEDPin, HIGH);
  delay(500);
  digitalWrite(redLEDPin, LOW);
  delay(500);
  Serial.println("-----RACE MODE-----");
}


void setup() {
  pinMode(trigPin, OUTPUT);       // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT);      // Sets the echoPin as an INPUT
  myServo.attach(servoPin);
  myServo.write(0);             //road is opened
  Serial.begin(9600);

  pinMode(redLEDPin, OUTPUT);
  pinMode(yellowLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(switchPin, INPUT);
  digitalWrite(greenLEDPin, LOW);
  digitalWrite(yellowLEDPin, LOW);
  digitalWrite(redLEDPin, LOW);
}

void loop() {
  switchState = digitalRead(switchPin);
  Serial.println("State of the Switch : ");
  Serial.println(switchState);
  robotMode = checkForMode(switchState);      // Var from the state of the switch
  if(robotMode == 1){
    launchModeTraffic(yellowLEDPin);      // Showing which mode is 
    while (MeasureDistance()>distanceLevel_I){    // selected.
      digitalWrite(greenLEDPin, HIGH);      // When distance is over 100                  // cm, light stays green.
      //tone(tonePin,349);
      delay(100);
    }
    while (MeasureDistance()>distanceLevel_II){
      digitalWrite(greenLEDPin, LOW);         // When distance is over 60   
      digitalWrite(yellowLEDPin, HIGH);       // cm, light becomes yellow.
      //tone(tonePin,330);
      delay(100);
    }
    while (MeasureDistance()>distanceLevel_III){
      digitalWrite(yellowLEDPin, LOW);      // When distance is over 20
      digitalWrite(redLEDPin, HIGH);        // cm, light becomes red
      myServo.write(angle);           // and road is closed.
      //tone(tonePin,294);
      delay(100);
    }
    //tone(tonePin,262);
    delay(1000);            // Departure light process
    digitalWrite(yellowLEDPin, HIGH);
    delay(1000);
    digitalWrite(greenLEDPin, HIGH);
    digitalWrite(redLEDPin, LOW);
    digitalWrite(yellowLEDPin, LOW);
    myServo.write(0);           //Road is opened
    delay(3000);
    //noTone(tonePin);
    switchState = LOW;
    robotMode = 0;
  }

  if(robotMode == 2){
    launchModeRace(redLEDPin);
  }
  delay(50);
}

float MeasureDistance(){  
   digitalWrite(trigPin, LOW);      // Clears the trigPin condition
   delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);       // Sets the trigPin HIGH (ACTIVE) for 10 
   delayMicroseconds(10);     // microseconds
   digitalWrite(trigPin, LOW);
   duration = pulseIn(echoPin, HIGH);   // Reads the echoPin, returns the sound wave 
            // travel time in microseconds.
   distance = duration * 0.034 / 2;     // Calculating the distance : speed of sound  
            // wave divided by 2 (go and back).
   Serial.print("Distance: ");        // Displays the distance on the Serial Monitor
   Serial.print(distance);
   Serial.println(" cm");
}

int checkForMode(boolean state){
  Serial.println("-----CHECK-----");
  if (state == HIGH){
    Serial.println("mode 1");
    return 1;
  }
  else{
    Serial.println("mode 0");
    return 0;
  }
}