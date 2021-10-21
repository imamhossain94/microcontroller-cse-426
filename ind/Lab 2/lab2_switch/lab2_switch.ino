int s1in=0;
int s2in=0;
int pivS1=0, pivS2=0;
const int s1=2;
const int s2=3;
const int led=4;
int x = 0, y=0;

void setup() {
  // put your setup code here, to run once:
   pinMode(s1,INPUT);
   pinMode(s2,INPUT);
   pinMode(led,OUTPUT);

   
}

void loop() {

    s1in = digitalRead(s1);
    s2in = digitalRead(s2);
  
  if(pivS1 == s1in && pivS2 == s2in){

      s1in =LOW;
      s2in =LOW;
    
  }else{
    pivS1 = s1in;
   pivS2 =s2in;
  
  if(s1in == LOW && s2in == LOW){
    digitalWrite(led, LOW);

  }else if(s1in == LOW && s2in == HIGH){
    digitalWrite(led, HIGH);
    x = 1000;
  }else if(s1in == HIGH && s2in == LOW){
    digitalWrite(led, HIGH);
    x = 2000;
  }else if(s1in == HIGH && s2in == HIGH){
    digitalWrite(led, HIGH);
    x = 3000;
  }
  }
   
  delay(x);
  digitalWrite(led, LOW);
  delay(x);
}
