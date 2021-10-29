#include <LiquidCrystal.h>

#define rs 9 
#define en 8 
#define d4 7 
#define d5 6  
#define d6 5 
#define d7 4 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
 
void setup() {
  lcd.begin(16, 2);
  lcd.print("Lal Vai");
}
 
void loop() {
  lcd.setCursor(3,1); 
  lcd.print("Seconds"); 
 
  lcd.setCursor(0, 1);
  lcd.print(millis()/1000);
  delay(500);
}
