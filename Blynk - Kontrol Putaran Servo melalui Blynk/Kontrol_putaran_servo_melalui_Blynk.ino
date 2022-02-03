/*
 * Wiring :
 * D1 (PWM) -> kabel orange servo
 * Vin -> kabel merah servo
 * GND -> kabel cokelat servo
 */
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

#define BLYNK_PRINT Serial
Servo myservo;

// liat penjelasannya di makerguides.com "how to control servo motors with arduino"
int minimum = 480;
int maximum = 2500;

// Auth Token.
char auth[] = "o2BSMqgczH7HF9GSNJBqCJ-URjdwRC8R";

// Detail WiFi
char ssid[] = "Anline";
char pass[] = "anto2021";

unsigned char slider;

// Membaca nilai dari slider (pint virtual V3)
BLYNK_WRITE(V3) {
  slider = param.asInt();
  myservo.write(slider);
}
void setup() {
  Serial.begin(9600);
  myservo.attach(D1, minimum, maximum);
  Blynk.begin(auth, ssid, pass);
  
}

void loop() {
  Blynk.run();

}
