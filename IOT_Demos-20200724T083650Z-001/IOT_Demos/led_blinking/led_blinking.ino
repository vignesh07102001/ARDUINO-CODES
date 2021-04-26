int led1=2;
int led2=21;

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(led1,HIGH);
delay(1000);
digitalWrite(led1,LOW);
digitalWrite(led2,HIGH);
delay(1000);
digitalWrite(led2,LOW);
}
