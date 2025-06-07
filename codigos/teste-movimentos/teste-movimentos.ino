// Programa: Controle de velocidade e direção de um motor Dc utilizando o módulo L298D
#include "benjamin.h"
  
void setup(){ 
  Serial.begin(115200);
  
  // Configura os pinos de controle como saída
  setup_benjamin();

  // Valores Iniciais
  parar();
}
  
void loop() {
    // frente();
    // delay(3000);
    // parar();
    // delay(500);

    girar_direita();
    delay(3000);
    parar();
    delay(500);

    girar_esquerda();
    delay(3000);
    parar();
    delay(500);

    // tras();
    // delay(3000);
    // parar();
    // delay(4000);
}
