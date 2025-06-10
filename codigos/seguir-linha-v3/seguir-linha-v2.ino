#include "benjamin.h"
#define ESQUERDA 0
#define DIREITA 1
#define FRENTE 2

void setup() {
    Serial.begin(115200);
    setup_benjamin();
}


int sensor_e = 0;
int sensor_d = 0;

int direcao = FRENTE;

void loop() {
    // Percepção
    sensor_e = sensor_esquerdo();
    sensor_d = sensor_direito();

    // Decisão
    if (sensor_e && !sensor_d) {
      // Apenas o sensor esquerdo na linha: vire para a esquerda
      direcao = ESQUERDA;
    } else if (!sensor_e && sensor_d) {
      // Apenas o sensor direito na linha: vire para a direita
      direcao = DIREITA;
    } else if (sensor_e && sensor_d) {
      // Ambos na linha (pode ser uma linha de chegada ou cruzamento)
      // Por enquanto, vamos em frente
      direcao = FRENTE;
    } else if (!sensor_e && !sensor_d) {
      // Ambos fora da linha, como em uma curva acentuada.
      // Continue fazendo o que estava fazendo antes (a variável 'direcao' não muda).
      // Se estava indo para frente, pode ser útil girar para o último lado detectado.
    } else {
      // Condição padrão: robô alinhado ou entre os sensores
      direcao = FRENTE;
    }

    // Ação
    if (direcao == DIREITA) {
      girar_direita();
    } else if (direcao == ESQUERDA) {
      girar_esquerda();
    } else if (direcao == FRENTE) {
      frente();
    }

    // Descanso
    delay(1);
}
