/* PROJECT CODE FOR CAR PARKING SYSTEM 
   by VIGNESH K S 
   This Code doesnt have Interrupts
   In this Car Parking System only 10 cars can Parking
 */
#include <Servo.h>  //Library file
#include <LiquidCrystal.h>
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Servo myservo1; //create object to control Inway Servo
Servo myservo2; //create object to control Outway Servo
void check();   //function for checking the IR sensors
void display1();
void check1();
void check2();
void check3();
void check4();
int positio=0;  //for angle of Rotation
int IR1 =2;     //Input Sensor
int IR2 =7;     //Output Sensor
int n =0;
void setup() {
  myservo1.attach(5); //5th pin connected to Servo1
  myservo2.attach(6); //6th pin connected to Servo2
  pinMode(IR1,INPUT); //Intialize the Pin as InputMode
  pinMode(IR2,INPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT); 
  pinMode(A4,OUTPUT);
  pinMode(A5,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  lcd.begin(16, 2);
}

void loop() {
  check();
  check1();
  check2();
  check3();
  check4();
  display1();
  if(n==0){
    myservo1.write(180);
    myservo2.write(90);
    lcd.setCursor(0,1);
    lcd.print("Nocars there");  
  }
  else if(n==10){
    myservo1.write(90);
    myservo2.write(180);
    lcd.setCursor(0,1);
    lcd.print("Cars Filled   "); 
  }
  else if(n>=1){
    myservo1.write(180);
    myservo2.write(180); 
    lcd.setCursor(0,1);
    lcd.print("Still U park   ");
  }
}
void check(){
  if(digitalRead(IR1)==1){
    delay(20);
    while(digitalRead(IR1)==1);
    n = n+1;
  }
  else if(digitalRead(IR2)==1){
    delay(20);
    while(digitalRead(IR2)==1);
    n = n-1;
  }
}
void display1(){
  lcd.setCursor(0, 0);
  lcd.print("No.of.carsIN  ");
  lcd.print(n/10);
  lcd.print(n%10);
}
void check1(){
  if(digitalRead(A0) ==1)
    digitalWrite(A4,HIGH);
  else
    digitalWrite(A4,LOW);
  
}
void check2(){
  if(digitalRead(A1) ==1)
    digitalWrite(A5,HIGH);
  else
    digitalWrite(A5,LOW);
  
}
void check3(){
 if(digitalRead(A2) ==1)
    digitalWrite(3,HIGH);
  else
    digitalWrite(3,LOW);
}
void check4(){
 if(digitalRead(A3) ==1)
    digitalWrite(4,HIGH);
  else
    digitalWrite(4,LOW);
}
