int redPin = 8;
int greenPin = 9;
int bluePin = 10;
String myColor;
String msg = "What color do you want - (R/G/B) - ";
int d1 = 100;
int d2 = 3000;

void setup(){
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  // input --> ask - wait - get
  Serial.print(msg);
  delay(d1);
  while(Serial.available() == 0){
    // HANG AROUND
  }
  myColor = Serial.readString();
  if(myColor == "r" || myColor == "R"){
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  }else if(myColor == "g" || myColor == "G"){
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);
  }else if(myColor ==  "b" || myColor == "B"){
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);
  }else{
    Serial.println("PLEASE CHOOSE ONE OF R,r/G,g/B,b!!");
  }
  Serial.println("");
  delay(d2);

}
