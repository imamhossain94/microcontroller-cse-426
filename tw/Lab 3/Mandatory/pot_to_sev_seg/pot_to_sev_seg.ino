int sensorValue, outputValue;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
    
  for(int i=2; i<9; i++){
    pinMode(i,OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(A0);
  outputValue = map(sensorValue, 0, 1023, 0, 15);

  Serial.print((String)"S_v: "+sensorValue);
  Serial.print((String)" O_v: "+outputValue);
  Serial.println();
  delay(500);
  getDigits(outputValue);
  delay(500);
}

void getDigits(int num) {
  if(num==0){
    show(HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,LOW);
  }else if(num==1){
    show(LOW,HIGH,HIGH,LOW,LOW,LOW,LOW);
  }else if(num==2){
    show(HIGH,HIGH,LOW,HIGH,HIGH,LOW,HIGH);
  }else if(num==3){
    show(HIGH,HIGH,HIGH,HIGH,LOW,LOW,HIGH);
  }else if(num==4){
    show(LOW,HIGH,HIGH,LOW,LOW,HIGH,HIGH);
  }else if(num==5){
    show(HIGH,LOW,HIGH,HIGH,LOW,HIGH,HIGH);
  }else if(num==6){
    show(HIGH,LOW,HIGH,HIGH,HIGH,HIGH,HIGH);
  }else if(num==7){
    show(HIGH,HIGH,HIGH,LOW,LOW,LOW,LOW);
  }else if(num==8){
    show(HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH);
  }else if(num==9){
    show(HIGH,HIGH,HIGH,HIGH,LOW,HIGH,HIGH);
  }else if(num==10){
    show(HIGH,HIGH,HIGH,LOW,HIGH,HIGH,HIGH);
  }else if(num==11){
    show(HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH);
  }else if(num==12){
    show(HIGH,LOW,LOW,HIGH,HIGH,HIGH,LOW);
  }else if(num==13){
    show(HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,LOW);
  }else if(num==14){
    show(HIGH,LOW,LOW,HIGH,HIGH,HIGH,HIGH);
  }else if(num==15){
    show(HIGH,LOW,LOW,LOW,HIGH,HIGH,HIGH);
  }
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
