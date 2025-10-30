int switchPin1 = 3;
int switchPin2 = 4;
int switchPin3 = 5;
int switchPin4 = 6;
int switch1;
int switch2;
int switch3;
int switch4;
int buzzPin = 8;

void setup(){
  pinMode(switchPin1, INPUT);
  pinMode(switchPin2, INPUT);
  pinMode(switchPin3, INPUT);
  pinMode(switchPin4, INPUT);
  Serial.begin(9600);
}

void loop(){
  switch1 = digitalRead(switchPin1);
  switch2 = digitalRead(switchPin2);
  switch3 = digitalRead(switchPin3);
  switch4 = digitalRead(switchPin4);
  Serial.print(switch1);  
  Serial.print(" ");      
  Serial.print(switch2);
  Serial.print(" ");
  Serial.print(switch3);  
  Serial.print(" ");      
  Serial.print(switch4);
  Serial.print("\n");
  if (switch1 == 1 && switch2 == 0 && switch3 == 0 && switch4 == 0) {
    tone(buzzPin, 1000);
  } else if (switch1 == 0 && switch2 == 1 && switch3 == 0 && switch4 == 0) {
    tone(buzzPin, 400);
  } else if (switch1 == 0 && switch2 == 0 && switch3 == 1 && switch4 == 0) {
    tone(buzzPin, 800);
  } else if (switch1 == 0 && switch2 == 0 && switch3 == 0 && switch4 == 1) {
    tone(buzzPin, 600);
  }else{
    noTone(buzzPin);
  }

}
