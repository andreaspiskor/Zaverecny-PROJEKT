#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
#define DEBUG

const byte buttonInterrupt = 2;
const byte cLed = 4;
const byte zLed = 5;
const byte bzucak = 8;
const byte zapis = 9;
const byte vypis = 10;
const int tonyFrekvence = 500;                          // Frekvence pípání
int maxVzdalenost;                                      // Maximální vzdálenost od objektu
int vzdalenost;                                         // Hodnota, která se měří
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); // Display který je zapojený na 4 piny a to konstantou 0x27, šířka 16 znaků, výška 2 znaky
long dobaTrvani;
int addr = 0;

void increment()                                        
// Funkce pro tlačítko (přidávání hodnoty)
{
  maxVzdalenost = maxVzdalenost + 10;
  if (maxVzdalenost > 200)
  {
    maxVzdalenost = 150;
  }
  EEPROM.put(addr, maxVzdalenost);
}

void setup()
{
  Serial.begin(9600);
  pinMode(buttonInterrupt, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonInterrupt), increment, FALLING);
  pinMode(cLed, OUTPUT);
  pinMode(zLed, OUTPUT);
  pinMode(bzucak, OUTPUT);
  pinMode(zapis, OUTPUT);
  pinMode(vypis, INPUT);
  lcd.init();
  lcd.backlight();
  EEPROM.get(addr, maxVzdalenost);
  Serial.println(maxVzdalenost);
}

void mereni()
// Měření senzoru HC-SR04
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
 // Výpis na LCD
{
  lcd.setCursor(0, 0);
  lcd.print("Vzd: ");
  lcd.setCursor(11, 0);
  lcd.print(vzdalenost);
  lcd.setCursor(0, 1);
  lcd.print("MaxVzd: ");
  lcd.setCursor(11, 1);
  lcd.print(maxVzdalenost);
}

void loop()
{
#if defined(DEBUG)
  Serial.print("Vzdalenost: ");
  Serial.println(vzdalenost);
  Serial.print("MAXVzdalenost: ");
  Serial.println(maxVzdalenost);
#endif

  mereni();
  lcdDisplay();
  delay(500);
}