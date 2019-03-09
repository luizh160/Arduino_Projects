//Programa : Teste Módulo Rele Arduino - Botoes
//Autor : FILIPEFLOP
 
//Porta ligada ao pino IN1 do modulo
int porta_rele1 = 7;
//Porta ligada ao botao 1
int porta_botao1 = 2;
 
//Armazena o estado do rele - 0 (LOW) ou 1 (HIGH)
int estadorele1 = 1;
//Armazena o valor lido dos botoes
int leitura1 = 0;
  
void setup()
{
  Serial.begin(9600);
  //Define pinos para o rele como saida
  pinMode(porta_rele1, OUTPUT); 
  //Define pinos dos botoes como entrada
  pinMode(porta_botao1, INPUT); 
  //Estado inicial dos reles - desligados
  digitalWrite(porta_rele1, HIGH);
}
 
void loop()
{
  Serial.println(leitura1);
  //Verifica o acionamento do botao 1
  leitura1 = digitalRead(porta_botao1);
  if (leitura1 != 0)
  {
    while(digitalRead(porta_botao1) != 0)
    {
      Serial.println("botao ligado");
      Serial.println(leitura1);
      Serial.println(estadorele1);
      delay(100);
    }
    //Inverte o estado da porta
    estadorele1 = !estadorele1;
    //Comandos para o rele 1
    digitalWrite(porta_rele1, estadorele1);  
  }   
   
  
}
