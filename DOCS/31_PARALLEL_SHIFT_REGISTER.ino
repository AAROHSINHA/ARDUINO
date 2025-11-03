int latchPin = 11;
int clockPin = 9;
int dataPin = 12;

// setting up a hex pin
/*
1. We have 8 leds. If we want all of them on, we need
1 1 1 1 | 1 1 1 1
  F       F
*/
byte LEDs_on = 0xFF; // we will send this to serial to parallel converted 

/*
2. We have 8 leds. If we want all of them on, we need
0 0 0 0 | 0 0 0 0 
  0         0
*/
byte LEDs_off = 0x00;

// setting up with binary
byte LEDs_bin1 = 0b10101010;
byte LEDs_bin2 = 0b11001100;


void setup(){
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  // when we need to send data to the register, we need the latch pin low..right?
  // so we make it low first
  digitalWrite(latchPin, LOW);
  // now that it is low, we want the arduino to send out the data to the register
  shiftOut(dataPin, clockPin, LSBFIRST, LEDs_bin2); // [what pin we want to send data in arduino, clockPin, least significant/most significant bit first, what data to send]
  // this above command ensures the function of storage register clock pin and how it will sync the data. We only need to write that command
  // and not worry about how it works anymore

  // now that data is sent, send the latch pin to high
  digitalWrite(latchPin, HIGH);

}
