/* Nome:  Programa Automação Casa 
   Autor: Alan Spinola 
   Data:  07/07/2019
   Versão: 1.0 - Arduino UNO - C++ (Ver1.0)
*/

// INCLUSÃO DE BIBLIOTECAS
#include <IRremote.h> // Biblioteca para controle IR


// DEFINIÇÃO PINOS
int RECV_PIN = 11;
int Vermelho = 8;
int Verde = 9;
int Azul = 10;
int Buzzer = 6;

char ver = 1.0;

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
  Serial.println("");
  Serial.println("");
  Serial.println("Modulos Ativos:");
  Serial.println("");
  Serial.println("Modulo Sensor IR Habilitado: IRremote ");
}

void loop(){
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
   }
}

delay(50);
}
