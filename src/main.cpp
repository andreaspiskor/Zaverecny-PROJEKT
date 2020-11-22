#include <Arduino.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 

const byte cLed = 0;
const byte zLed = 1;
const byte bzucak = 2;
const byte zapis = 3;
const byte vypis = 4;
const int tonyFrekvence = 2000; // Frekvence pípání
int maxVzdalenost = 200; // Od kdy začne pípat 
int vzdalenost; // Vzdálenost
long ; //Jak dlouho bude bzučet
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
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
  lcd.init();
  lcd.backlight();
}

void tlacitka() {
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

}

void mereni(){
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

  
}

void lcdDisplay(){
  lcd.setCursor(2, 0);
  lcd.print("Nazdar!");
  lcd.setCursor(2, 1);
  lcd.print("LCD Display");
}

void loop() {
  tlacitka();
  mereni();
  lcdDisplay();
}

/*
const long interval = 1000;      
void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    digitalWrite(ledPin, ledState);
  }
}
*/