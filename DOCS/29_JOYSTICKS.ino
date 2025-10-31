int Xpin = A0;
int Ypin = A2;
int switchPin = 2; // digital Pin 2
int Xval; // we will read X
int Yval ; // we will read y
int switchVal; // read the switch pin 2
int dt = 200;

void setup(){
  Serial.begin(9600);
  pinMode(Xpin, INPUT);
  pinMode(Ypin, INPUT);
  pinMode(switchPin, INPUT);
  digitalWrite(switchPin, HIGH);
}

void loop(){
	  Xval = analogRead(Xpin); // 0 on left and 1023 on right
	  Yval = analogRead(Ypin); // 0 on top 1023 on down
	  switchVal = digitalRead(switchPin);
  delay(dt);
  Serial.print("X Value = ");
  Serial.print(Xval);
  Serial.print("\tY value = ");
  Serial.print(Yval);
  Serial.print("\tSwitch State is - ");
  Serial.println(switchVal);
}

int x_val;
int y_val;
int x_pin = A0;
int y_pin = A1;
int switchPin = 2;
int switchVal;
int ledPin = 13;
int dt = 200;

void setup(){
  pinMode(x_pin, INPUT);
  pinMode(y_pin, INPUT);
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(switchPin, HIGH);
  Serial.begin(9600);
}

void loop(){
  x_val = analogRead(x_pin);
  y_val = analogRead(y_pin);
  switchVal = digitalRead(switchPin);
  if(switchVal == 0){
    digitalWrite(ledPin, HIGH);
  }else{
    digitalWrite(ledPin, LOW);
  }
  delay(dt);
  Serial.print("X Value = ");
  Serial.print(x_val);
  Serial.print("\tY value = ");
  Serial.print(y_val);
  Serial.print("\tSwitch State is - ");
  Serial.println(switchVal);
}
