void setup() {
  // put your setup code here, to run once:

  pinMode(13, OUTPUT); 
}

void loop() {
  digitalWrite(13, HIGH); 
  delay(1000); // how many millisecond we want to delay (1000ms = 1s)
  digitalWrite(13, LOW);
  delay(1000); // how many millisecond we want to delay (1000ms = 1s)
}
