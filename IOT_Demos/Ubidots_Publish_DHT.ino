

/****************************************
 * Include Libraries
 ****************************************/
#include <WiFi.h>
#include <PubSubClient.h>
#include "DHTesp.h"

#define WIFISSID "Nokia 6" // Put your WifiSSID here
#define PASSWORD "vinu1402" // Put your wifi password here
#define TOKEN "BBFF-MGnknKU4ggVqY56bUuaDlityslx45k" // Put your Ubidots' TOKEN
#define MQTT_CLIENT_NAME "3C:71:BF:4C:8F:C0" // MQTT client Name, please enter your own 8-12 alphanumeric character ASCII string; 
                                           //it should be a random and unique ascii string and different from all other devices

/****************************************
 * Define Constants
 ****************************************/
#define VARIABLE_LABEL "Temperature"
#define VARIABLE_LABEL1 "Humidity"// Assigning the variable label
#define DEVICE_LABEL "ESP" // Assigning the device label

#define SENSOR 4 // Set the GPIO12 as SENSOR
DHTesp dht;
int dhtPin = 17;
char mqttBroker[]  = "things.ubidots.com";
char payload[100];
char topic[150];
// Space to store values to send
char str_sensor[10];
float Temp ;
float Humi ;
char Temp_str[10]; 
char Humi_str[10];

/****************************************
 * Auxiliar Functions
 ****************************************/
WiFiClient ubidots;
PubSubClient client(ubidots);

void callback(char* topic, byte* payload, unsigned int length) {
  char p[length + 1];
  memcpy(p, payload, length);
  p[length] = NULL;
  String message(p);
  Serial.write(payload, length);
  Serial.println(topic);
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.println("Attempting MQTT connection...");
    
    // Attemp to connect
    if (client.connect(MQTT_CLIENT_NAME, TOKEN, "")) {
      Serial.println("Connected");
    } else {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 2 seconds");
      // Wait 2 seconds before retrying
      delay(2000);
    }
  }
}

/****************************************
 * Main Functions
 ****************************************/
void setup() {
  Serial.begin(115200);
  WiFi.begin(WIFISSID, PASSWORD);
  // Assign the pin as INPUT 
  pinMode(SENSOR, INPUT);
  dht.setup(dhtPin, DHTesp::DHT11);

  Serial.println();
  Serial.print("Wait for WiFi...");
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  
  Serial.println("");
  Serial.println("WiFi Connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  client.setServer(mqttBroker, 1883);
  client.setCallback(callback);  
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }

  
  TempAndHumidity newValues = dht.getTempAndHumidity();
  float Temp =  float(newValues.temperature);
  float Humi = float(newValues.humidity);
  sprintf(topic, "%s%s", "/v1.6/devices/", DEVICE_LABEL);
  sprintf(payload, "%s", ""); // Cleans the payload
  sprintf(payload, "{\"%s\":", VARIABLE_LABEL); // Adds the variable label
  
  float sensor = 20;//analogRead(SENSOR); 
  
  /* 4 is mininum width, 2 is precision; float value is copied onto str_sensor*/
  dtostrf(Temp, 4, 2, Temp_str);
  dtostrf(Humi, 4, 2, Humi_str);
  
  sprintf(payload, "%s {\"value\": %s}}", payload, Temp_str);// Adds the value
  Serial.println("Publishing data to Ubidots Cloud");
  
  client.publish(topic, payload);
  client.loop();
  sprintf(payload,"%s", "");
  sprintf(payload, "{\"%s\":", VARIABLE_LABEL1);
  sprintf(payload, "%s {\"value\": %s}}",payload, Humi_str);
  client.publish(topic, payload);
  client.loop();
  delay(1000);
}
