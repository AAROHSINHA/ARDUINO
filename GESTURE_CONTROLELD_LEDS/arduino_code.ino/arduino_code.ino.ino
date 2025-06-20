int ledPins[] = {8, 9, 10, 11, 12};
int dt1 = 50;
int baudrate = 9600;

void ledControl(String fingerStatus){
	for(int i = 0; i < 5; i+=1){
		if(fingerStatus[i] == '1'){
			digitalWrite(ledPins[i], HIGH);
		}else{
			digitalWrite(ledPins[i], LOW);
		}
	}
}

void setup(){
	for(int pin : ledPins){
		pinMode(pin, OUTPUT);
	}
	Serial.begin(baudrate);
	delay(dt1);
}

void loop(){
	tone(1, 440);
	if(Serial.available()){
		if (Serial.available()) {
  String data = Serial.readStringUntil('\n');
  data.trim();  // Remove any whitespace or newlines

  if (data == "NONE" || data.length() != 5) {
    for(int i = 0; i < 5; i+=1){
			digitalWrite(ledPins[i], LOW);  // No hand or bad input
		}
  } else {
    ledControl(data);
  }
}

	}
}
