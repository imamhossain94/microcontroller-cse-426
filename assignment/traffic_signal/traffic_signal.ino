int wR = 6, wY = 5, wG = 4, sR = 2, sY = 1, sG = 0;
int sw = 3, i;

void setup() {
  for(i=0; i<=6; i++){
    pinMode(i, i==3?INPUT:OUTPUT);
  }
}

void loop() {
  int s = digitalRead(sw);
  ledConfig(LOW, LOW, HIGH, HIGH, LOW, LOW);
  if(s == HIGH){
    delay(3000);
    ledConfig(LOW, HIGH, LOW, HIGH, LOW, LOW);
    delay(1000);
    ledConfig(HIGH, LOW, LOW, HIGH, LOW, LOW);
    delay(1000);
    ledConfig(HIGH, LOW, LOW, LOW, LOW, HIGH);
    delay(1000);
    ledConfig(HIGH, LOW, LOW, LOW, HIGH, LOW);
    delay(1000);
    ledConfig(HIGH, LOW, LOW, LOW, HIGH, LOW);
    delay(1000);
    ledConfig(HIGH, LOW, LOW, HIGH, LOW, LOW);
    delay(1000);
  }
}

void ledConfig(int wr, int wy, int wg,int sr, int sy, int sg){
  digitalWrite(wR, wr);
  digitalWrite(wY, wy);
  digitalWrite(wG, wg);
  digitalWrite(sR, sr);
  digitalWrite(sY, sy);
  digitalWrite(sG, sg);
}
