int bluePin = 8;
int redPin = 10;
int blueTime = 500;
int redTime = 500;
int blueBlink = 3;
int redBlink = 5;
int j;

void setup() {
  // put your setup code here, to run once:
  pinMode(bluePin, OUTPUT);
  pinMode(redPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // blue blink
  for(j = 0; j < blueBlink; j+=1){
  digitalWrite(bluePin, HIGH);
  delay(blueTime);
  digitalWrite(bluePin, LOW);
  delay(blueTime);
  }

  // red blink
  for(j = 0; j < redBlink; j+=1){
  digitalWrite(redPin, HIGH);
  delay(redTime);
  digitalWrite(redPin, LOW);
  delay(redTime);
  }

}
