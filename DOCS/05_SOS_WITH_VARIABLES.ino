// variables are declared before the void setup(){}
int redLED = 8;
int dit = 100;
int dah = 500;
int longWait = 1000;

void setup() {
  // Because the positive terminal of LED is connected to port redLED, we add pin
  pinMode(redLED, OUTPUT);
}

void loop() {
  // S - O - S
  // First S
  digitalWrite(redLED, HIGH);
  delay(dit);
  digitalWrite(redLED, LOW);
  delay(dit);
  digitalWrite(redLED, HIGH);
  delay(dit);
  digitalWrite(redLED, LOW);
  delay(dit);
  digitalWrite(redLED, HIGH);
  delay(dit);
  digitalWrite(redLED, LOW);
  delay(dit);

  delay(longWait);

  // O
  digitalWrite(redLED, HIGH);
  delay(2000);
  digitalWrite(redLED, LOW);
  delay(dah);
  digitalWrite(redLED, HIGH);
  delay(2000);
  digitalWrite(redLED, LOW);
  delay(dah);
  digitalWrite(redLED, HIGH);
  delay(2000);
  digitalWrite(redLED, LOW);
  delay(dah);

  delay(longWait);

  // Second S
   digitalWrite(redLED, HIGH);
  delay(dit);
  digitalWrite(redLED, LOW);
  delay(dit);
  digitalWrite(redLED, HIGH);
  delay(dit);
  digitalWrite(redLED, LOW);
  delay(dit);
  digitalWrite(redLED, HIGH);
  delay(dit);
  digitalWrite(redLED, LOW);
  delay(dit);

  delay(longWait);
}
