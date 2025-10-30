int switchPin1 = 5;
int switchPin2 = 6;
int switchPin3 = 7;
int switchState1;
int switchState2;
int switchState3;
int buzzPin = 13;
int redPin = 8;
int greenPin = 9;
int bluePin = 10;

void setup(){
  pinMode(switchPin1, INPUT);
  pinMode(switchPin2, INPUT);
  pinMode(switchPin3, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);
    
}

void loop(){
  switchState1 = digitalRead(switchPin1);
  switchState2 = digitalRead(switchPin2);
  switchState3 = digitalRead(switchPin3);

  if(switchState1 == 0 && switchState2 == 1 && switchState3 == 1){
     digitalWrite(redPin, HIGH);
     digitalWrite(greenPin, LOW);
     digitalWrite(bluePin, LOW);
     digitalWrite(buzzPin, HIGH);
   }else if(switchState1 == 1 && switchState2 == 0 && switchState3 == 1){
     digitalWrite(redPin, LOW);
     digitalWrite(greenPin, HIGH);
     digitalWrite(bluePin, LOW);
     digitalWrite(buzzPin, HIGH);
   }else if(switchState1 == 1 && switchState2 == 1 && switchState3 == 0){
     digitalWrite(redPin, LOW);
     digitalWrite(greenPin, LOW);
     digitalWrite(bluePin, HIGH);    
     digitalWrite(buzzPin, HIGH);
   }else{
     digitalWrite(redPin, LOW);
     digitalWrite(greenPin, LOW);
     digitalWrite(bluePin, LOW);   
     digitalWrite(buzzPin, LOW); 
   }

}
