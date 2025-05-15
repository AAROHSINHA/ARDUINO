int readPin = A3;
int V2 = 0;
int delayTime = 500;

void setup(){
  pinMode(readPin, INPUT); // this time as we are reading, we will take an input

  // to print a value
  // we need to setup the serial monitor
  Serial.begin(9600); // so we have setup the serial monitor and we can print to it
}

void loop(){
  // as we are taking analog reading, wuse analogRead
  V2 = analogRead(readPin);
  Serial.println(V2); // println - print at every line
  delay(delayTime);
}
