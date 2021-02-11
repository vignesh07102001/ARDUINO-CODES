int r = 3;
int y1 = 5;
int y2 = 6;
void setup() {
  pinMode(r,OUTPUT);
  pinMode(y1,OUTPUT);
  pinMode(y2,OUTPUT);
}

void loop() {
  analogWrite(r,random(120)+135);
  analogWrite(y1,random(120)+135);
  analogWrite(y2,random(120)+135);
  delay(random(100));
}
