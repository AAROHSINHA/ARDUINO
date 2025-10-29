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

// THIS PROGRAM WARNS THE USER IF Someone uses a user input of above 10
int buzzPin = 8;
int myNum;
int d1 = 100;
int d2 = 1000;

void setup(){
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);
}

// CODE 2 - BUZZ THE BUZZER WHEN POTENTIOMETER READING IS MORE THAN 800
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

int buzzPin = 8;
int dt1 = 1;
int dt = 2;
int j;

void setup(){
  pinMode(buzzPin, OUTPUT);
}

// CODE 3 - GETTING A LITTLE BIT OF TONE FROM ACTIVE BUZZER (VERY ANNOYING)
void loop(){
  for(j = 1; j <= 100; j = j + 1){
    digitalWrite(buzzPin, HIGH);
    delay(dt1);
    digitalWrite(buzzPin, LOW);
    delay(dt1);
  }
  for(j = 1; j <= 100; j = j + 1){
    digitalWrite(buzzPin, HIGH);
    delay(dt2);
    digitalWrite(buzzPin, LOW);
    delay(dt2);
  }
}
