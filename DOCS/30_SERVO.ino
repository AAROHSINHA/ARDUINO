#include <Servo.h>
int x_val;
int y_val;
int x_pin = A0;
int y_pin = A1;
int switchPin = 2;
int switchVal;
int ledPin = 13;
int dt = 200;
int servoPin = 9;
int servoAngle;
Servo myServo;
int speakerPin = 7;

void setup(){
  pinMode(x_pin, INPUT);
  pinMode(y_pin, INPUT);
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(speakerPin, OUTPUT);
  digitalWrite(switchPin, HIGH);
  myServo.attach(servoPin);
  Serial.begin(9600);
}

void loop(){
  x_val = analogRead(x_pin);
  y_val = analogRead(y_pin);
  switchVal = digitalRead(switchPin);
  int freqMapping = map(y_val, 0, 1023, 0, 523);

  if(switchVal == 0){
    digitalWrite(ledPin, HIGH);
  }else{
    digitalWrite(ledPin, LOW);
  }
 
  servoAngle = 180 - (180./1023.)*x_val;
  myServo.write(servoAngle);
  tone(speakerPin, freqMapping);
}

 // delay(dt);
  // Serial.print("X Value = ");
  // Serial.print(x_val);
  // Serial.print("\tY value = ");
  // Serial.print(y_val);
  // Serial.print("\tSwitch State is - ");
  // Serial.println(switchVal);
