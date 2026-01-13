	#include <LiquidCrystal.h>
	int rs = 7;
	int en = 8;
	int d4 = 9;
	int d5 = 10;
	int d6 = 11;
	int d7 = 12;
	LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
	
	void setup(){
	  // start the lcd
	  lcd.begin(16, 2); // 16 columns, 2 rows
	
	}
	
	void loop(){
	  // tell the lcd where to put the cursor
	  lcd.setCursor(1, 0);
	  lcd.print("hello world");
	
	
	}
