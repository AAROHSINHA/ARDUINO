int trigPin = 12;
int echoPin = 11;
int pingTravelTime; // we will be reading this as a value

void setup(){
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop(){
  // we want to create a low-high-low... pulse on the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // pulse generated
  // now this just sends the echo to high and it will send echo high until we get some object (means it detects something at a distance) 

  // the pingTravelTime measures how long it takes to detect the echo (collision)
  pingTravelTime = pulseIn(echoPin, HIGH);
  Serial.println(pingTravelTime);

  /*
  1. pingTravelTime goes up when we move the target further
  2. pingTravelTime goes down when we move the target closer
  (obvious)
  */
  
  delay(250);

}
