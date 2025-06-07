#include "benjamin.h"

void setup() {
    Serial.begin(115200);
    setup_benjamin();
}


int se = 0;
int sd = 0;
void loop() {
    se = sensor_esquerdo();
    sd = sensor_direito();

    Serial.print("leitura: ");
    Serial.print(se);
    Serial.print(" ");
    Serial.println(sd);

    delay(100);
}
