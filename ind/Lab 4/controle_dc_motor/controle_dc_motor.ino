#define motor_one_ena 9
#define motor_one_input_one 8
#define motor_one_input_two 7

#define motor_two_input_one 6
#define motor_two_input_two 5
#define motor_two_enb 3

#define switch_one_input 10
#define switch_two_input 11

#define sensor_one_input A0
#define sensor_two_input A1

int firstSensorValue, firstSensorOutputValue;
int secondSensorValue, secondSensorOutputValue;
int switchOne, switchTwo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i=0; i<10; i++){
    if(i!=2 && i!=4){
       pinMode(i,OUTPUT); 
    }
  }
  pinMode(switch_one_input,INPUT); 
  pinMode(switch_two_input,INPUT); 
  
}

void loop() {

  firstSensorValue = analogRead(A0);
  firstSensorOutputValue = map(firstSensorValue, 0, 1023, 0, 255);
  secondSensorValue = analogRead(A1);
  secondSensorOutputValue = map(secondSensorValue, 0, 1023, 0, 255);
  
  switchOne = digitalRead(switch_one_input);
  switchTwo = digitalRead(switch_two_input);

  String m1r = (switchOne==HIGH)?" Anti-Clockwise":" Clockwise";
  String m2r = (switchTwo==HIGH)?" Anti-Clockwise":" Clockwise";
  
  Serial.print((String)"Left motor rotation mode: "+ m1r);
  Serial.println();
  Serial.print((String)"Left motor speed: "+ firstSensorOutputValue);
  Serial.println();
  Serial.print((String)"Right motor rotation mode: "+ m2r);
  Serial.println();
  Serial.print((String)"Right motor speed: "+ secondSensorOutputValue);
  Serial.println();
  Serial.println();
  Serial.println();
  motorOne(firstSensorOutputValue, switchOne);
  motorTwo(secondSensorOutputValue, switchTwo);
  delay(1000);
  
}

void motorOne(int rotationSpeed, int rotationMode){
  analogWrite(motor_one_ena, rotationSpeed);
  
  if(rotationMode == HIGH){
    digitalWrite(motor_one_input_one, LOW);
    digitalWrite(motor_one_input_two, HIGH);
  }else{
    digitalWrite(motor_one_input_one, HIGH);
    digitalWrite(motor_one_input_two, LOW);
  }
  
}

void motorTwo(int rotationSpeed, int rotationMode){
  analogWrite(motor_two_enb, rotationSpeed);

  if(rotationMode == HIGH){
    digitalWrite(motor_two_input_one, HIGH);
    digitalWrite(motor_two_input_two, LOW);
  }else{
    digitalWrite(motor_two_input_one, LOW);
    digitalWrite(motor_two_input_two, HIGH);
  }
  
}
