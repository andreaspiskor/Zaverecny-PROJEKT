#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

<<<<<<< HEAD
const byte cLed = 4;
const byte zLed = 5;
const byte bzucak = 8;
const byte zapis = 9;
const byte vypis = 10;
const int tonyFrekvence = 200; // Frekvence pípání
int maxVzdalenost = 100;        // Maximální měřená vzdálenost
int vzdalenost;           // Vzdálenost, která se může měnit podle libosti uživatele
=======
const byte cLed = 8;
const byte zLed = 9;
const byte bzucak = 2;
const byte zapis = 3;
const byte vypis = 4;
const int tonyFrekvence = 2000; // Frekvence pípání
int maxVzdalenost = 210;        // Maximální měřená vzdálenost
int minVzdalenost = 140;        // Minimální měřená vzdálenost
int vzdalenost;           // Vzdálenost, která se může měnit podle libosti uživatele od 150-200 cm
>>>>>>> dde5d74fe1fc8f76321dff5f845e14f6729e48ff
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); //Display který je zapojený na 4 piny a to konstantou 0x27, šířka 16 znaků, výška 2 znaky
const int buttonPin = 2;
const int buttonPin1 = 3;
int vzdalenostTlacitko = 0;
long dobaTrvani;

void setup()
{
  Serial.begin(9600);
  pinMode(cLed, OUTPUT);
  pinMode(zLed, OUTPUT);
  pinMode(bzucak, OUTPUT);
  //digitalWrite(cLed, HIGH);
  pinMode(zapis, OUTPUT);
  pinMode(vypis, INPUT);
//  pinMode(buttonPin, INPUT);
//  pinMode(buttonPin1, INPUT);
  lcd.init();
  lcd.backlight();
}
/*
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
*/
void mereni()
{
  digitalWrite(zapis, LOW);
  delayMicroseconds(2);
  digitalWrite(zapis, HIGH);
  delayMicroseconds(10);
  digitalWrite(zapis, LOW);

  dobaTrvani = pulseIn(vypis, HIGH);
  vzdalenost = dobaTrvani * 0.034 / 2;
<<<<<<< HEAD
  if (vzdalenost < maxVzdalenost)
=======
  // if (vzdalenost > vzdalenost - 1 && vzdalenost > minVzdalenost && vzdalenost < maxVzdalenost)
  if (maxVzdalenost < vzdalenost)
>>>>>>> dde5d74fe1fc8f76321dff5f845e14f6729e48ff
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
  lcd.print(maxVzdalenost);
}

void loop()
{
<<<<<<< HEAD
//  tlacitka();
=======
  //tlacitka();
>>>>>>> dde5d74fe1fc8f76321dff5f845e14f6729e48ff
  Serial.println("Vzdalenost:");
  Serial.println(vzdalenost);
  mereni();
  lcdDisplay();
<<<<<<< HEAD
  delay(500);
=======
  delay(1000);
>>>>>>> dde5d74fe1fc8f76321dff5f845e14f6729e48ff
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