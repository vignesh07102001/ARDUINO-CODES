//Knight Rider 
void setup() {
 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(6,OUTPUT);
 pinMode(7,OUTPUT);
 pinMode(8,OUTPUT);
 pinMode(9,OUTPUT);
 pinMode(10,OUTPUT);
 pinMode(11,OUTPUT);
 pinMode(12,OUTPUT);
 pinMode(13,OUTPUT);
}

void loop() {
  for(int i = 2;i<=13;i++){
    digitalWrite(i,HIGH);
    digitalWrite(i+1,HIGH);
    digitalWrite(i+2,HIGH);
    delay(100);
    digitalWrite(i,LOW);
    digitalWrite(i+1,LOW);
    digitalWrite(i+2,LOW);
  }
   for(int i=13;i>=2;i--){
    digitalWrite(i,HIGH);
    digitalWrite(i+1,HIGH);
    digitalWrite(i+2,HIGH);
    delay(100);
    digitalWrite(i,LOW);
    digitalWrite(i+1,LOW);
    digitalWrite(i+2,LOW);
  }
}
