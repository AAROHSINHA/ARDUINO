int readPin = A2;
int redPin = 8;
int readVal;
float V_out;
int d = 250;

void setup(){
  pinMode(A2, INPUT);
  pinMode(redPin, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  readVal = analogRead(readPin);
  V_out = (5./1023.)*readVal;
  Serial.print("Potentiometer Voltage is - ");
  Serial.println(V_out);
  if(V_out >= 2.50){
    digitalWrite(redPin, HIGH);
  }
  if(V_out < 2.50){
    digitalWrite(redPin, LOW);
  }
  delay(d);
}
