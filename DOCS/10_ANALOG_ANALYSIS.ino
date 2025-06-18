int readPin = A2; // we read input through this pin
int outputV;
int V_out;
int delayTime = 500;

void setup(){
  // parameters - [pin number we are operating on, INput or OUtput that pin takes?] 
  pinMode(readPin, INPUT); 

  // setting up serial to display result
  Serial.begin(9600);
}

void loop(){
  outputV = analogRead(readPin); // This pin reads the output V at different points, 
  // where the other ends of readPin is connected
  V_out = (5./1023.)*outputV;
  Serial.println(V_out);
  delay(delayTime);
}
