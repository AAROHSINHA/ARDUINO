int inputNumber; // we will read this number from the serial monitor
String msg = "PLEASE ENTER YOUR NUMBER";
String msg2 = "Your Number Is - ";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  /*
  To get data from the serial - 
    1. ASK
    2. WAIT
    3. READ
  */
  Serial.println(msg);
  while(Serial.available() == 0){
    // while there is no input on the Serial, this loop just runs
    // So basically this just hangs until we write something as input in the serial
    // When we input something, Serial.available() == 1
  
  }
  inputNumber = Serial.parseInt();
  Serial.print(msg2);
  Serial.println(inputNumber);


}
