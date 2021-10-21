#include<Keypad.h>
#include<Servo.h>
#include<LiquidCrystal.h>
#define knownPass "1234"
String inputPass;
int i, rs=13, e=12, d4=11, d5=10, d6=9, d7=8;
const int col = 3, row = 4;
char keys[row][col]={
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'},
};
byte pin_row[row] = {3,2,1,0};
byte pin_col[col] = {4,5,6};
Keypad keypad = Keypad(makeKeymap(keys), pin_row, pin_col, row, col);
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);
Servo ms;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  ms.attach(7);
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = keypad.getKey();
  if(key){
    inputPass+=key;
    if(inputPass.equals(knownPass)){
      lcd.print(key);
      lcd.println();
      lcd.print("Welcome");
      delay(100);
      for(i=90; i<=180; i++){
        ms.write(i);
        delay(50);
      }
      delay(200);
      for(i=180; i>=90; i--){
        ms.write(i);
        delay(50);
      }
    }else{
      lcd.print(key);
    }
  }

}
