int numBlinks;
String msg = "How Many Blinks Do You Want";
int redPin = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(msg);
  delay(100);
  while(Serial.available() == 0){
    // hang around
  }
  numBlinks = Serial.parseInt();
  for(int i = 0; i < numBlinks; i++){
      digitalWrite(redPin, HIGH);
      delay(500);
      digitalWrite(redPin, LOW);
      delay(500);
  }



}
