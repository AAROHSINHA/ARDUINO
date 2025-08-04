// LED Sensor Line Follower - Threshold Based

const int sensorLeft = A0;
const int sensorCenter = A1;
const int sensorRight = A2;

const int threshold = 500;  // adjust based on testing

void setup() {
  Serial.begin(9600);
}

void loop() {
  int left = analogRead(sensorLeft);
  int center = analogRead(sensorCenter);
  int right = analogRead(sensorRight);

  // Optional: print to debug
  Serial.print("L: ");
  Serial.print(left);
  Serial.print(" C: ");
  Serial.print(center);
  Serial.print(" R: ");
  Serial.println(right);

  // Thresholding logic
  bool leftBlack = left < threshold;
  bool centerBlack = center < threshold;
  bool rightBlack = right < threshold;

  // if(centerBlack) go straight
  // if(leftBlack) turn left
  // if(rightBlack) turn right

  delay(100); // simple delay for stability
}
