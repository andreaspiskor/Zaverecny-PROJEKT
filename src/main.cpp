#include <Arduino.h>
#include <LiquidCrystal.h>

const byte cLed = 4;
const byte zLed = 5;
const byte bzucak = 8;
const byte zapis = 9;
const byte vypis = 10;
const int tonyFrekvence = 2000; // Frekvence pípání
int maxVzdalenost = 200; // Od kdy začne pípat 
int vzdalenost; // Vzdálenost
long ; //Jak dlouho bude bzučet
LiquidCrystal lcd(7,8,9,10,11,12);
const int  buttonPin = 5;    
const int  buttonPin1 = 6;
int tlacitkoPocitac = 0;  
int tlacitkoHodnota = 0;         
int tlacitkoPosledniHodnota = 0;     
void setup() {
  
  pinMode(cLed, OUTPUT);
  pinMode(zLed, OUTPUT);
  pinMode(bzucak, OUTPUT);
  digitalWrite(cLed, HIGH);
  pinMode(zapis, OUTPUT); 
  pinMode(vypis, INPUT); 
   pinMode(buttonPin, INPUT);
   pinMode(buttonPin1, INPUT);
   lcd.begin(16,2);
   lcd.setCursor(0,1);
   lcd.print("Hodnota měření:");
}

void loop() {
   tlacitkoHodnota = digitalRead(buttonPin);
   if (tlacitkoHodnota != tlacitkoPosledniHodnota) {
     if (tlacitkoHodnota == HIGH)
     {
      tlacitkoPocitac++;
      lcd.setCursor(7,1);
      lcd.print(tlacitkoPocitac);
     }
   }
  tlacitkoPosledniHodnota = tlacitkoHodnota;

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