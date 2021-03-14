#include "FirebaseESP8266.h"  // Install Firebase ESP8266 library
#include <ESP8266WiFi.h>
#define FIREBASE_HOST "https://automaticfloorcleaner-default-rtdb.firebaseio.com/" 
#define FIREBASE_AUTH "pZU7dC2youR1HDB8s23DlLLbI7rCiLxdXy6a7Ph6"
#define WIFI_SSID "Mani's A50"
#define WIFI_PASSWORD "........"
//Define FirebaseESP8266 data object
FirebaseData firebaseData;
void backward();
void forward();
void left();
void right();
FirebaseData t;
FirebaseData r;
FirebaseData Waterpump;

FirebaseJson json;

void setup(){
  Serial.begin(9600);
  pinMode(2,OUTPUT);  //Right Motor
  pinMode(5,OUTPUT);   //Right MOtor
  pinMode(4,OUTPUT);   //Left Motor
  pinMode(0,OUTPUT);   //Left Motor
  pinMode(13,OUTPUT);  //Cleaning Motor
  pinMode(15,OUTPUT);  //WaterPump
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
}
void loop(){

  if (Firebase.getString(Waterpump,"/floorcleaner/pump")){
    if(Waterpump.stringData() == "1"){

      digitalWrite(15,HIGH);
    }
    else if(Waterpump.stringData() == "0"){
      digitalWrite(15,LOW);
    }
  }
  if (Firebase.getString(t,"/floorcleaner/movement")){
    if (Firebase.getString(r,"/floorcleaner/movement1")){
      if ((t.stringData()=="0")&&(r.stringData()=="0")){
        digitalWrite(2,LOW);
        digitalWrite(5,LOW);
        digitalWrite(4,LOW);
        digitalWrite(0,LOW);
  
      }
      if ((t.stringData()=="1")&&(r.stringData()=="0")){
        forward();
      }
       if ((t.stringData()=="2")&&(r.stringData()=="0")){
       backward();
      }
       if ((t.stringData()=="1")&&(r.stringData()=="1")){
       left();
      }
      if ((t.stringData()=="1")&&(r.stringData()=="2")){
       right();
      }
    }
  }
}
void forward(){
  digitalWrite(2,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(0,LOW);
  
}
void backward(){
  digitalWrite(2,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(0,HIGH);
  }
 void left(){
  digitalWrite(2,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(4,LOW);
  digitalWrite(0,LOW);
 }
  void right(){
  digitalWrite(2,LOW);
  digitalWrite(5,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(0,LOW);
 }
