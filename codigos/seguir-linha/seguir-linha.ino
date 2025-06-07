#include "benjamin.h"
#define ESQUERDA 0
#define DIREITA 1

void setup() {
    Serial.begin(115200);
    setup_benjamin();
}


int sensor_e = 0;
int sensor_d = 0;

int direcao = DIREITA;

void loop() {
    sensor_e = sensor_esquerdo();
    sensor_d = sensor_direito();

    if (sensor_e) {
      direcao = ESQUERDA;
    } else if (sensor_d) {
      direcao = DIREITA;
    }

    if (direcao == DIREITA) {
      girar_direita();
    } else if (direcao == ESQUERDA) {
      girar_esquerda();
    }

    // delay(1);
}
