int dt1 = 100; // for setup

int switchPin1 = 2;
int switchPin2 = 3;
int switchPin3 = 4;
int switchVal1;
int switchVal2;
int switchVal3;
int lightPins[] = {5, 6, 7, 8, 9, 10, 11, 12};

// lightshow 1
void lightshow1(){
  delay(100);
  for(int i = 0; i < 8; i++) digitalWrite(lightPins[i], HIGH);
  delay(1000);
  for(int i = 0; i < 8; i+=2) digitalWrite(lightPins[i], LOW);
  delay(500);
  for(int i = 0; i < 8; i++) digitalWrite(lightPins[i], LOW);
  for(int i = 0; i < 8; i+=2) digitalWrite(lightPins[i], HIGH);
  delay(1000);
  for(int i = 0; i < 8; i++) digitalWrite(lightPins[i], LOW);
}

void lightshow2(){
  for(int i = 0; i < 8; i++) digitalWrite(lightPins[i], HIGH), delay(100), digitalWrite(lightPins[i], LOW);
  for(int i = 6; i >= 0; i--) digitalWrite(lightPins[i], HIGH), delay(100), digitalWrite(lightPins[i], LOW);
}

void lightshow3(){
  for(int i = 0; i < 8; i++) digitalWrite(lightPins[i], HIGH), delay(100);
  for(int i = 0; i < 8; i++) digitalWrite(lightPins[i], LOW);
  for(int i = 6; i >= 0; i--) digitalWrite(lightPins[i], HIGH), delay(100);
  for(int i = 0; i < 8; i++) digitalWrite(lightPins[i], LOW);
}


void setup(){
  pinMode(switchPin1, INPUT);
  pinMode(switchPin2, INPUT);
  pinMode(switchPin3, INPUT);
  for(int i = 0; i < 8; i++){
    pinMode(lightPins, OUTPUT);
  }
  Serial.begin(9600);
}

void loop(){
  switchVal1 = digitalRead(switchPin1);
  switchVal2 = digitalRead(switchPin2);
  switchVal3 = digitalRead(switchPin3);
   if (switchVal1 == 0 && switchVal2 == 1 && switchVal3 == 1) {
    delay(10);
    while(digitalRead(switchPin1) == 0){}
    switchVal1 = 1;
    lightshow1();
  } else if (switchVal1 == 1 && switchVal2 == 0 && switchVal3 == 1) {
    delay(10);
    while(digitalRead(switchPin2) == 0){}
    switchVal2 = 1;
    lightshow2();
  } else if (switchVal1 == 1 && switchVal2 == 1 && switchVal3 == 0) {
    delay(10);
    while(digitalRead(switchPin3) == 0){}
    switchVal3 = 1;
    lightshow3();
  } 
  delay(10);
}