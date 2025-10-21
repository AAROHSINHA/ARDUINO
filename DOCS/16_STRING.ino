String myName;
String msg1 = "What is your name? ";
String msg2 = "Hello ";
String msg3 = ", Welcome to Arduino";
int delay1 = 100;
int delay2 = 2000;

void setup(){
  Serial.begin(9600);
}

void loop(){
  // ask -> wait -> read
  Serial.print(msg1);
  delay(delay1);
  while(Serial.available() == 0){
    // HANG AROUND
  }
  // now that we have some input. We will print it
  myName = Serial.readString();
  Serial.print(msg2);
  Serial.print(myName);
  Serial.print(msg3);
  Serial.println("");
  delay(delay2);
}
