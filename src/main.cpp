#include <Arduino.h>
const byte cLed = 4;
const byte zLed = 5;
const byte bzucak = 8;
const byte zapis = 9;
const byte vypis = 10;
const int tonyFrekvence = 2000; // Frekvence pípání
int maxVzdalenost = 200; // Od kdy začne pípat 
int vzdalenost; // Vzdálenost
long ; //Jak dlouho bude bzučet

void setup() {
  
  pinMode(cLed, OUTPUT);
  pinMode(zLed, OUTPUT);
  pinMode(bzucak, OUTPUT);
  digitalWrite(cLed, HIGH);
  pinMode(zapis, OUTPUT); 
  pinMode(vypis, INPUT); 

}

void loop() {

  digitalWrite(zapis, LOW);
  delayMicroseconds(2);
  
  digitalWrite(zapis, HIGH);
  delayMicroseconds(10);
  digitalWrite(zapis, LOW);
  
  vzdalenost = pulseIn(vypis, HIGH);  
  vzdalenost= vzdalenost*0.034/2;
  
  if (vzdalenost < maxVzdalenost && vzdalenost > 20 ) {
    tone(bzucak, tonyFrekvence);    
    digitalWrite(cLed, HIGH);
    digitalWrite(zLed, LOW);
  } else {
    noTone(bzucak);    
    digitalWrite(cLed, LOW);
    digitalWrite(zLed, HIGH);  
  }

  delay(40);

}