int ledPins[] = {2, 3, 4, 5, 6, 9, 10, 11 ,12};
int numLeds = 9;
int readPin = A0;
int readValue;
int dt1 = 100;

void setup(){
  for(int index = 0; index < numLeds; index++){
    pinMode(ledPins[index], OUTPUT);
  }
  Serial.begin(9600);
}

void loop(){
  readValue = analogRead(readPin);
  int ledCurrent = map(readValue, 0, 1023, 0, numLeds - 1);
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], LOW);
  }
  for(int i = 0; i <= ledCurrent; i++){
    digitalWrite(ledPins[i], HIGH);
  }
  Serial.println(ledCurrent);
  delay(dt1);
}
