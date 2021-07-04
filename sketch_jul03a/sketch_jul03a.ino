/*
 * https://circuits4you.com
 * ESP32 LED Blink Example
 * Board ESP23 DEVKIT V1
 * 
 * ON Board LED GPIO 2
 */
#define LED 2
#define GO_PIN 13
#define YEILD_PIN 14
#define STOP_PIN 15



void setup() {
  // Set pin mode
  pinMode(LED,OUTPUT);
  pinMode(GO_PIN,OUTPUT);
  pinMode(YEILD_PIN,OUTPUT);
  pinMode(STOP_PIN,OUTPUT);
  
  randomSeed(analogRead(0));
}

void loop() {
 // delay(500);
  //digitalWrite(LED,HIGH);
  
  GoPinOn();
  delay(random(10000,30000));
  GoPinOff();
  YeildPinOn();
  delay(random(10000,30000));
  YeildPinOff();
  StopPinOn();
  delay(random(15000,45000));
  StopPinOff();
 // delay(500);
 // digitalWrite(LED,LOW);
}

void GoPinOn() {
  digitalWrite(GO_PIN,HIGH);
}

void GoPinOff() {
  digitalWrite(GO_PIN,LOW);
}

void YeildPinOn() {
  digitalWrite(YEILD_PIN,HIGH);
}

void YeildPinOff() {
  digitalWrite(YEILD_PIN,LOW);
}

void StopPinOn() {
  digitalWrite(STOP_PIN,HIGH);
}

void StopPinOff() {
  digitalWrite(STOP_PIN ,LOW);
}
