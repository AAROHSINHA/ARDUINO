#include <LiquidCrystal.h>

int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// responses 
const char* magic8BallResponses[] = {
  // Positive
  "It is certain",
  "Without a doubt",
  "Definitely yes",
  "You can rely on it",
  "As I see it, yes",
  "Most likely",
  "Outlook is good",
  "Yes",
  "Signs point to yes",
  "It is decided",
  // Non-committal
  "Reply hazy, try again",
  "Ask again later",
  "Can't tell you now",
  "Not sure, ask again",
  "Thinking... try again",
  // Negative
  "Don't count on it",
  "My reply is no",
  "Sources say no",
  "Outlook not good",
  "Very doubtful"
};

const int responseCount = sizeof(magic8BallResponses) / sizeof(magic8BallResponses[0]);
long randomIndex = 0;
String DisplayMsg = "Enter Your Question Son (or daughter) - ";
String inputMsg;

void display(int ind){
  String output = magic8BallResponses[ind];
  int len = output.length();
  lcd.setCursor(0, 0);
  for(int i = 0; i < 16; i++){
    if(i >= len) return;
    lcd.print(output[i]);
  }
  lcd.setCursor(0, 1);
  for(int i = 16; i < 32; i++){
    if(i >= len) return;
    lcd.print(output[i]);
  }
}

void setup(){
  lcd.clear();
  lcd.begin(2, 16);
  randomSeed(analogRead(0));
  Serial.begin(9600);
  delay(100);
}

void loop(){
  Serial.println(DisplayMsg);
  while(Serial.available() == 0){}
  lcd.clear();
  inputMsg = Serial.readString();
  delay(500);
  randomIndex = random(0, responseCount);
  display(randomIndex);


}
