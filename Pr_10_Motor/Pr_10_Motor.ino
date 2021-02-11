#include<AFMotor.h>
AF_DCMotor motor1(3); //argument --port
void setup() {
  motor1.setSpeed(255);
}

void loop(){
  motor1.run(FORWARD);
  }
