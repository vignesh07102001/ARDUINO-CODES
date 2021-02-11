/*PROBLEM -2 red & Yellow - 10times
             Red & Green  - 10times
             Yellow & Green - 10times
             Red & Yellow & Green - 10times
 */
 int red = 11;
 int yellow = 12;
 int green = 13;
void setup() {
  pinMode(red,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(green,OUTPUT);
}
void loop() {
  for(int i=0;i<=10;i++){
    digitalWrite(red,HIGH);
    digitalWrite(yellow,HIGH);
    digitalWrite(green,LOW);
    delay(100);
    digitalWrite(red,LOW);
    digitalWrite(yellow,LOW);
    digitalWrite(green,LOW);
    delay(100);
  }
  for(int i=0;i<=10;i++){
    digitalWrite(red,LOW);
    digitalWrite(yellow,HIGH);
    digitalWrite(green,HIGH);
    delay(100);
    digitalWrite(red,LOW);
    digitalWrite(yellow,LOW);
    digitalWrite(green,LOW);
    delay(100);
  }
  
  for(int i=0;i<=10;i++){
    digitalWrite(red,HIGH);
    digitalWrite(yellow,LOW);
    digitalWrite(green,HIGH);
    delay(100);
    digitalWrite(red,LOW);
    digitalWrite(yellow,LOW);
    digitalWrite(green,LOW);
    delay(100);
  }
  
  for(int i=0;i<=10;i++){
    digitalWrite(red,HIGH);
    digitalWrite(yellow,HIGH);
    digitalWrite(green,HIGH);
    delay(100);
    digitalWrite(red,LOW);
    digitalWrite(yellow,LOW);
    digitalWrite(green,LOW);
    delay(100);
  }

}
