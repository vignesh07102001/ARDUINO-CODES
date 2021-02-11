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
 Serial.begin(9600);
}
char val;
void loop() {
  while(Serial.available()>0){
    val = Serial.read();
    Serial.println(val);
  }
  if (val == '1'){
    knightRider();
  }
  else if (val=='2'){
    chaser();
  }
  else if(val =='3'){
     Led5();
  }
  else if(val =='4'){
    Led2();
  }
}
void knightRider(){
    for(int i = 2;i<=9;i++){
    digitalWrite(i,HIGH);
    digitalWrite(i+1,HIGH);
    digitalWrite(i+2,HIGH);
    delay(200);
    digitalWrite(i,LOW);
    digitalWrite(i+1,LOW);
    digitalWrite(i+2,LOW);
    delay(100);
  }
   for(int i=11;i>=4;i--){
    digitalWrite(i,HIGH);
    digitalWrite(i-1,HIGH);
    digitalWrite(i-2,HIGH);
    delay(200);
    digitalWrite(i,LOW);
    digitalWrite(i-1,LOW);
    digitalWrite(i-2,LOW);
    delay(100);
  }
}
void chaser(){
    for(int i = 2;i<=11;i++){
    digitalWrite(i,HIGH);
    delay(100);
    digitalWrite(i,LOW);
    delay(100);
  }
   for(int i=11;i>=2;i--){
    digitalWrite(i,HIGH);
    delay(100);
    digitalWrite(i,LOW);
    delay(100);
  }
}
void Led5(){
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  delay(500);  
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  delay(500);
}
void Led2(){
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  delay(500);  
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  delay(500);
}
