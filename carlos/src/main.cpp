
#include <Servo.h>
#include <Arduino.h>
/* 
int flag = 0;
int k = 0;
int b = 0;
int c = 0;
int count = 0;
// Ir---------------------------------------------------------------------------------------
int ir_left = 8; // left
int ir_right = 7; // right
int ir_center = 12;
int ir_drive = 13;
float cuppp = 3.5;

int read_sensor(int pin)
{
  int status_sensor = digitalRead(pin);
  if (status_sensor)
  {
	return 1;
  }
  else
  {
	return 0;
  }
}

void debug_ir() {
  printf("left ir %6d!", read_sensor(ir_left));
  printf("right ir %6d!", read_sensor(ir_right));
  printf("center ir %6d!", read_sensor(ir_center));
  printf("drive ir %6d!", read_sensor(ir_drive));
}
// Ultrasonic---------------------------------------------------------------------------------------
int echo = 2; // echo
int trig = 4;
float read_distance()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // calculation the distance
  long duration = pulseIn(echo, HIGH);
  float distance = duration * 0.0343 / 2;
  delay(100);
  return distance;
}

// Motor---------------------------------------------------------------------------------------
int servo_L = 9;
int servo_R = 6;
Servo servo_left; // left
Servo servo_right; // right

void stop()
{
  //Serial.println("motors stopped");
  servo_left.write(90);
  servo_right.write(90);
}
void recovery() {
    servo_left.write(85);
    servo_right.write(100);
}

void go_forward() //
{
  Serial.println("going forward");
  servo_left.write(95);
  servo_right.write(80);
}
void go_backwards()
{
  Serial.println("going backwards");
  servo_left.write(83);
  servo_right.write(100);
}

void turn_right_90_timed()
{
  Serial.println("start turning right");
  servo_left.write(95);
  servo_right.write(106);
  delay(820); // calculated time for 100 speed
  stop();
  flag = 2;
  Serial.println("stop turning right");
}
void turn_right_90_line()
{
  Serial.println("start turning right");
  servo_left.write(100);
  servo_right.write(110);
  delay(500); // calculated time for 100 speed
  stop();
  while (true){
	servo_left.write(100);
	servo_right.write(110);
	if(digitalRead(ir_drive)==HIGH){
  	stop();
  	break;
	}
	{
  	stop();
  	delay(500);
	}
  }
  flag = 2;
  Serial.println("stop turning right");
}
void turn_left_90_timed()
{
  Serial.println("start turning left");
  servo_left.write(80);
  servo_right.write(65);
  delay(680); // calculated time for 80 speed
  stop();
  Serial.println("stop turning left");
}
void turn_left_90_line()
{
  Serial.println("start turning right");
  servo_left.write(80);
  servo_right.write(62);
  delay(500); // calculated time for 100 speed
  stop();
  while (true){
	servo_left.write(80);
	servo_right.write(62);
	if(digitalRead(ir_drive)==HIGH){
  	stop();
  	break;
	}
  }
  flag = 2;
  Serial.println("stop turning right");
}
void turn_180_timed(){
  Serial.println("start turning 180deg");
  servo_left.write(70);
  servo_right.write(60);
  delay(800); // calculated time for 80 speed
  stop();
  Serial.println("stop turning 180deg");
}
void turn_180_line()
{
  Serial.println("start turning 180");
  servo_left.write(96);
  servo_right.write(111);
  delay(600); // calculated time for 100 speed
  stop();
  while (true){
	servo_left.write(96);
	servo_right.write(111);
	if(digitalRead(ir_drive)==HIGH){
  	stop();
  	break;
	}
  }
  flag = 2;
  Serial.println("stop turning 180");
}
void follow_line_back() // copypaste of a, with inverted movement
{
  Serial.println("start follow line");
  while (true)
  {
	if (digitalRead(ir_left)==LOW && digitalRead(ir_center)==HIGH && digitalRead(ir_right)==LOW) // only center
	{
  	go_backwards();
  	Serial.println("only center ON");
  	k = 0;
	}
	if (digitalRead(ir_left)==HIGH && digitalRead(ir_center)==HIGH && digitalRead(ir_right)==LOW) // center and left
	{  
  	servo_left.write(90);
  	servo_right.write(98);  // a bit towards left
  	Serial.println("center and left ON");
  	k = 0;
 	 
	}
	if (digitalRead(ir_left)==HIGH && digitalRead(ir_center)==LOW && digitalRead(ir_right)==LOW) // left
	{
  	servo_left.write(90);
  	servo_right.write(100);  // towards left
  	Serial.println("only left ON");
  	k = 0;
  	if (digitalRead(ir_left)==HIGH && digitalRead(ir_center)==HIGH && digitalRead(ir_right)==HIGH)
  	{
    	while (true){
      	servo_left.write(80);
      	servo_right.write(62);
      	if(digitalRead(ir_left)==LOW && digitalRead(ir_center)==HIGH && digitalRead(ir_right)==LOW && digitalRead(ir_drive)==HIGH){
        	stop();
        	break;
      	}
    	}
  	}
	}
	if (digitalRead(ir_left)==LOW && digitalRead(ir_center)==HIGH && digitalRead(ir_right)==HIGH) // center and right
	{
  	servo_left.write(80); // a bit towards right
  	servo_right.write(90);
  	Serial.println("center and right ON");
  	k = 0;
	}
	if (digitalRead(ir_left)==LOW && digitalRead(ir_center)==LOW && digitalRead(ir_right)==HIGH) // right
	{
  	servo_left.write(78); // towards right
  	servo_right.write(90);
  	Serial.println("only right ON");
  	k = 0;
  	if (digitalRead(ir_left)==HIGH && digitalRead(ir_center)==HIGH && digitalRead(ir_right)==HIGH)
  	{
    	while (true){
      	servo_left.write(100);
      	servo_right.write(110);
      	if(digitalRead(ir_left)==LOW && digitalRead(ir_center)==HIGH && digitalRead(ir_right)==LOW && digitalRead(ir_drive)==HIGH){
      	stop();
      	break;
      	}
    	}
  	}
	}
	if (digitalRead(ir_left)==HIGH && digitalRead(ir_center)==HIGH && digitalRead(ir_right)==HIGH)
	{
  	Serial.println("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
  	stop();
  	Serial.println("stop follow line: cross detected");
 	 
  	k = k + 1;
	}
	if (digitalRead(ir_left)==LOW && digitalRead(ir_center)==LOW && digitalRead(ir_right)==LOW)
	{
  	Serial.println("all three OFF");
  	stop();
  	k=0;
	}
	if (k==10)
	{
  	//k=0;
  	break;
	}
    
    
	if (read_distance() < 10)
	{
  	stop();
  	break;
  }
}

void follow_line() // first level starting line, stops on crosses
{
  Serial.println("start follow line");
  while (true)
  {
	if (digitalRead(ir_left)==LOW && digitalRead(ir_center)==HIGH && digitalRead(ir_right)==LOW) // only center
	{
  	go_forward();
  	Serial.println("only center ON");
  	k = 0;
	}
	if (digitalRead(ir_left)==HIGH && digitalRead(ir_center)==HIGH && digitalRead(ir_right)==LOW) // center and left
	{  
  	servo_left.write(92); //90
  	servo_right.write(80);  // a bit towards left
  	Serial.println("center and left ON");
  	k = 0;
	}
	if (digitalRead(ir_left)==HIGH && digitalRead(ir_center)==LOW && digitalRead(ir_right)==LOW) // left
	{
  	servo_left.write(91); //90
  	servo_right.write(75);  // towards left
  	Serial.println("only left ON");
  	k = 0;
	}
	if (digitalRead(ir_left)==LOW && digitalRead(ir_center)==HIGH && digitalRead(ir_right)==HIGH) // center and right
	{
  	servo_left.write(100); // a bit towards right
  	servo_right.write(88); //90
  	Serial.println("center and right ON");
  	k = 0;
	}
	if (digitalRead(ir_left)==LOW && digitalRead(ir_center)==LOW && digitalRead(ir_right)==HIGH) // right
	{
  	servo_left.write(100); // towards right
  	servo_right.write(87); //90
  	Serial.println("only right ON");
  	k = 0;
	}
	if (digitalRead(ir_left)==HIGH && digitalRead(ir_center)==HIGH && digitalRead(ir_right)==HIGH)
	{
  	stop();
    break;
	}
  if (read_distance()<cuppp)
	{
  	Serial.println("---------------cup found--------------------");
  	stop();
  	b = 1;
  	break; 	 
	}
  if (digitalRead(ir_left)==LOW && digitalRead(ir_center)==LOW && digitalRead(ir_right)==LOW) {
    recovery();
  }
  }
}

// Arm---------------------------------------------------------------------------------------
Servo grabberServo;
Servo lifterServo;

int grabberPin = 5;
int lifterPin = 3;
int Close = 39;
int Open = 15;
int High = 0;
int Low = 110;

void grab()
{
  Serial.println("------- Searching for cup --------");
  grabberServo.write(Close);
  delay(1000);
  lifterServo.write(High);
}

void leave()
{
  Serial.println("--------leaving the cup-------");
  lifterServo.write(Low);
  delay(1000);
  grabberServo.write(Open);
  follow_line_back();
  grabberServo.write(Close);
}



// Levels---------------------------------------------------------------------------------------
void lvl1()
{
  int cup_position = 0; // Cup position
  // Make the robot face the cup
  follow_line();
  delay(1000);
  turn_right_90_line();
  delay(1000);  
  if (read_distance() > 20)
  {
	turn_180_timed();
	cup_position = 1; 	 
  }
  // Grab the cup and drive to the cross
  grabberServo.write(Open);
  follow_line();
  delay(1000);
  grab();
  delay(1000);
  turn_180_line(); 
  follow_line();
  delay(500);

  // Now at the cross again with the cup 

  go_forward();
  delay(500);
  stop();
  follow_line(); 

  // Placing the cup
  leave(); // this includes going backwards to the cross and close clamp
  if (cup_position == 1)
  {
	turn_left_90_line();
  }
  else
  {
	turn_right_90_line(); // both were D
  }
  //go_forward();
  //delay(300); // time to leave cross (then level 2 can start)
  stop();
  flag=3;  
}
void lvl2()
{
  follow_line(); // pay attention to the sharp turn (function follow_line ad hoc with turn left if steady on sharp curve)
}
void lvl3()
{
  follow_line(); // bigger wheels like other italians (+rubbers) or kevin's feet (weird)---> rear wheel's height already solved
}

void tick() {
  servo_left.write(105); 
  servo_right.write(88);
  delay(200);
  stop();
  delay(200);
  
}
void limp() {
  servo_left.write(92); 
  servo_right.write(84);
}
void lvl4()
{
  int scan = 0;
  // get to the start of the box
  follow_line();
  follow_line();
  follow_line();

  // scan for the cup
  while(read_distance() > 50) {
    tick();
    scan += 1;
  }
  // limp to the cup
  while (read_distance() > 3.5) {
    limp();
  }
  //pick it up and move back to the line
  grabberServo.write(Open);
  grab();
  turn_180_timed(); // time the turning of th robot. create a separate function. 
  while(digitalRead(ir_left)==LOW && digitalRead(ir_center)==LOW && digitalRead(ir_right)==LOW) {
    limp();
  }
  //check if it is on the right or left side of the cross. go to starting position. 
  if (scan > 100) {
    turn_left_90_line();
    follow_line();
    turn_right_90_line();

  }
  else {
    turn_left_90_line();
    follow_line();
    turn_right_90_line();
  }
  follow_line();
  turn_left_90_line();
  
}

void setup()
{

  Serial.begin(9600);
  // ir
  pinMode(ir_left, INPUT);
  pinMode(ir_right, INPUT);
  pinMode(ir_center, INPUT);
  pinMode(ir_drive, INPUT);


  // Ultrasonic
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);

  // Servo
  servo_left.attach(servo_L);
  servo_right.attach(servo_R);

  // Arm
  grabberServo.attach(grabberPin);
  lifterServo.attach(lifterPin);
  grabberServo.write(Close);
  lifterServo.write(Low);
}

void loop() //testing
{
  follow_line();
}
 */

int flag = 0;
int k = 0;
int b = 0;
int c = 0;
int count = 0;
// Ir---------------------------------------------------------------------------------------
int ir_left = 8; // left
int ir_right = 7; // right
int ir_center = 12;
int ir_drive = 13;
float cuppp = 3.5;

int read_sensor(int pin)
{
  int status_sensor = digitalRead(pin);
  if (status_sensor)
  {
	return 1;
  }
  else
  {
	return 0;
  }
}
// Ultrasonic---------------------------------------------------------------------------------------
int echo = 2; // echo
int trig = 4;
float read_distance()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // calculation the distance
  long duration = pulseIn(echo, HIGH);
  float distance = duration * 0.0343 / 2;
  delay(100);
  return distance;
}

// Motor---------------------------------------------------------------------------------------
int servo_L = 9;
int servo_R = 6;
Servo servo_left; // left
Servo servo_right; // right

void stop()
{
  //Serial.println("motors stopped");
  servo_left.write(90);
  servo_right.write(90);
}

void go_forward() //
{
  Serial.println("going forward");
  servo_left.write(106);
  servo_right.write(59);
}
void go_forward_fast() //
{
  servo_left.write(94);
  servo_right.write(80);
}
void go_forward_slow() //
{
  Serial.println("going forward");
  servo_left.write(100);
  servo_right.write(80);
}
void go_backwards()
{
  Serial.println("going backwards");
  servo_left.write(85);
  servo_right.write(95);
}
void go_backwards_fast()
{
  Serial.println("going backwards");
  servo_left.write(84);
  servo_right.write(100);
}
void go_back_left()
{
  while((digitalRead(ir_left)==HIGH) | (digitalRead(ir_center)==HIGH) | (digitalRead(ir_right)==HIGH))
  {
	servo_left.write(90); // less than 90 , less powerful
	servo_right.write(105);// more, more
  }
  stop();
  while(digitalRead(ir_center)==LOW)
  {
	go_backwards();
  }
  stop();
  while((digitalRead(ir_center)==LOW) | (digitalRead(ir_drive)==LOW))
  {
	servo_left.write(97);
	servo_right.write(100);
  }
  stop();
  //follow_line_a();
}

void follow_line_a() // first level starting line, stops on crosses
{
  Serial.println("start follow line");
  while (true)
  {
	if (digitalRead(ir_left)==LOW && digitalRead(ir_center)==HIGH && digitalRead(ir_right)==LOW) // only center
	{
  	go_forward_slow();
  	Serial.println("only center ON");
  	k = 0;
	}
	if (digitalRead(ir_left)==HIGH && digitalRead(ir_center)==HIGH && digitalRead(ir_right)==LOW) // center and left
	{  
  	servo_left.write(86); //90
  	servo_right.write(72);  // a bit towards left
	}
	if (digitalRead(ir_left)==HIGH && digitalRead(ir_center)==LOW && digitalRead(ir_right)==LOW) // left
	{
  	servo_left.write(86); //90
  	servo_right.write(70);  // towards left
  	Serial.println("only left ON");
  	k = 0;
	}
	if (digitalRead(ir_left)==LOW && digitalRead(ir_center)==HIGH && digitalRead(ir_right)==HIGH) // center and right
	{
  	servo_left.write(100); // a bit towards right
  	servo_right.write(90); //90
  	Serial.println("center and right ON");
  	k = 0;
	}
	if (digitalRead(ir_left)==LOW && digitalRead(ir_center)==LOW && digitalRead(ir_right)==HIGH) // right
	{
  	servo_left.write(100); // towards right
  	servo_right.write(90); //90
  	Serial.println("only right ON");
  	k = 0;
	}
	if (digitalRead(ir_left)==HIGH && digitalRead(ir_center)==HIGH && digitalRead(ir_right)==HIGH)
	{
  	Serial.println("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
  	stop();
  	Serial.println("stop follow line: cross detected");
  	flag = 1;
  	k = k + 1;
	}
	if (digitalRead(ir_left)==LOW && digitalRead(ir_center)==LOW && digitalRead(ir_right)==LOW)
	{
  	Serial.println("all three OFF");
	go_forward_slow();
  	k=0;
	}
	if (k==10)
	{ 	 
  	k=0;
  	break;
	}
    
    
	/*if (read_distance() < 10)
	{
  	stop();
  	break;
	}*/
  }
}

void follow_line_2() // first level starting line, stops on crosses
{
  Serial.println("start follow line");
  while (true)
  {
	if (digitalRead(ir_left)==LOW && digitalRead(ir_center)==HIGH && digitalRead(ir_right)==LOW) // only center
	{
	servo_left.write(110);
	servo_right.write(70);
  	Serial.println("only center ON");
	}
	if (digitalRead(ir_left)==HIGH && digitalRead(ir_center)==HIGH && digitalRead(ir_right)==LOW) // center and left
	{  
  	servo_left.write(86); //90
  	servo_right.write(70);  // a bit towards left
  	Serial.println("center and left ON");
	}
	if (digitalRead(ir_left)==HIGH && digitalRead(ir_center)==LOW && digitalRead(ir_right)==LOW) // left
	{
  	servo_left.write(86); //90
  	servo_right.write(65);  // towards left
  	Serial.println("only left ON");
	}
	if (digitalRead(ir_left)==LOW && digitalRead(ir_right)==HIGH) // center and right
	{
  	servo_left.write(110); // a bit towards right
  	servo_right.write(80); //90
  	Serial.println("center and right ON");
	}
	if (digitalRead(ir_left)==LOW && digitalRead(ir_center)==LOW && digitalRead(ir_right)==HIGH) // right
	{
  	servo_left.write(100); // towards right
  	servo_right.write(85); //90
  	Serial.println("only right ON");
	}
	if (digitalRead(ir_left)==HIGH && digitalRead(ir_center)==HIGH && digitalRead(ir_right)==HIGH)
	{
  	Serial.println("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
  	stop();
  	Serial.println("stop follow line: cross detected");
	}
	if (digitalRead(ir_left)==LOW && digitalRead(ir_center)==LOW && digitalRead(ir_right)==LOW)
	{
  	Serial.println("all three OFF");
	go_forward_slow();
	}
  }
}

void go_back_right()
{
  while((digitalRead(ir_left)==HIGH) | (digitalRead(ir_center)==HIGH) | (digitalRead(ir_right)==HIGH))
  {
	servo_left.write(70); // less than 90, more power
	servo_right.write(95); // more, less
  }
  stop();
  while(digitalRead(ir_center)==LOW)
  {
	go_backwards();
  }
  stop();
  follow_line_a();
}
void turn_right_90()
{
  Serial.println("start turning right");
  servo_left.write(95);
  servo_right.write(106);
  delay(420); // calculated time for 100 speed
  stop();
  flag = 2;
  Serial.println("stop turning right");
}
void turn_right_90D()
{
  Serial.println("start turning right");
  servo_left.write(100);
  servo_right.write(110);
  delay(500); // calculated time for 100 speed
  stop();
  while (true){
	servo_left.write(100);
	servo_right.write(110);
	if(digitalRead(ir_drive)==HIGH){
  	stop();
  	break;
	}
   /* else
	{
  	stop();
  	delay(500);
	}*/
  }
  flag = 2;
  Serial.println("stop turning right");
}
void turn_left_90()
{
  Serial.println("start turning left");
  servo_left.write(80);
  servo_right.write(65);
  delay(680); // calculated time for 80 speed
  stop();
  Serial.println("stop turning left");
}
void turn_left_90D()
{
  Serial.println("start turning right");
  servo_left.write(80);
  servo_right.write(62);
  delay(500); // calculated time for 100 speed
  stop();
  while (true){
	servo_left.write(80);
	servo_right.write(62);
	if(digitalRead(ir_drive)==HIGH){
  	stop();
  	break;
	}
  }
  flag = 2;
  Serial.println("stop turning right");
}
void turn_180deg(){
  Serial.println("start turning 180deg");
  servo_left.write(75);
  servo_right.write(70);
  delay(1000); // calculated time for 80 speed
  stop();
  Serial.println("stop turning 180deg");
}
void turn_180degL(){ //L is for loaded, so with the cup
  Serial.println("start turning 180deg");
  servo_left.write(74);
  servo_right.write(58);
  delay(1200); // calculated time for 80 speed
  stop();
  Serial.println("stop turning 180deg");
}
void turn_180degD()
{
  Serial.println("start turning 180");
  servo_left.write(96);
  servo_right.write(113);
  delay(500); // calculated time for 100 speed
  stop();
  while (true){
	servo_left.write(96);
	servo_right.write(111);
	if(digitalRead(ir_drive)==HIGH){
  	stop();
  	break;
	}
  }
  servo_left.write(96);
  servo_right.write(111);
  delay(200); // calculated time for 100 speed
  Serial.println("stop turning 180");
}

void follow_line() // first haakon's function, not used anymore
{
  Serial.println("start follow line");
  while (flag == 0)
  {
	if (read_sensor(ir_center) && !read_sensor(ir_right) && !read_sensor(ir_left)) // only center
	{
  	go_forward_fast();
  	Serial.println("only center ON");
	}
	if (read_sensor(ir_center) && !read_sensor(ir_right) && read_sensor(ir_left)) // center and left
	{  
  	servo_left.write(90);
  	servo_right.write(70);  // a bit towards left
  	Serial.println("center and left ON");
	}
	if (!read_sensor(ir_center) && !read_sensor(ir_right) && read_sensor(ir_left)) // left
	{
  	servo_left.write(90);
  	servo_right.write(65);  // towards left
  	Serial.println("only left ON");
	}
	if (read_sensor(ir_center) && read_sensor(ir_right) && !read_sensor(ir_left)) // center and right
	{
  	servo_left.write(110); // a bit towards right
  	servo_right.write(90);
  	Serial.println("center and right ON");
	}
	if (!read_sensor(ir_center) && read_sensor(ir_right) && !read_sensor(ir_left)) // right
	{
  	servo_left.write(115); // towards right
  	servo_right.write(90);
  	Serial.println("only right ON");
	}
	if (read_sensor(ir_center) && read_sensor(ir_right) && read_sensor(ir_left))
	{
  	Serial.println("all three ON");
  	stop();
  	Serial.println("stop follow line: cross detected");
  	flag = 1;
  	break;
	}
	if (!read_sensor(ir_center) && !read_sensor(ir_right) && !read_sensor(ir_left))
	{
  	Serial.println("all three OFF");
  	stop();
	}
    
    
	/*if (read_distance() < 10)
	{
  	stop();
  	break;
	}*/
  }
}

void follow_line_b() // copypaste from a but with slower movement, stops at <int cuppp> cm from the cup
{
  while (true)
  {
	count = count+1;
	Serial.println(read_distance());
	if (digitalRead(ir_center)==HIGH) //  center and crosses (it will stop at the cup, not at the cross)
	{
  	go_forward_slow();
  	//Serial.println("only center ON");
	 
	}
	if (digitalRead(ir_left)==HIGH && digitalRead(ir_center)==HIGH && digitalRead(ir_right)==LOW) // center and left
	{  
  	servo_left.write(90); // 90
  	servo_right.write(85); // 75 // a bit towards left
  	//Serial.println("center and left ON");
 	 
	}
	if (digitalRead(ir_left)==HIGH && digitalRead(ir_center)==LOW && digitalRead(ir_right)==LOW) // left
	{
  	servo_left.write(90); //90
  	servo_right.write(80); //65 // towards left
  	//Serial.println("only left ON");
	 
	}
	if (digitalRead(ir_left)==LOW && digitalRead(ir_center)==HIGH && digitalRead(ir_right)==HIGH) // center and right
	{
  	servo_left.write(96); //105// a bit towards right
  	servo_right.write(92); //90
  	//Serial.println("center and right ON");
 	 
	}
	if (digitalRead(ir_left)==LOW && digitalRead(ir_center)==LOW && digitalRead(ir_right)==HIGH) // right
	{
  	servo_left.write(95); //115// towards right
  	servo_right.write(90); //90
 	// Serial.println("only right ON");
 	 
	}
	if (digitalRead(ir_left)==LOW && digitalRead(ir_center)==LOW && digitalRead(ir_right)==HIGH) // right
	{
  	servo_left.write(95); //115// towards right
  	servo_right.write(90); //90
 	// Serial.println("only right ON");
	}
    
	if (digitalRead(ir_left)==LOW && digitalRead(ir_center)==LOW && digitalRead(ir_right)==LOW)
	{
  	//Serial.println("all three OFF");
  	stop();
	break;
	}
	if (read_distance()<cuppp)
	{
  	Serial.println("---------------cup found--------------------");
	go_forward_slow();
	delay(200);
  	stop();
  	break; 	 
	}
  }
}
void follow_line_c() { //copypaste from b, but stops after the same #while loops of b (so the same lenght)
  //Serial.println("start follow line");
  while (true)
  {
	//count = count-1;
	Serial.println(read_distance());
	if (digitalRead(ir_center)==HIGH) //  center and crosses (it will stop at a certain number of loops)
	{
  	go_forward_slow();
  	//Serial.println("only center ON");
	 
	}
	if (digitalRead(ir_left)==HIGH && digitalRead(ir_center)==HIGH && digitalRead(ir_right)==LOW) // center and left
	{  
  	servo_left.write(90); // 90
  	servo_right.write(80); // 75 // a bit towards left
  	//Serial.println("center and left ON");
 	 
	}
	if (digitalRead(ir_left)==HIGH && digitalRead(ir_center)==LOW && digitalRead(ir_right)==LOW) // left
	{
  	servo_left.write(90); //90
  	servo_right.write(70); //65 // towards left
  	//Serial.println("only left ON");
	 
	}
	if (digitalRead(ir_left)==LOW && digitalRead(ir_right)==HIGH) // center and right
	{
  	servo_left.write(120); //105// a bit towards right
  	servo_right.write(89); //90
  	//Serial.println("center and right ON");
 	 
	}
	if (digitalRead(ir_left)==LOW && digitalRead(ir_center)==LOW && digitalRead(ir_right)==HIGH) // right
	{
  	servo_left.write(120); //115// towards right
  	servo_right.write(89); //90
 	// Serial.println("only right ON");
 	 
	}
    
	if (digitalRead(ir_left)==LOW && digitalRead(ir_center)==LOW && digitalRead(ir_right)==LOW)
	{
  	//Serial.println("all three OFF");
  	stop();
  	break;
	}
  }
}
void follow_line_a_back() // copypaste of a, with inverted movement
{
  Serial.println("start follow line");
  while (true)
  {
	if (digitalRead(ir_left)==LOW && digitalRead(ir_center)==HIGH && digitalRead(ir_right)==LOW) // only center
	{
  	go_backwards();
	}
	if (digitalRead(ir_left)==LOW && digitalRead(ir_center)==LOW && digitalRead(ir_right)==LOW)
	{
  	Serial.println("all three OFF");
  	go_backwards();
	}

	if (digitalRead(ir_left)==HIGH && digitalRead(ir_center)==HIGH && digitalRead(ir_right)==LOW) // center and left
	{  
  	servo_left.write(90);
  	servo_right.write(110);  // a bit towards left
	}
	if (digitalRead(ir_left)==HIGH && digitalRead(ir_center)==LOW && digitalRead(ir_right)==LOW) // left
	{
  	servo_left.write(92);
  	servo_right.write(110);  // towards left

	}
	if (digitalRead(ir_right)==HIGH) // center and right
	{
  	servo_left.write(70); // a bit towards right
  	servo_right.write(92);
	}

	if (digitalRead(ir_left)==HIGH && digitalRead(ir_center)==HIGH && digitalRead(ir_right)==HIGH)
  	{
		stop();
		break;
  	}
	
  }
}


// Arm---------------------------------------------------------------------------------------
Servo grabberServo;
Servo lifterServo;

int grabberPin = 5;
int lifterPin = 3;
int Close = 42; // the Answer
int Open = 5;
int Open2 =  15;
int ultrahigh = 0;
int High = 20;
int Low = 160;

void grab()
{
  Serial.println("------- Searching for cup --------");
  grabberServo.write(Close);
  delay(1000);
  lifterServo.write(High);
}

void leave()
{
  Serial.println("--------leaving the cup-------");
  lifterServo.write(Low);
  delay(1000);
  grabberServo.write(Open2);
  //follow_line_a_back(); // reverse of follow_line_a until the cross
  //grabberServo.write(Close);
}

// Feet ----------------------------------------------------------------------------------------

Servo left_push;
Servo right_push;

int left_push_pin = 10;
int right_push_pin = 11;

int count10 = 0;

void pull() {
  left_push.write(160);
  right_push.write(20);
}
void push() {
  left_push.write(5);
  right_push.write(175);
}
// Levels---------------------------------------------------------------------------------------
void lvl1()
{
  int cup_position = 0; // 0: the cup is initially on the right
  follow_line_a();
  turn_right_90D(); // there was 90D
  delay(1000);
 
  if (read_distance() > 20)
  {
	/* go_forward_fast();
	delay(1000);
	stop();
	delay(1000);
	turn_180deg();
	cup_position = 1; // cup is initially on the left 	
	follow_line_a(); */
	follow_line_c();
	delay(1000);
	turn_180degD();
	delay(1000);
	cup_position = 1; 
	follow_line_a();
	delay(1000);
  }
  grabberServo.write(Open);
  follow_line_b();
  delay(1000);
  grab();
  delay(500);
  //NOW WE HAVE THE CUP
  turn_180degD(); //was D
  follow_line_a();
  follow_line_c();
  stop();
  leave(); // this includes going backwards to the cross and close clamp
  delay(500);
  lifterServo.write(ultrahigh);
  delay(500);
  //turn 180
  servo_left.write(75);
  servo_right.write(70);
  delay(1000);
  
  follow_line_a();
  delay(500);
  grabberServo.write(Low);
  grabberServo.write(Close);
  
  if (cup_position == 0)
  {
	turn_left_90D();
  }
  else
  {
	turn_right_90D(); // both were D
  }
  //go_forward();
  //delay(300); // time to leave cross (then level 2 can start)
  stop();
  flag=3;  
}
void lvl2()
{
  follow_line_a(); // pay attention to the sharp turn (function follow_line ad hoc with turn left if steady on sharp curve)
}
void follow_ramp(){
	while (true)
  {
	//CENTER ON
	if (digitalRead(ir_left)==LOW && digitalRead(ir_center)==HIGH && digitalRead(ir_right)==LOW) // only center
	{
  	servo_left.write(140);
  	servo_right.write(60);
  	
	}
	//CENTER LEFT
	if (digitalRead(ir_left)==HIGH && digitalRead(ir_center)==HIGH && digitalRead(ir_right)==LOW) // center and left
	{  
  	servo_left.write(86); //90
  	servo_right.write(75);  // a bit towards left
	}
	//LEFT
	if (digitalRead(ir_left)==HIGH && digitalRead(ir_center)==LOW && digitalRead(ir_right)==LOW) // left
	{
  	servo_left.write(86); //90
  	servo_right.write(70);  // towards left
	}
	//CENTER RIGHT
	if (digitalRead(ir_left)==LOW && digitalRead(ir_center)==HIGH && digitalRead(ir_right)==HIGH) // center and right
	{
  	servo_left.write(98); // a bit towards right
  	servo_right.write(88); //90
	}
	//RIGHT
	if (digitalRead(ir_left)==LOW && digitalRead(ir_center)==LOW && digitalRead(ir_right)==HIGH) // right
	{
  	servo_left.write(100); // towards right
  	servo_right.write(88); //90
	}
	//CROSS
	if (digitalRead(ir_left)==HIGH && digitalRead(ir_center)==HIGH && digitalRead(ir_right)==HIGH)
	{
  	stop();
	}
	// OFF LINE
	if (digitalRead(ir_left)==LOW && digitalRead(ir_center)==LOW && digitalRead(ir_right)==LOW)
	{
	go_forward_slow(); // all three are off
	}
  }
}

void follow_line_3 (int count) {
  
  int counter = 0;
  while (true)
  {
    if (digitalRead(ir_left)==LOW && digitalRead(ir_center)==HIGH && digitalRead(ir_right)==LOW) // only center
    {
        servo_left.write(130);
  		servo_right.write(50);
    }
    if (digitalRead(ir_left)==HIGH && digitalRead(ir_center)==HIGH && digitalRead(ir_right)==LOW) // center and left
    {  
      servo_left.write(88); //90
      servo_right.write(80);  // a bit towards left
      Serial.println("center and left ON");
    }
    if (digitalRead(ir_left)==HIGH && digitalRead(ir_center)==LOW && digitalRead(ir_right)==LOW) // left
    {
      servo_left.write(88); //90
      servo_right.write(80);  // towards left
    }
    if (digitalRead(ir_left)==LOW && digitalRead(ir_center)==HIGH && digitalRead(ir_right)==HIGH) // center and right
    {
      servo_left.write(100); // a bit towards right
      servo_right.write(92); //90
    }
    if (digitalRead(ir_left)==LOW && digitalRead(ir_center)==LOW && digitalRead(ir_right)==HIGH) // right
    {
      servo_left.write(110); // towards right
      servo_right.write(100); //90
    }
    if (digitalRead(ir_left)==HIGH && digitalRead(ir_center)==HIGH && digitalRead(ir_right)==HIGH)
    {
		stop();
		break;
    }
    if (digitalRead(ir_left)==LOW && digitalRead(ir_center)==LOW && digitalRead(ir_right)==LOW)
    {
      go_forward_slow();
    }
	counter ++;
	if(counter == count) {
		counter =0;
		stop();
		break;
	}
  }

}

void gun1(int del){
	servo_left.write(130);
  	servo_right.write(48);
	delay(del);
	stop();
	delay(1300);
}
void gun2(int del){
	servo_left.write(127);
  	servo_right.write(48);
	delay(del);
	stop();
	delay(1300);
}

void lvl3()
{
//ramp and first bar
	gun1(2300);
	turn_right_90D();
	// second bar and turn
	gun1(1050);
	turn_right_90D();
	//sandpit stuck
	gun2(1600);
	servo_left.write(106);
  	servo_right.write(58);
	//sand trap
	push();
	delay(300);
	pull();
	delay(300);
	push();
	delay(300);
	pull();
	// catch the line
	follow_line_a();
	delay(20000);
	//turn and move to lvl 4
	turn_left_90D();
	follow_line_a();
}

void tick() {
  servo_left.write(96); 
  servo_right.write(102);
  delay(200);
  stop();
  delay(500);
}

void scan() {
	int num = 0;
	int iter = 0;
	int dists[] = {25, 25, 25, 25 ,50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 25, 25, 25, 25};
	while(read_distance() > dists[iter]) {
    tick();
	num += 1;
	iter += 1;
	if (num > 20) {
		num = 0;
		iter = 0;
		turn_left_90();
	}
  }
}

void limp() //
{
  Serial.println("going forward");
  servo_left.write(95);
  servo_right.write(82);
}

void lvl4()
{
  // get to the start of the box
  follow_line_a();
  delay(2000);
  grabberServo.write(Open);
  delay(1000);

  //inital turn to to the left
  servo_left.write(80);
  servo_right.write(65);
  delay(340); 
  stop();

  //scan
  int num = 0;
  int iter = 0;
  int dists[] = {10, 25, 25, 25 ,50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 25, 25, 25, 25};
  while(read_distance() > dists[iter]) {
	tick();
  	num += 1;
  	iter += 1;
  	if (num > 20) {
		num = 0;
		iter = 0;
		turn_left_90();
  	}
  }
  tick();
  delay(1000);
  // Move to the cup
  while(read_distance() > 3.5) {
	servo_left.write(95);
	servo_right.write(76);
  }
  stop();
  //pick it up and move back to the line
  grab();
  //turn with the cup
  if(iter < 7) {
	servo_left.write(96);
	servo_right.write(106);
	delay(1250);

	servo_left.write(95);
	servo_right.write(78);
	delay(1000);
	stop();

	servo_left.write(95);
	servo_right.write(106);
	delay(1450);
	stop();
  }
  else {
	servo_left.write(96);
	servo_right.write(106);
	delay(1250);

	servo_left.write(95);
	servo_right.write(106);
	delay(1450);
	stop();
  }

  while(digitalRead(ir_left)==LOW && digitalRead(ir_center)==LOW && digitalRead(ir_right)==LOW) {
    servo_left.write(96);
	servo_right.write(80);
  }
  stop();
  // on the line
  turn_right_90D();
  // on the line facing the cross
  follow_line_a();
  // at the cross
  servo_left.write(80);
  servo_right.write(65);
  delay(400); // calculated time for 80 speed
  stop();
  delay(1000);
  // on the cross facing the way back
  servo_left.write(97);
  servo_right.write(80);
  delay(1000);
  stop();
  delay(1000);
  // on the line facing the vay bac
  follow_line_a();
  servo_left.write(80);
  servo_right.write(65);
  delay(400); // calculated time for 80 speed
  follow_line_a();
  leave();
}



void setup()
{

  Serial.begin(9600);
  // ir
  pinMode(ir_left, INPUT);
  pinMode(ir_right, INPUT);
  pinMode(ir_center, INPUT);
  pinMode(ir_drive, INPUT);


  // Ultrasonic
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);

  // Servo
  servo_left.attach(servo_L);
  servo_right.attach(servo_R);

  // Arm
  grabberServo.attach(grabberPin);
  lifterServo.attach(lifterPin);
  grabberServo.write(Close);
  lifterServo.write(Low);

  // Feet
  left_push.attach(left_push_pin);
  right_push.attach(right_push_pin);
  pull();
}

void loop() //testing
{
	lvl3();
}
