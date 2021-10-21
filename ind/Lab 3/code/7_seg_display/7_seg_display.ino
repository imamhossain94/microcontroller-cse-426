void setup() {
  // put your setup code here, to run once:
  for(int i=2; i<9; i++){
    pinMode(i,OUTPUT);
  }

}

void loop() {
  //Zero
  show(HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,LOW);
  delay(1000);
  //Two
  show(HIGH,HIGH,LOW,HIGH,HIGH,LOW,HIGH);
  delay(1000);
  //Four
  show(LOW,HIGH,HIGH,LOW,LOW,HIGH,HIGH);
  delay(1000);
  //Six
  show(HIGH,LOW,HIGH,HIGH,HIGH,HIGH,HIGH);
  delay(1000);
  //Eight
  show(HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH);
  delay(1000);
  //A
  show(HIGH,HIGH,HIGH,LOW,HIGH,HIGH,HIGH);
  delay(1000);
  //C
  show(HIGH,LOW,LOW,HIGH,HIGH,HIGH,LOW);
  delay(1000);
  //E
  show(HIGH,LOW,LOW,HIGH,HIGH,HIGH,HIGH);
  delay(1000);
}

  //          8     7       6      5      4      3      2
void show(int a, int b, int c, int d, int e, int f, int g){
  digitalWrite(2,g);
  digitalWrite(3,f);
  digitalWrite(4,e);
  digitalWrite(5,d);
  digitalWrite(6,c);
  digitalWrite(7,b);
  digitalWrite(8,a);
}
