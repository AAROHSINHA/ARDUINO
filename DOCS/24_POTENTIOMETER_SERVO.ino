#include <Servo.h>
int readPin = A0;
int angle;
int readVal;
Servo myServo;
int servoPin = 7;
int dt1 = 15;

// BASICALLY WE TAKE ANALOG INPUT AND GET A FUNCTION TO WRITE IN SERVO

void setup() {
  // put your setup code here, to run once:
  pinMode(readPin, INPUT);
  Serial.begin(9600);
  myServo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  readVal = analogRead(readPin);
  angle = (140./1023.)*readVal + 20;
  Serial.println(angle);
  myServo.write(angle);
  delay(dt1);
}
