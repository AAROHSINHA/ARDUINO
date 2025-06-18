int redPin = 9;
int bright = 255;
int dim = 50;
int delayB = 200;

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT); // parameters - [what pin we want to use, INPUT or OUTPUT]
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(redPin, bright); // parameters - [what pin to use, what value of VOLTAGE (signal) to send - between 0 and 255]
  delay(delayB);
  analogWrite(redPin, dim);
  delay(delayB);
  // note that 0-255, here 0 stands for 0V but 255 doesnot stand for 255V. 255 repersents 5V
  // 255 is basically 2^8 and 8 bits
  // hence 0 represents 0V and 255 represents 5V
  // so 125 will be around 2.5 Volts
}
