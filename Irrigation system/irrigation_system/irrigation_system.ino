#include <Wire.h>

#define BLYNK_PRINT Serial   
#include <SPI.h>
#include<Adafruit_Sensor.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#include <DallasTemperature.h>
#include <OneWire.h>
#include <DHT.h>
OneWire oneWire D2;
DallasTemperature sensors(&oneWire);
char auth[] ="your auth token"; 
char ssid[] = "your wifi name"; 
char pass[] = "your wifi password"; 
#define DHTPIN 2    
#define DHTTYPE DHT11     
DHT dht(DHTPIN, DHTTYPE);
SimpleTimer timer;
void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
 
  Blynk.virtualWrite(V5, h);  //V5 is for Humidity
  Blynk.virtualWrite(V6, t);  //V6 is for Temperature
}
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
   
  dht.begin();

  timer.setInterval(1000L, sendSensor);
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
   sensors.begin();
}
int sensor=0;
void sendTemps()
{
sensor=analogRead(A0);
sensors.requestTemperatures();
float temp = sensors.getTempCByIndex(0); 
Serial.println(temp);
Serial.println(sensor);
Blynk.virtualWrite(V1, temp);
Blynk.virtualWrite(V2,sensor);
delay(1000);
}
void loop()
{
  Blynk.run(); 
  timer.run(); 
  sendTemps();
}
