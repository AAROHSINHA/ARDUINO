#include <Servo.h>
int servoPin = 8;
int ServoPos = 0;
Servo myServo;

int greenPin = 4;
int redPin = 5;
int triggerPin = 2;
int echoPin = 3;
int setupTime = 150;
int pingTravelTime;
float time;
float distance;
float speed = 327.09;

void setup(){
  // we pinMode the triggerPin and echoPin
  // echoPin must be input
  // as the triggerPin must be given a pulse.
  // then the echoPin starts and it reads the echos from collision of objects. So it takes input
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  Serial.begin(9600);
  myServo.attach(servoPin);
  delay(setupTime);
}

void loop(){
  // sending a pulse to the triggerPin
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(10);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  // Now the echo pin is activated. It records the time the signal takes to 
  // start from the sensor face, to to the object, collide with it and return back
  // notice that this covers 2xdistance of object
  pingTravelTime = pulseIn(echoPin, HIGH);
  time = pingTravelTime*0.000001;
  distance = speed*time;
  distance/=2;
  distance*=100;
  Serial.println(distance);

  // pingTime is noted in Useconds (microseconds). let's convert it into seconds

  if(distance <= 12 && distance >= 1){
    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
    myServo.write(90);
    // delay(2000);
  }else{
    digitalWrite(greenPin, LOW);
    digitalWrite(redPin, HIGH);
    myServo.write(0);
  }

  delay(250);

  
}

/*
  time = pingTravelTime*0.000001;
  distance = speed*time;
  distance/=2;
  distance*=100;
*/

/*

*/
