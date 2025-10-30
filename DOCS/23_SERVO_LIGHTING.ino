#include <Servo.h>
int readPin = A0;
int readValue;
int angle;
int dt1 = 100;
Servo myServo;
int servoPin = 3;

// so basically we connect a photoresistor circuit. Then to take the value of potential drop
// at the point, we need connect a jumper cable to A0 to take in analog value of potential.
// then for angle range [20, 160] and voltage range [0, 1023], we find the equation
// and get the resultant angle and write in servo

void setup(){
  pinMode(readPin, INPUT);
  myServo.attach(servoPin);
  Serial.begin(9600);
}

void loop(){
  readValue = analogRead(readPin);
  angle  =(-1)*(160./1003.)*readValue + 160;
  Serial.print(readValue);
  Serial.print(" --- ");
  Serial.print(angle);
  Serial.print("\n");
  myServo.write(angle);
  delay(dt1);
}
