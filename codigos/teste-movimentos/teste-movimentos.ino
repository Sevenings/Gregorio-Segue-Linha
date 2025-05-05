// Programa: Controle de velocidade e direção de um motor Dc utilizando o módulo L298D
#include "benjamin.h"
  
void setup(){ 
  Serial.begin(115200);
  
  // Configura os pinos de controle como saída
  pinMode(PINO_IN1_L, OUTPUT);  // Define o pino IN1 como saída
  pinMode(PINO_IN2_L, OUTPUT);  // Define o pino IN2 como saída
  pinMode(PINO_IN3_R, OUTPUT);  // Define o pino IN1 como saída
  pinMode(PINO_IN4_R, OUTPUT);  // Define o pino IN2 como saída

  // Valores Iniciais
  parar();
}
  
void loop() {
    frente();
    delay(3000);
    parar();
    delay(500);

    girar_direita();
    delay(3000);
    parar();
    delay(500);

    girar_esquerda();
    delay(3000);
    parar();
    delay(500);

    tras();
    delay(3000);
    parar();
    delay(4000);
}
