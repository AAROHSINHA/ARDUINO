// include the libraries required to use the DHT11 sensor 
#include <Adafruit_Sensor.h>
#include <DHT.h>

// declare the type of the sensor. (we can use a lots of sensors with these libraries)
// so we need to specify the type we are currently using
#define Type DHT11

/*
(left)
Vcc - 5/3.3 V
DataPin
Nc - (left unconencted)
Gnd
(right)
*/

// this is the data pin
int sensePin = 2;

// creating the DHT11 object
DHT HT(sensePin, Type); // we need to give it two things - data PIn and the type
float humidity;
float tempC;
float tempF;
int setTime = 500; // just to let the HT set-up in the void setup

void setup(){
  Serial.begin(9600);
  HT.begin(); // we need to start it
  delay(setTime);
}

void loop(){
  humidity = HT.readHumidity();
  tempC = HT.readTemperature();
  tempF = HT.readTemperature(true); // true to read in farhenite (default - false for celcius)
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("\tTemperature (C): ");
  Serial.print(tempC);
  Serial.print("\tTemperature (F): ");
  Serial.println(tempF);
  delay(100);
}
