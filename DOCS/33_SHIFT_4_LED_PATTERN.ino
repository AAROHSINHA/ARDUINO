int latchPin = 11;
int clockPin = 9;
int dataPin = 12;
int dt1 = 500;

// data packs
byte LED_1 = 0b11110000;
byte LED_2 = 0b00001111;

void setup(){
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop(){
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, LED_1);
  digitalWrite(latchPin, HIGH);

  delay(dt1);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, LED_2);
  digitalWrite(latchPin, HIGH);

  delay(dt1);
}
