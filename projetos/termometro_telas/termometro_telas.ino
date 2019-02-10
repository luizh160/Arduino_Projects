#include <dht.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define dht_dpin A1
dht DHT;
LiquidCrystal_I2C lcd(0x3f, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
int counter = 0;
int botao;
float maxt = 0, maxu = 0;
float mint = 100, minu = 100;
byte grau[8] = { B00001100,
                 B00010010,
                 B00010010,
                 B00001100,
                 B00000000,
                 B00000000,
                 B00000000,
                 B00000000,
               };
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.createChar(0, grau);
  pinMode(2, INPUT_PULLUP);
}
void loop() {
  Serial.println("");
  Serial.print("counter ");
  Serial.println(counter);
  Serial.print("maxt ");
  Serial.println(maxt);
  Serial.print("mint ");
  Serial.println(mint);
  Serial.print("maxu ");
  Serial.println(maxu);
  Serial.print("minu ");
  Serial.println(minu);
  DHT.read11(dht_dpin);
  if (maxt < DHT.temperature) {
    maxt = DHT.temperature;
  }
  if (mint > DHT.temperature) {
    mint = DHT.temperature;
  }
  if (maxu < DHT.humidity) {
    maxu = DHT.humidity;
  }
  if (minu > DHT.humidity) {
    minu = DHT.humidity;
  }
  switch (counter) {
    case 0:
      lcd.clear();
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
      delay(10000);
      break;
    case 1:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("temp max:");
      lcd.setCursor(9, 0);
      lcd.print(maxt, 1);
      lcd.setCursor(13, 0);
      lcd.print((char)0);
      lcd.setCursor(0, 1);
      lcd.print("temp min:");
      lcd.setCursor(9, 1);
      lcd.print(mint, 1);
      lcd.setCursor(13, 1);
      lcd.print((char)0);
      delay(5000);
      break;
    case 2:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("umid max:");
      lcd.setCursor(9, 0);
      lcd.print(maxu, 1);
      lcd.setCursor(13, 0);
      lcd.print("%");
      lcd.setCursor(0, 1);
      lcd.print("umid min:");
      lcd.setCursor(9, 1);
      lcd.print(minu, 1);
      lcd.setCursor(13, 1);
      lcd.print("%");
      delay(5000);
      break;
  }
  botao = digitalRead(2);
  if (botao == 1) {
    if (counter < 2) {
      counter++;
      delay(1000);
    }
    else {
      counter = 0;
      delay(1000);
    }
  }
}
