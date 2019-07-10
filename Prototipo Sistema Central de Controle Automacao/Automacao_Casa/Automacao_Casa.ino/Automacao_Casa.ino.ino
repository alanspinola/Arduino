/* Nome:  Programa Automação Casa 
   Autor: Alan Spinola 
   Data:  07/07/2019
   Versão: 1.1 - Arduino UNO - C++ (Ver1.1)
*/

// INCLUSÃO DE BIBLIOTECAS
#include <IRremote.h> // Biblioteca para controle IR
#include <stdio.h> 


// DEFINIÇÃO PINOS 
int RECV_PIN = 11;
int Vermelho = 8; // Lâmpada da Sala
int Verde = 9; // Lâmpada da Cozinha
int Azul = 10; //Lâmpada da Cozinha II
int Buzzer = 6;

char autor[] = "Alan Spinola";
double ver = 1.1;

// INSTANCIANDO OBJETOS
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  pinMode(RECV_PIN, INPUT); // Recebe as informações do IR
  pinMode(Vermelho, OUTPUT); 
  pinMode(Verde, OUTPUT);
  pinMode(Azul, OUTPUT);
  
  irrecv.enableIRIn(); // Start IR
  Serial.println("Seja Bem Vindo ao Sistema de Controle Central.");
  Serial.print("Versão:");
  Serial.print(ver, 1);
  Serial.print("  Autor:");
  Serial.println(autor);
  Serial.println("");
  Serial.println("Modulos Ativos:");
  Serial.println("");
  Serial.println("Modulo Sensor IR Habilitado: IRremote ");
}

void loop(){
boolean efeito_direito();
boolean efeito_esquerdo();
boolean botao_maior();
boolean botao_menor();

   if (irrecv.decode(&results)) {
   //Serial.print(" Apertado Botão:   ");
   //Serial.println(results.value, DEC);
    irrecv.resume(); // Receive the next value


    switch (results.value) {
      case (1907962371): {
        Serial.println("Led Vermelho Acesso");
        digitalWrite(Vermelho, HIGH);
        break;
      }   
      case (3060960739): {
        Serial.println("Led Verde Acesso");
        digitalWrite(Verde, HIGH);
        break;
      }
      case (1629609119): {
        Serial.println("Led Azul Acesso");
        digitalWrite(Azul, HIGH);
        break;
      }
      case (587215555): {
        Serial.println("Led Vermelho Apagado");
        digitalWrite(Vermelho, LOW);
        break;
      }   
      case (2091748039): {
        Serial.println("Led Verde Apagado");
        digitalWrite(Verde, LOW);
        break;
      }
      case (3501030495): {
        Serial.println("Led Azul Apagado");
        digitalWrite(Azul, LOW);
        break;
      }
        case (2054283779): {
        Serial.println("Led Tudo Ligado");
        digitalWrite(Vermelho, HIGH);
        digitalWrite(Verde, HIGH);
        digitalWrite(Azul, HIGH);
        break;
        }
        case (1866721467): {
        Serial.println("Led Tudo Apagado");
        digitalWrite(Vermelho, LOW);
        digitalWrite(Verde, LOW);
        digitalWrite(Azul, LOW);
        break;
      } 
        case (551522925): {
        Serial.println("Leds Esqueda para Direita");
        efeito_esquerdo();
        break;

      }  
        case (3400364191): {
        Serial.println("Leds Direita para Esqueda");
        efeito_direito();
        break;
        
      } 
         case (3721245087): {
        Serial.println("Maior");
        botao_maior();
        break;
        
      }
         case (551526495): {
        Serial.println("Menor");
        botao_menor();
        break;
        
      }  
   }
}

delay(50);
}


boolean efeito_direito(){

int i = 10;

  for (i = 1; i <= 10; i++){
    digitalWrite(Vermelho, HIGH);
    delay(100);
    digitalWrite(Vermelho, LOW);
    delay(200);
    digitalWrite(Verde, HIGH);
    delay(100);
    digitalWrite(Verde, LOW);
    delay(200);
    digitalWrite(Azul, HIGH);
    delay(100);
    digitalWrite(Azul, LOW);
    delay(200);
  }
}

boolean efeito_esquerdo(){

int i = 10;

  for (i = 10; i >= 0; i--){
    digitalWrite(Azul, HIGH);
    delay(100);
    digitalWrite(Azul, LOW);
    delay(200);
    digitalWrite(Verde, HIGH);
    delay(100);
    digitalWrite(Verde, LOW);
    delay(200);
    digitalWrite(Vermelho, HIGH);
    delay(100);
    digitalWrite(Vermelho, LOW);
    delay(200);
  }
};


boolean botao_maior(){

  int i = 255;
  int del = 15;

  for (i = 1; i <= 255; i++){

    
    analogWrite(Vermelho, 255);
    delay(del);
    analogWrite(Vermelho, 0);
    delay(del);
    analogWrite(Verde, 255);
    delay(del);
    analogWrite(Verde, 0);
    delay(del);
    analogWrite(Azul, 255);
    delay(del);
    analogWrite(Azul, 0);
    delay(del);
    
}
}

boolean botao_menor(){
  
  int i = 255;
  int del = 30;

  for (i = 1; i <= 255; i++){
    analogWrite(Vermelho, 255);
    delay(del);
    analogWrite(Verde, 255);
    delay(del);
    analogWrite(Azul, 255);
    delay(del);
    analogWrite(Vermelho, 0);
    delay(del);
    analogWrite(Verde, 0);
    delay(del);
    analogWrite(Azul, 0);
    delay(del);
 
}
}
