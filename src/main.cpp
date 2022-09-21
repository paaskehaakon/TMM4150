#include <Arduino.h>

class Arm {
  public:
    Arm() {
      // pins n shit
    }
    void pickup() {
      //picks up the cup
    }
    void putdown() {
      // puts down the cup
    }
};

class Ir {
  public:
    Ir() {
      // pins n shit
    }
};

class Motor {
  public:
    Motor() {
    //init motor
  }
};

class Robot {
  public:
    //public info
    Arm arm;
    Ir ir;
    Motor motor;
    Robot() {
      //initialize the Robot with Arm n shit.
    }
  private:
    //private info

};

void setup() {
  Robot rob;
  
};

void loop() {

};