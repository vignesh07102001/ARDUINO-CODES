/* PROBLEM - 3 morse sos code
       one LED
       blink time - 150 HIGH
                    100 LOW
       Second Blink - 400 HIGH
                      100 LOW
       Third Blink - 150 HIGH
                     100 LOW
 */
int LED = 8;
void setup() {
  pinMode(LED,OUTPUT);  
}

void loop() {
  digitalWrite(LED,HIGH);
  delay(150);
  digitalWrite(LED,LOW);
  delay(100);
  digitalWrite(LED,HIGH);
  delay(400);
  digitalWrite(LED,LOW);
  delay(100);
  digitalWrite(LED,HIGH);
  delay(150);
  digitalWrite(LED,LOW);
  delay(100);
}
