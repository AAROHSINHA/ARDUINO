int latchPin = 11;
int clockPin = 9;
int dataPin = 12;
byte data;
int decimalNumber;
byte convertedNumber;

void setup(){
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop(){
  data = random(0, 256);
  Serial.println("PROVIDE THE CORRECT DECIMAL NUMBER - ");
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, data);
  digitalWrite(latchPin, HIGH);

  // now take in user input
  while(Serial.available() == 0){
    // hang around
  }
  decimalNumber = Serial.parseInt();
  convertedNumber = decimalNumber;
  if(convertedNumber == data){
    Serial.println("CORRECTT!!!!!!!!!!!!!!!!!");
  }else{
    Serial.println("WRONGGG.....................");
  }
  delay(1000);
}
