#include <Blynk.h>

// http://arduino.esp8266.com/stable/package_esp8266com_index.json

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;
char auth[] = "CQN1osCrav7U4GPtW_UZzf2PNexygbYt";

char ssid[] = "Rorostyle";  // Type your wifi name
char pass[] = "r@w@nhEsh@m";  // Type your wifi password

#define trig D5   // Trig pin
#define echo D6   // Echo Pin 
long duration, inches, cm;
void notify()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long t = pulseIn(echo, HIGH);
  long cm = t / 29 / 2;
  Serial.println(cm);
  long level= 12-cm; // Change 15 according to your tank depth
  if (level<0)
  level=0;
  Blynk.virtualWrite(V1, level);
}
void setup()
{
 pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(115200);
Blynk.begin(auth, ssid, pass);
timer.setInterval(100L,notify); 
}
void loop()
{
  Blynk.run();
  timer.run();
}
