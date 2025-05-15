int readPin = A0;
int buzzPin = 8;
int readValue;
float delayTime;

void setup(){
  pinMode(readPin, INPUT);
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);
}

// potentiometer 1023 --> 1000Us
// potentiometer 0 --> 60Us
// and middle in between that

void loop(){
  readValue = analogRead(readPin);
  // formula - 
  delayTime = (940./1023.)*readValue + 60;

  // digitalWrite
  digitalWrite(buzzPin, HIGH);
  delayMicroseconds(delayTime);
  digitalWrite(buzzPin, LOW);
  delayMicroseconds(delayTime);
}
