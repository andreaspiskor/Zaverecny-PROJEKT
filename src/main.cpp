#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const byte cLed = 4;
const byte zLed = 5;
const byte bzucak = 8;
const byte zapis = 9;
const byte vypis = 10;
const int tonyFrekvence = 500; // Frekvence pípání
int maxVzdalenost = 100;        // Maximální měřená vzdálenost
int vzdalenost;           // Vzdálenost, která se může měnit podle libosti uživatele
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); //Display který je zapojený na 4 piny a to konstantou 0x27, šířka 16 znaků, výška 2 znaky
int vzdalenostTlacitko = 0;
long dobaTrvani;

void setup()
{
  Serial.begin(9600);
  pinMode(cLed, OUTPUT);
  pinMode(zLed, OUTPUT);
  pinMode(bzucak, OUTPUT);
  pinMode(zapis, OUTPUT);
  pinMode(vypis, INPUT);
  lcd.init();
  lcd.backlight();
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
  if (vzdalenost < maxVzdalenost)
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
  lcd.print("Vypis hodnoty: ");
  lcd.setCursor(10, 1);
  lcd.print(vzdalenost);
}

void loop()
{
  Serial.println("Vzdalenost:");
  Serial.println(vzdalenost);
  mereni();
  lcdDisplay();
  delay(500);
}

//DISPLAY IS OUT (BE IN THE CLOUD NINE)