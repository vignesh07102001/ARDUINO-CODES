int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
char val;
void setup() {
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);
Serial.begin(9600);
}

void loop() {
  while(Serial.available()>0){
    val = Serial.read();
    Serial.println(val);
  }
if(val == '1'){
  digitalWrite(led1,HIGH);
  }
  else if(val == '2'){
    digitalWrite(led2,HIGH);
  }
  else if(val == '3'){
    digitalWrite(led3,HIGH);
  }
   else if(val == '4'){
    digitalWrite(led4,HIGH);
  }
  else if(val == '5'){
  digitalWrite(led1,LOW);
  }
  else if(val == '6'){
    digitalWrite(led2,LOW);
  }
  else if(val == '7'){
    digitalWrite(led3,LOW);
  }
   else if(val == '8'){
    digitalWrite(led4,LOW);
  }
}
