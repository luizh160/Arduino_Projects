#include <dht.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define dht_dpin A1
dht DHT;
LiquidCrystal_I2C lcd(0x3f, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
byte grau[8] = { B00001100,
                 B00010010,
                 B00010010,
                 B00001100,
                 B00000000,
                 B00000000,
                 B00000000,
                 B00000000,
               };
void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.createChar(0, grau);
}
void loop()
{
  DHT.read11(dht_dpin);
  lcd.setCursor(0, 0);
  lcd.print("temp:");
  lcd.setCursor(5, 0);
  lcd.print(DHT.temperature, 1);
  lcd.setCursor(9, 0);
  lcd.print((char)0);
  lcd.setCursor(0, 1);
  lcd.print("umid:");
  lcd.setCursor(5, 1);
  lcd.print(DHT.humidity, 1);
  lcd.setCursor(9, 1);
  lcd.print("%");
  delay(2000);
}
