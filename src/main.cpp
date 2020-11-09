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

void loop() {
  tlacitka();
  mereni();
}

/*
const int ledPin =  LED_BUILTIN;// the number of the LED pin

// Variables will change:
int ledState = LOW;             // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change:
const long interval = 1000;           // interval at which to blink (milliseconds)

void setup() {
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
}
*/