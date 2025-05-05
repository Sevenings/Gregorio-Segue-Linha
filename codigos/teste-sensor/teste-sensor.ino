#define PIN_LEITURA A0

void setup() {
    Serial.begin(115200);

    pinMode(PIN_LEITURA, INPUT);
}


int leitura;
void loop() {
    leitura = analogRead(PIN_LEITURA);

    Serial.println(leitura);

    delay(100);
}
