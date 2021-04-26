#include <Servo.h>  //Library file
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display
Servo myservo1; //create object to control Inway Servo
Servo myservo2; //create object to control Outway Servo
void check();   //function for checking the IR sensors
void display1();
void check1();
void check2();
void check3();
void check4();
int positio=0;  //for angle of Rotation
int IR1 =10;     //Input Sensor
int IR2 =11;     //Output Sensor
int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int n =0;
void setup() {
  myservo1.attach(8); //8th pin connected to Servo1
  myservo2.attach(9); //9th pin connected to Servo2
  lcd.init();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is on
  pinMode(IR1,INPUT); //Intialize the Pin as InputMode
  pinMode(IR2,INPUT);
  lcd.begin(16, 2);
  pinMode(A3,INPUT);
  pinMode(A2,INPUT);
  pinMode(A1,INPUT);
  pinMode(A0,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
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
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Nocars there");  
  }
  else if(n==10){
    myservo1.write(90);
    myservo2.write(180);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Cars Filled   "); 
  }
  else if(n>=1){
    myservo1.write(180);
    myservo2.write(180); 
    lcd.clear();
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
    digitalWrite(led1,HIGH);
  else
    digitalWrite(led1,LOW);
  
}
void check2(){
  if(digitalRead(A1) ==1)
    digitalWrite(led2,HIGH);
  else
    digitalWrite(led2,LOW);
  
}
void check3(){
 if(digitalRead(A2) ==1)
    digitalWrite(led3,HIGH);
  else
    digitalWrite(led3,LOW);
}
void check4(){
 if(digitalRead(A3) ==1)
    digitalWrite(led4,HIGH);
  else
    digitalWrite(led4,LOW);
}
