int ledPin =13;
int inputpin = 2;
int motion = LOW;
int stat = 0;
void setup() {
pinMode(ledPin,OUTPUT);
pinMode(inputpin,INPUT);
}

void loop() {
if((digitalRead(inputpin))== 1){
  digitalWrite(13,LOW);
  motion = HIGH;
}
else{
  digitalWrite(13,HIGH);
  motion = LOW;
}
}
