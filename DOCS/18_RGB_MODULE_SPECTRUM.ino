int redPin = 8;
int greenPin = 9;
int bluePin = 10;
int d = 500;

void setup(){
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop(){
  // red - green - blue - magenta
  // red
  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
  delay(d);
  // green
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, HIGH);
  digitalWrite(bluePin, LOW);
  delay(d);
  // blue
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, HIGH);
  delay(d);
  /// magenta
  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, LOW);
  analogWrite(bluePin, 125);
  delay(d);
  // cyan 
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, HIGH);
  analogWrite(bluePin, 125);
  delay(d);
  // orange
  analogWrite(redPin, 255); 
  analogWrite(greenPin, 165);
  analogWrite(bluePin, 45);
  delay(d);
}
