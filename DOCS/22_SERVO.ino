#include <Servo.h> // To use the servo we need to import this external Servo.h library
int servoPin = 9;
int servoPos = 180;
// now consider this as...Servo is an object in the real world. So to use the servo and interact with it
// we need to create a virtual object for servo to access it
Servo myServo; // This is the object


void setup(){
  Serial.begin(9600);
  // we need to attach the servo to the servoPin
  myServo.attach(servoPin); // now it gets attached
}

void loop(){
  // issue a command to the servo to just go to a position
  myServo.write(servoPos);
}
#include <Servo.h>
int servoPin = 9;
int servoPos; // degrees - where to go
// note that the servos we use in tutorials, are kinda cheap and for learning purposes, so might not
// go completely till 180 and so...

// try to think it this way - the servo motor is an object in real world,
// so we have to create a virtual object in the arduino compiler
Servo myServo; // this is an object called myServo

void setup(){
  Serial.begin(9600);
  myServo.attach(servoPin); // which pin is our servo controller attached to
}

void loop(){
  // we want the servo to go in an position
  Serial.println("WHAT ANGLE FOR THE SERVO - ");
  while(Serial.available() == 0){}
  servoPos = Serial.parseInt();
  myServo.write(servoPos); 
}
