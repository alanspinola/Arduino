/* Nome:  Programa Automação Casa - Controle Remoto Clone
   Autor: Alan Spinola 
   Data:  07/07/2019
   Versão: 1.0 - Arduino UNO - C++ (Ver1.0)
*/

// INCLUSÃO DE BIBLIOTECAS
#include <IRremote.h> // Biblioteca para controle IR

// DEFINIÇÃO PINOS
int RECV_PIN = 11;

// INSTANCIANDO OBJETOS
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  pinMode(RECV_PIN, INPUT); // Recebe as informações do IR
  irrecv.enableIRIn(); // Start IR
}

void loop() {
  if (irrecv.decode(&results)) {
   Serial.print(" Apertado Botão:   ");
   Serial.println(results.value, DEC);
   irrecv.resume(); // Receive the next value
  }
  delay(1);
}
