int clockPin = 9;
int latchPin = 11;
int dataPin = 12;

int number;

void setup(){
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  Serial.begin(9600);
}

int returnShifted(int number){
  // arr = {0, 0, 0, 0, 0, 0, 0, 0};
  int arr[] = {0, 0, 0, 0, 0, 0, 0, 0};
  int ind = 7;
  while(number > 0){
    arr[ind] = number%2;
    ind--;
    number/=2;
  }

  // now we have the binary array. So..like 7 = {0, 0, 0, 0, 0, 1, 1, 1}
  // as we wan to left shift, we do it
  for(int i = 1; i < 8; i+=1){
    arr[i - 1] = arr[i];
  }
  arr[7] = 0;

  // now convert the newly found array of binary to the decimal
  int decimals[] = {128, 64, 32, 16, 8, 4, 2, 1};
  int newNum = 0;
  for(int i = 0; i < 8; i++){
    newNum += decimals[i]*arr[i];
  }
  return newNum;

}

void loop(){
  Serial.println("PROVIDE A NUMBER - ");
  while(Serial.available() == 0){
    // wait
  }
  number = Serial.parseInt();
  while(number > 0){
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, number);
    digitalWrite(latchPin, HIGH);
    delay(800);
    number = returnShifted(number);
  }
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, 0x00);
  digitalWrite(latchPin, HIGH);
}
