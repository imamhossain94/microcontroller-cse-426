int sensorValue, outputValue;
String str, haxValue;
char u;
void setup(){
  
  Serial.begin(9600);
  for (int i = 2; i < 9; i++)   {  
    pinMode(i, OUTPUT);  
  }  
  pinMode(12, OUTPUT);  
  pinMode(13, OUTPUT);  

}

void loop(){

  str="";
  sensorValue = analogRead(A0);
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  haxValue = convertToHex(outputValue);
  Serial.println((String)"S_v: "+sensorValue);
  Serial.println((String)"O_v: "+outputValue);
  Serial.println((String)"C_v: "+haxValue);
  Serial.println();

  if(haxValue.length()==1){
    digitalWrite(12, HIGH);  
    digitalWrite(13, LOW);  
    getDigits(0);
    delay(10);  
    digitalWrite(13, HIGH);  
    digitalWrite(12, LOW);
    u = haxValue[0];
    getDigits(hexToInt(u));
  }else{
    digitalWrite(12, HIGH);  
    digitalWrite(13, LOW);  
    u = haxValue[0];
    getDigits(hexToInt(u));
    delay(10);  
    digitalWrite(13, HIGH);  
    digitalWrite(12, LOW);
    u = haxValue[1];
    getDigits(hexToInt(u));
  }
  delay(10);
}

String convertToHex(unsigned int num){
  if (num >= 16){
    convertToHex(num / 16);
  }
  str = String(str+"0123456789ABCDEF"[num % 16]);
  return str;
}

int hexToInt(char u){
  int c = 0;
  if(u=='A'){
    c = 10;
  }else if(u=='B'){
    c = 11;
  }else if(u=='C'){
    c = 12;
  }else if(u=='D'){
    c = 13;
  }else if(u=='E'){
    c = 14;
  }else if(u=='F'){
    c = 15;
  }else{
    c = u-'0';
  }
  return c;
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
