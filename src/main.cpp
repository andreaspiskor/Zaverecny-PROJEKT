#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const byte cLed = 0;
const byte zLed = 1;
const byte bzucak = 2;
const byte zapis = 3;
const byte vypis = 4;
const int tonyFrekvence = 2000; // Frekvence pípání
int maxVzdalenost = 210;        // Maximální měřená vzdálenost
int minVzdalenost = 140;        // Minimální měřená vzdálenost
int vzdalenost = 160;           // Vzdálenost, která se může měnit podle libosti uživatele od 150-200 cm
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); //Display který je zapojený na 4 piny a to konstantou 0x27, šířka 16 znaků, výška 2 znaky
const int buttonPin = 5;
const int buttonPin1 = 6;
int vzdalenostTlacitko = 0;
long dobaTrvani;

void setup()
{
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

void tlacitka()
{
  vzdalenost = digitalRead(buttonPin);
  if (vzdalenost != vzdalenostTlacitko)
  {
    if (vzdalenost == HIGH)
    {
      vzdalenost += 10;
      lcd.setCursor(10, 1);
      lcd.print(vzdalenost);
    }
  }
  vzdalenostTlacitko = vzdalenost;

  vzdalenost = digitalRead(buttonPin1);
  if (vzdalenost != vzdalenostTlacitko)
  {
    if (vzdalenost == HIGH)
    {
      vzdalenost -= 10;
      lcd.setCursor(10, 1);
      lcd.print(vzdalenost);
    }
  }
  vzdalenostTlacitko = vzdalenost;
}

void mereni()
{
  digitalWrite(zapis, LOW);
  delayMicroseconds(2);
  digitalWrite(zapis, HIGH);
  delayMicroseconds(10);
  digitalWrite(zapis, LOW);

  dobaTrvani = pulseIn(vypis, HIGH);
  vzdalenost = dobaTrvani * 0.034 / 2;
  if (vzdalenost > vzdalenost - 1 && vzdalenost > minVzdalenost && vzdalenost < maxVzdalenost)
  {
    tone(bzucak, tonyFrekvence);
    digitalWrite(cLed, HIGH);
    digitalWrite(zLed, LOW);
  }
  else
  {
    noTone(bzucak);
    digitalWrite(cLed, LOW);
    digitalWrite(zLed, HIGH);
  }
}

void lcdDisplay()
{
  lcd.setCursor(0, 0);
  lcd.print("Nastav vzdalenost: ");
  lcd.setCursor(10, 1);
  lcd.print(vzdalenost);
}

void loop()
{
  tlacitka();
  mereni();
  lcdDisplay();
}

/*
vzdalenostPred=vzdalenost
vzdalenost + nějaká operace s tím číslem
if(vzdalenostPred > vzdalenost)
  bzucim
else
  nebzucim
HOCHU NEVIM ANI ZA NIC
*/