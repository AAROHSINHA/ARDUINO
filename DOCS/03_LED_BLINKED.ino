void setup() {
  // as we are working with pin 13, we need to do the pinMode
  pinMode(13, OUTPUT); // parameters - [what pin are we gonna work with, whether the pin is for output or input]
}

void loop() {
  // we want to turn the led on
  digitalWrite(13, HIGH); // parameters - [what pin, HIGH or LOW]
  // as we want to leave it on for a while, let's put a delay of 2 second
  delay(2000);
  // now we will turn it off
  digitalWrite(13, LOW);
  // and again leave it off for 2 seconds so put a delay pf 2 seconds
  delay(2000); 
}
