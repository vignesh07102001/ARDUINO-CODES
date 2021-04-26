#define trigPin 23 // Trigger Pin of Ultrasonic Sensor
#define echoPin 22 // Echo Pin of Ultrasonic Sensor

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   
}

void loop() {
   long duration, cm;
   pinMode(trigPin, OUTPUT);
   digitalWrite(trigPin, LOW);
   delayMicroseconds(5);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   cm = duration / 29 / 2;
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   delay(100);
}
