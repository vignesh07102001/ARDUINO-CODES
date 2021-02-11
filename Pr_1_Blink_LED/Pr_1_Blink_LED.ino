//Problem Statement 1 Blynk an LED using Arduino Uno,Resistor and LED...............
int Led = 13;  //setting 13th Pin to LED 

void setup() {      //setting Pin configurations
pinMode(Led,OUTPUT);
}

void loop() {
/* For OFF LED*/
digitalWrite(Led,LOW);
delay(50);
/*For ON LED*/  
digitalWrite(Led,HIGH);
delay(50);
/*For OFF LED*/
digitalWrite(Led,LOW);
delay(50);
}
