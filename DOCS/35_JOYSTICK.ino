int xPin = A0;
int yPin = A2;
int switchPin = 2;
int Xval;
int Yval;
int switchVal;
int dt = 200;

int latchPin = 11;
int clockPin = 9;
int dataPin = 12;
int greenPin = 3;
byte data = 0b11110000;

void setup(){
  Serial.begin(9600);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(switchPin, INPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  digitalWrite(switchPin, HIGH);
}

void loop(){
  Xval = analogRead(xPin); // 0 on left and 1023 on right
  Yval = analogRead(yPin); // 0 on top 1023 on down
  switchVal = digitalRead(switchPin);

  if(switchVal== 0){
    digitalWrite(greenPin, HIGH);
  }else{
    digitalWrite(greenPin, LOW);
  }

  digitalWrite(latchPin, LOW);
  if(Xval > 500 && Xval < 530){
      if(Yval < 500) shiftOut(dataPin, clockPin, LSBFIRST, 0b10000000);
      else if(Yval > 530) shiftOut(dataPin, clockPin, LSBFIRST, 0b01000000);
      else shiftOut(dataPin, clockPin, LSBFIRST, 0b00000000);
  }else if(Yval > 500 && Yval < 530){
      if(Xval < 500) shiftOut(dataPin, clockPin, LSBFIRST, 0b00100000);
      else if(Xval > 530) shiftOut(dataPin, clockPin, LSBFIRST, 0b00010000);
     else shiftOut(dataPin, clockPin, LSBFIRST, 0b00000000);
  }
  digitalWrite(latchPin, HIGH);

  Serial.print("X Value = ");
  Serial.print(Xval);
  Serial.print("\tY value = ");
  Serial.print(Yval);
  Serial.print("\tSwitch State is - ");
  Serial.println(switchVal);

  delay(dt);
}

/*
  Serial.print("X Value = ");
  Serial.print(Xval);
  Serial.print("\tY value = ");
  Serial.print(Yval);
  Serial.print("\tSwitch State is - ");
  Serial.println(switchVal);
*/
