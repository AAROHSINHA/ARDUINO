int xPin = A0;
int yPin = A2;
int xValue;
int yValue;

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
byte segmentPins[] = {A, B, C, D, E, F, G, DP};

const char* numbers[] = {
  "00000011",  // 0b00000011
  "10011111",  // 0b10011111
  "00100101",  // 0b00100101
  "00001101",  // 0b00001101
  "10011001",  // 0b10011001
  "01001001",  // 0b01001001
  "01000001",  // 0b01000001
  "00011111",  // 0b00011111
  "00000001",  // 0b00000001
  "00001001"   // 0b00001001
};



void setup(){
  for(int i = 0; i < 4; i+=1){
    pinMode(digitPins[i], OUTPUT);
    digitalWrite(digitPins[i], LOW);
  }

  for(int i = 0; i < 8; i+=1){
    pinMode(segmentPins[i], OUTPUT);
  }
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  Serial.begin(9600);
}
void displayDigit(byte digit, int num) {
  digitalWrite(digit, HIGH);
  const char* number = numbers[num];  // Use the char array directly

  for (int i = 0; i < 8; i++) {
    if (number[i] == '0') {  // Check if the character is '0'
      digitalWrite(segmentPins[i], LOW);
    } else {
      digitalWrite(segmentPins[i], HIGH);
    }
  }
  delay(6);
  digitalWrite(digit, LOW);
}

void display_yValue(int val){
  int index = 3;
  while(val > 0){
    if(index < 0) index = 3;
    Serial.print(val%10);
    Serial.print("\t");
    // now we have to display
    displayDigit(digitPins[index], val%10);
    val/=10;
    index--;
  }
  Serial.print("\n");
}

void loop(){
  // displayDigit(D1, 1);
  // displayDigit(D2, 2);
  // displayDigit(D3, 3);
  // displayDigit(D4, 4);
  yValue = analogRead(yPin);
  display_yValue(yValue);


  /*
  => DO THIS MANUALLY FIRST TO SEE IF IT WORKS
  1. GLOW THE LED 1 VERY BRIGHTLY
  2. THEN GLOW THE LED 2 VERY BRIGHTLY
  */
}
