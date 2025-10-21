int potPIN = A1;
int gPIN = 6;
int portVal;
float ledVal;

void setup(){
  pinMode(potPIN, INPUT);
  pinMode(gPIN, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  portVal = analogRead(potPIN);
  ledVal = (255./1023.)*portVal;
  analogWrite(gPIN, ledVal);
  Serial.println(ledVal);

}
