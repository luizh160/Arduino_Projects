const int Potenciometro = 5;
const int Led = 9;
int ValorPoten = 0;
 
void setup() {
  Serial.begin(9600);
pinMode(Led, OUTPUT);
}
 
void loop() {
ValorPoten = analogRead(Potenciometro);
Serial.println(ValorPoten);
digitalWrite(Led, HIGH);
delay(ValorPoten);
digitalWrite(Led, LOW);
delay(ValorPoten);
}
