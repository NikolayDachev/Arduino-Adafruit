// 4WD movement 
// Nikolay Dachev
// 2014

#include <AFMotor.h>
#include <Servo.h>

// Servo Motors
Servo servo1;
Servo servo2;

// DC Motors
AF_DCMotor motor1(1); // Front Left
AF_DCMotor motor2(2); // Back Left
AF_DCMotor motor3(3); // Front Right
AF_DCMotor motor4(4); // Back Right

// motor comand
char go[3] = {FORWARD, BACKWARD, RELEASE};

// servos init config
int servo1_pos = 0; // init servo 1 positison
int servo2_pos = 0; // init servo 2 positison

// easy control motor
// MT(motor number(1-4), motor speed, direction(go[0-2]))
int MT(int motor_number ,int speed, int direction){
  if (motor_number == 1) {
     motor1.setSpeed(speed);
     motor1.run(go[direction]);
  }
  if (motor_number == 2) {
     motor2.setSpeed(speed);
     motor2.run(go[direction]);
  }
  if (motor_number == 3) {
     motor3.setSpeed(speed);
     motor3.run(go[direction]);
  }
  if (motor_number == 4) {
     motor4.setSpeed(speed);
     motor4.run(go[direction]);
  }
}

// mangage all 4 motors
// speed motor speed
// direction: 1 - forward, 2 - backword, 3 - left, 4 - right, 5- full stop
// time - delay time 
int go4wd(int speed, int direction, int time){
// var directions
int dr[] = {3, 3, 3, 3};

// forward
   if (direction == 1){
     dr[0] = 0;
     dr[1] = 0;
     dr[2] = 0;
     dr[3] = 0;
   }
// backword
   if (direction == 2){
     dr[0] = 1;
     dr[1] = 1;
     dr[2] = 1;
     dr[3] = 1;
   }
// left
      if (direction == 3){
     dr[0] = 0;
     dr[1] = 0;
     dr[2] = 1;
     dr[3] = 1;
   }
// right
   if (direction == 4){
     dr[0] = 1;
     dr[1] = 1;
     dr[2] = 0;
     dr[3] = 0;
   }
// full stop
   if (direction == 5){
     dr[0] = 2;
     dr[1] = 2;
     dr[2] = 2;
     dr[3] = 2;
   }
// go 4wd

      MT(1, speed, dr[0]);  
      MT(2, speed, dr[1]);
      MT(3, speed, dr[2]);
      MT(4, speed, dr[3]);

     delay(time);
}

// demo all directions
int demo(){
   Serial.println("DEMO BEGIN");
   
   Serial.println("GO FORWARD - 1");
   go4wd(255, 1, 1000);
   go4wd(255, 5, 500);
   
   Serial.println("GO BACKWORD - 2");
   go4wd(255, 2, 1000);
   go4wd(255, 5, 500);
   
   Serial.println("GO LEFT - 3");
   go4wd(255, 3, 1000);
   go4wd(255, 5, 500);
   
   Serial.println("GO RIGHT - 4");
   go4wd(255, 4, 1000);
   go4wd(255, 5, 500);
   
   Serial.println("DEMO END");
   Serial.println(" ");
   
   // SERVO 1
   for(servo1_pos = 0; servo1_pos < 180; servo1_pos += 1)  // goes from 0 degrees to 180 degrees
   {                                  // in steps of 1 degree
     servo1.write(servo1_pos);              // tell servo to go to position in variable 'pos'
     delay(15);                       // waits 15ms for the servo to reach the position
  }
  for(servo1_pos = 180; servo1_pos>=1; servo1_pos-=1)     // goes from 180 degrees to 0 degrees
  {                                
     servo1.write(servo1_pos);              // tell servo to go to position in variable 'pos'
     delay(15);                       // waits 15ms for the servo to reach the position
  } 

  // SERVO 2
  for(servo2_pos = 0; servo2_pos < 180; servo2_pos += 1)  // goes from 0 degrees to 180 degrees
  {                                  // in steps of 1 degree
     servo2.write(servo2_pos);              // tell servo to go to position in variable 'pos'
     delay(15);                       // waits 15ms for the servo to reach the position
  }
  for(servo2_pos = 180; servo2_pos>=1; servo2_pos-=1)     // goes from 180 degrees to 0 degrees
  {                                
     servo2.write(servo2_pos);              // tell servo to go to position in variable 'pos'
     delay(15);                       // waits 15ms for the servo to reach the position
  } 
}

void setup() {
  Serial.begin(9600);  // set up Serial library at 9600 bps
  // conect servos to arduino pins
  servo1.attach(9);
  servo2.attach(10);

}

void loop() {

      demo();
}

