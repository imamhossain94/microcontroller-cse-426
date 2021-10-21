#include<Servo.h>
Servo msl;
Servo msr;
int i;
bool isOpened;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  msl.attach(8);
  msr.attach(7);
  pinMode(2, INPUT);
  isOpened = false;
  msl.write(180); 
  msr.write(0);
}

void loop() {
  Serial.print((String)"Starting... ");
  if(digitalRead(2) == LOW && isOpened == false) {
    Serial.println("Closing: wet"); 
    msl.write(180); 
    msr.write(0);
    isOpened = true;
  }else if(digitalRead(2) == HIGH && isOpened == true){
    Serial.println("Opening: dry");
    msl.write(45); 
    msr.write(135);
    isOpened = false;
  }  
  Serial.println();
  delay(500);
}
