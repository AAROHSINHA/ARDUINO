int greenPIN = 2;
int bluePIN = 4;
int redPIN = 6;
int readPIN = A3;
int dt = 500;
float readVoltage;
float Vout;

void setup(){
  pinMode(greenPIN, OUTPUT);
  pinMode(bluePIN, OUTPUT);
  pinMode(redPIN, OUTPUT);
  pinMode(readPIN, INPUT);
  Serial.begin(9600);
}

void loop(){
  readVoltage = analogRead(readPIN);
  Vout = (5./1023.)*readVoltage;
  Serial.println(Vout);
  if(Vout >= 5.00){
    digitalWrite(redPIN, HIGH);
    digitalWrite(bluePIN, LOW);
    digitalWrite(greenPIN, LOW); 
  }
  if(Vout >= 3 && Vout <= 4){
    digitalWrite(redPIN, LOW);
    digitalWrite(bluePIN, HIGH);
    digitalWrite(greenPIN, LOW); 
  }
  if(Vout < 3){
    digitalWrite(redPIN, LOW);
    digitalWrite(bluePIN, LOW);
    digitalWrite(greenPIN, HIGH); 
  }
}
