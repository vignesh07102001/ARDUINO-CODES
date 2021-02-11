#include <Servo.h>

Servo name_servo;
int degree =0;
void setup() {
name_servo.attach(10);
delay(50);
}

void loop() {
for(degree =0;degree<=180;degree=degree+1){
  name_servo.write(degree);
  delay(50);
}
for(degree=180;degree>=0;degree=degree-1){
  name_servo.write(degree);
  delay(50);
}
}
