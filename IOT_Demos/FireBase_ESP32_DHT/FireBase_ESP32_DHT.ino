#include <WiFi.h>                                                // esp32 librar
#include <IOXhop_FirebaseESP32.h>  
#define FIREBASE_HOST "https://******.firebaseio.com/"                         // the project name address from firebase id
#define FIREBASE_AUTH "XXXXXxxxxxxxxxxxxx"                    // the secret key generated from firebase
#define WIFI_SSID "XXXXXXXXX"                                          // input your home or public wifi name
#define WIFI_PASSWORD "YYYYYYY"                                    //password of wifi ssid
String a = " ";
String b = " ";
String c = " ";
void setup() {
  pinMode(13,OUTPUT);   //left motors forward
  pinMode(12,OUTPUT);   //left motors reverse
  pinMode(14,OUTPUT);   //right motors forward
  pinMode(27,OUTPUT);   //right motors reverse
  pinMode(26,OUTPUT);   //water spray
  pinMode(25,OUTPUT);   //cleaner motor


  Serial.begin(9600);

  delay(1000);                

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                      //try to connect with wifi

  Serial.print("Connecting to ");

  Serial.print(WIFI_SSID);

  while (WiFi.status() != WL_CONNECTED) {

    Serial.print(".");

    delay(500);

  }

  

  Serial.println();

  Serial.print("Connected to ");

  Serial.println(WIFI_SSID);

  Serial.print("IP Address is : ");

  Serial.println(WiFi.localIP());                                                      //print local IP address

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); //connect to firebase

}

void loop() {
  a = Firebase.getString("floorcleaner/variable1");
  b = Firebase.getString("floorcleaner/variable2");
  c = Firebase.getString("floorcleaner/variable3");
  if(a == "F"){
    digitalWrite(12,LOW);
    digitalWrite(27,LOW); 
    digitalWrite(13,HIGH);
    digitalWrite(14,HIGH);
  }
  else if(a == "B"){
    digitalWrite(13,LOW);
    digitalWrite(14,LOW); 
    digitalWrite(12,HIGH);
    digitalWrite(27,HIGH);
  }
  else if(a == "L"){
    digitalWrite(13,LOW);
    digitalWrite(14,LOW); 
    digitalWrite(12,LOW);
    digitalWrite(27,HIGH);
  }
   else if(a == "R"){
    digitalWrite(27,LOW);
    digitalWrite(14,LOW); 
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
  }
   else if(a == "S"){
    digitalWrite(27,LOW);
    digitalWrite(14,LOW); 
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
  }
  if (b == "on"){
    digitalWrite(26,HIGH);
  }
  }
