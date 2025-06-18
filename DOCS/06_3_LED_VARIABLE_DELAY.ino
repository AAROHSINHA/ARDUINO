// variables are declared before the void setup(){}
int redLED = 8;
int greenLED = 9;
int blueLED = 10;
int redDelay = 50;
int greenDelay = 500;
int blueDelay = 2000;
int midDelay = 1000;

void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  delay(midDelay);
  for(int i = 0; i < 15; i+=1){
    digitalWrite(redLED, HIGH);
    delay(redDelay);
    digitalWrite(redLED, LOW);
    delay(redDelay);
  }
  delay(midDelay);
  for(int i = 0; i < 10; i+=1){
    digitalWrite(greenLED, HIGH);
    delay(greenDelay);
    digitalWrite(greenLED, LOW);
    delay(greenDelay);
  }
  delay(midDelay);
  for(int i = 0; i < 5; i+=1){
    digitalWrite(blueLED, HIGH);
    delay(blueDelay);
    digitalWrite(blueLED, LOW);
    delay(blueDelay);
  }
}
