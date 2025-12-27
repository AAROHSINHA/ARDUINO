byte D1 = 2;
byte D2 = 3;
byte D3 = 4;
byte D4 = 5;

byte digitPins[] = {D1, D2, D3, D4};

byte A = 6;
byte B = 7;
byte C = 8;
byte D = 9;
byte E = 10;
byte F = 11;
byte G = 12;
byte DP = 13;
const int segmentPins[] = {A, B, C, D, E, F, G, DP};

uint8_t digitON = HIGH;
uint8_t digitOFF = LOW;
uint8_t segmentON = LOW;
uint8_t segmentOFF = HIGH;
/*
Note that for segment, On - LOW and off - HIGH
This is because, when suppose D1 is HIGH, This also makes the segments inside it HIGH
so D1 - HIGH -> A/B/C/D/E/F/G - HIGH
And they will ke on glowing. we have to turn them off before hand
*/

void display(byte pin, byte number){
  digitalWrite(pin, HIGH);
  int digitCount = 7;
  while(digitCount >= 0){
    byte digit = (number >> (7 - digitCount)) & 0x01;
    if(digit == 0){
      digitalWrite(segmentPins[digitCount], HIGH);
    }else{
      digitalWrite(segmentPins[digitCount], LOW);
    }
    digitCount--;
  }
}

void setup(){
  for(int i = 0; i < 8; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  for(int i = 0; i < 4; i++){
    pinMode(digitPins[i], OUTPUT);
    digitalWrite(digitPins[i], LOW);
  }
}

void loop(){
  display(D3, 0b11110010); // turning the first digit on and displaying 1

}
