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
    if (direcao == DIREITA) {
      if (sensor_e) {
        direcao = ESQUERDA; 
      } else if (sensor_d) {
        direcao = FRENTE;
      }

    } else if (direcao == ESQUERDA) {
      if (sensor_e) {
        direcao = FRENTE; 
      } else if (sensor_d) {
        direcao = DIREITA;
      }

    } else if (direcao == FRENTE) {
      if (sensor_e) {
        direcao = ESQUERDA;
      } else if (sensor_d) {
        direcao = DIREITA;
      }
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
