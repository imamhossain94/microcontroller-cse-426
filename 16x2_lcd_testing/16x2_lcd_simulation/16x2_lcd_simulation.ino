#include <LiquidCrystal.h>


//GPS
#include <SoftwareSerial.h>
#include <TinyGPS++.h>
SoftwareSerial ss(2,3);
TinyGPSPlus gps;



//LCD
#define rs 9 
#define en 8 
#define d4 7 
#define d5 6  
#define d6 5 
#define d7 4 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

char inputByte;
void setup() {
  Serial.begin(9600);
  pinMode(10,OUTPUT);
  lcd.begin(16, 2);
//  lcd.print("Lal Vai");

  //  Connect Gps
  ss.begin(9600); 

  
}


String lng = "", lat = "";
 
void loop() {


//Bluetooth
//while(Serial.available()>0){
//  inputByte= Serial.read();
//  Serial.println(inputByte);
//  if (inputByte=='A'){
//    lcd.setCursor(3,1); 
//    lcd.print("Seconds"); 
//    tone(10,200);
//    delay(500);
//  }
//  else if (inputByte=='B'){
//    lcd.setCursor(3,1); 
//    lcd.print("Minutes");
//    noTone(10);
//    delay(500);
//  } 
//}

//LCD
//  lcd.setCursor(3,1); 
//  lcd.print("Seconds"); 
//  lcd.setCursor(0, 1);
//  lcd.print(millis()/1000);
//  delay(500);


//Gps
  while (ss.available() > 0){
    //Serial.write(ss.read());
    gps.encode(ss.read());
    if (gps.location.isUpdated()){
      //Serial.write("Latitude= "); 
      lat = String(gps.location.lat(), 6);
      //Serial.print(gps.location.lat(), 6);
      //Serial.print(" Longitude= "); 
      lng = String(gps.location.lng(), 6);
      //Serial.println(gps.location.lng(), 6);
    }
    //Serial.println(String(gps.location.lat(), 6)+";"+String(gps.location.lng(), 6));
  }
  
//  String latitude = String(lat,6);
//  String longitude = String(lon,6);
//  //Serial.println(latitude+";"+longitude);
  Serial.println();
  Serial.println(lat+";"+lng);
  lcd.setCursor(0, 0);
  lcd.println(lat);
  lcd.setCursor(0, 1);
  lcd.println(lng);
  delay(500);

}
