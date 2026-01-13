#include <LiquidCrystal.h>

int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int number1;
int number2;
char op;
int result;

void setup() {
  lcd.begin(16, 2); // 16 columns, 2 rows
  Serial.begin(9600);
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter Number 1:");
  while (Serial.available() == 0);
  number1 = Serial.parseInt();
  Serial.flush(); // Clear buffer
  lcd.clear();
  lcd.print("num1: ");
  lcd.print(number1);
  delay(1000);

  lcd.clear();
  lcd.print("Enter Number 2:");
  while (Serial.available() == 0);
  number2 = Serial.parseInt();
  Serial.flush();
  lcd.clear();
  lcd.print("num2: ");
  lcd.print(number2);
  delay(1000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(number1);
  lcd.print(" ");
  lcd.print("+"); // Just for clarity
  lcd.print(" ");
  lcd.print(number2);

  lcd.setCursor(0, 1);
  lcd.print("OP (+-/*): ");
  while (Serial.available() == 0);
  op = Serial.read(); // Read single character
  Serial.flush();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(number1);
  lcd.print(" ");
  lcd.print(op);
  lcd.print(" ");
  lcd.print(number2);
  lcd.print(" = ");

  // Perform the operation
  lcd.setCursor(0, 1);
  switch (op) {
    case '+':
      result = number1 + number2;
      break;
    case '-':
      result = number1 - number2;
      break;
    case '*':
      result = number1 * number2;
      break;
    case '/':
      if (number2 != 0) {
        result = number1 / number2;
      } else {
        lcd.print("Error: Div by 0");
        delay(2000);
        return;
      }
      break;
    default:
      lcd.print("Invalid Op");
      delay(2000);
      return;
  }

  lcd.print(result);
  delay(3000); // Pause before next calculation
}
