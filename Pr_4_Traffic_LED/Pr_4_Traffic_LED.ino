/*PROBLEM - 4 
 Traffic LIGHT
 red = 10secs
 yellow = 2secs
 red = low

 green = glow
 yellow = low

 yellow = glow
 green = low
 */
int red = 7;
int yellow = 8;
int green =9;
void setup() {
  pinMode(red,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(green,OUTPUT); 
}

void loop() {
  digitalWrite(yellow,LOW);
  digitalWrite(green,LOW);
  digitalWrite(red,HIGH);
  delay(10000);
  digitalWrite(yellow,HIGH);
  delay(2000);
  digitalWrite(green,HIGH);
  digitalWrite(red,LOW);
  digitalWrite(yellow,LOW);
  delay(10000);
  digitalWrite(green,LOW);
  digitalWrite(red,LOW);
  digitalWrite(yellow,HIGH);
  delay(2000);
}
