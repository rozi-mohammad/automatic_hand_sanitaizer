

#define trigPin 3
#define echoPin 2

int relay = 4;
int relayON = LOW;


int relayOFF = HIGH;


void setup() {
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(relay, OUTPUT);
pinMode(trigPin, OUTPUT);
}
void loop() {
long duration, distance;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;

if (distance < 15) {
 // delay(5000);
Serial.println("the distance is less than 10");
digitalWrite(relay, relayON);
delay(50);
digitalWrite(relay, relayOFF);
delay(5000);

}
else {
digitalWrite(relay, relayOFF);
delay(1000);
}
if (distance > 60 || distance <= 0){
Serial.println("The distance is more than 60");
}
else {
Serial.print(distance);
Serial.println(" cm");
}
delay(100);
}
