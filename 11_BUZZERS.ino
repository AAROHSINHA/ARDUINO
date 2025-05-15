// THIS PROGRAM WARNS THE USER IF Someone uses a user input of above 10
int buzzPin = 8;
int myNum;
int d1 = 100;
int d2 = 1000;

void setup(){
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  Serial.print("Please Enter a number - ");
  while(Serial.available() == 0){
    // HAND AROUND
  }
  myNum = Serial.parseInt();
  if(myNum > 10){
    digitalWrite(buzzPin, HIGH);
    delay(d1);
    digitalWrite(buzzPin, LOW);
  }
  delay(d2);
}
