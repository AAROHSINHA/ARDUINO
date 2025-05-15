int pins[] = {3, 6, 9}; // Digital pins connected to LEDs
int dt1 = 100; // LITTLE DELAY FOR SETUP
int dt2 = 10; // delay for voltage change PWM
int dt3 = 1000; // delay before restarting

void setup() {
  // Set all pins as OUTPUT
  for(int pin = 0; pin < 3; pin+=1){
    pinMode(pins[pin], OUTPUT);
  }
  delay(dt1);
}

void loop() {
  for(int pin = 0; pin < 3; pin++){
    for(int i = 0; i < 255; i++){
      analogWrite(pins[pin], i);
      delay(dt2);
    }
    delay(dt3);
  }
  delay(dt3);
}
