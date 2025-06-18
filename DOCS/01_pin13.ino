void setup() {
  // put your setup code here, to run once:

  // tell arduino we will work with pin 13
  pinMode(13, OUTPUT); // parameters - [which pin are we working with, if we will use pin as an input or output]
  // as we want the led connected to the pin 13 to glow, we are sending signal to it...hence it is an output
}

void loop() {
  // put your main code here, to run repeatedly:

  // to turn led on, we want to send a signal to it
  digitalWrite(13, HIGH); // parameters - [what pin are we working with, if we wanna turn on or off]
  // to turn on - command is HIGH, as we send
}
