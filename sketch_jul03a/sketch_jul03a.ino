/*
 * https://circuits4you.com
 * ESP32 LED Blink Example
 * Board ESP23 DEVKIT V1
 * 
 * ON Board LED GPIO 2
 */
#include <WiFi.h>
#include <WebServer.h>
#include <Arduino.h>
#include "wifiThings.h"

#define LED 2
#define GO_PIN 14
#define YEILD_PIN 15
#define STOP_PIN 13

// Web server running on port 80
WebServer server(80);
void connectToWiFi() {
  Serial.print("Connecting to ");
  Serial.println(SSID);
  
  WiFi.begin(SSID, PASS);
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
    // we can even make the ESP32 to sleep
  }
 
  Serial.print("Connected. IP: ");
  Serial.println(WiFi.localIP());
}

// setup API resources
void setup_routing() {
  server.on("/stopOn", StopPinOn);
  server.on("/stopOff", StopPinOff);
  server.on("/yeildOn", YeildPinOn);
  server.on("/yeildOff", YeildPinOff);
  server.on("/goOn", GoPinOn);
  server.on("/goOff", GoPinOff);
 
  // start server
  server.begin();
}

void setup() {
  // Set pin mode
  Serial.begin(115200);
  pinMode(LED,OUTPUT);
  pinMode(GO_PIN,OUTPUT);
  pinMode(YEILD_PIN,OUTPUT);
  pinMode(STOP_PIN,OUTPUT);
  
  randomSeed(analogRead(0));
  connectToWiFi();
  setup_routing();
}

void loop() {
  server.handleClient();
}

void GoPinOn() {
  digitalWrite(GO_PIN,HIGH);
  server.send(200);
}

void GoPinOff() {
  digitalWrite(GO_PIN,LOW);
  server.send(200);
}

void YeildPinOn() {
  digitalWrite(YEILD_PIN,HIGH);
  server.send(200);
}

void YeildPinOff() {
  digitalWrite(YEILD_PIN,LOW);
  server.send(200);
}

void StopPinOn() {
  digitalWrite(STOP_PIN,HIGH);
  server.send(200);
}

void StopPinOff() {
  digitalWrite(STOP_PIN ,LOW);
  server.send(200);
}
