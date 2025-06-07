// Programa: Controle de velocidade e direção de um motor Dc utilizando o módulo L298D

// Define os pinos de controle do motor ligados ao Arduino
#define PINO_IN1_L 10  // Pino responsável pelo controle no sentido horário
#define PINO_IN2_L 11  // Pino responsável pelo controle no sentido anti-horário
#define PINO_IN3_R 6  // Pino responsável pelo controle no sentido horário
#define PINO_IN4_R 5  // Pino responsável pelo controle no sentido anti-horário
                       //
#define PINO_SEN_L 2
#define PINO_SEN_R 3

#define FRENTE 1
#define TRAS 0

void setup_benjamin() {
    pinMode(PINO_IN1_L, OUTPUT);
    pinMode(PINO_IN2_L, OUTPUT);
    pinMode(PINO_IN3_R, OUTPUT);
    pinMode(PINO_IN4_R, OUTPUT);

    pinMode(PINO_SEN_L, INPUT);
    pinMode(PINO_SEN_R, INPUT);
}

void parar() {
    analogWrite(PINO_IN1_L, 0);
    analogWrite(PINO_IN2_L, 0);
    analogWrite(PINO_IN4_R, 0);
    analogWrite(PINO_IN3_R, 0);
}


void motor_direita(int velocidade, bool frente) {
    if (frente) {
        analogWrite(PINO_IN3_R, velocidade);
        analogWrite(PINO_IN4_R, 0);
    } else {
        analogWrite(PINO_IN3_R, 0);
        analogWrite(PINO_IN4_R, velocidade);
    }
}

void motor_esquerda(int velocidade, bool frente) {
    if (frente) {
        analogWrite(PINO_IN1_L, velocidade);
        analogWrite(PINO_IN2_L, 0);
    } else {
        analogWrite(PINO_IN1_L, 0);
        analogWrite(PINO_IN2_L, velocidade);
    }
}

void parar_direita() {
    analogWrite(PINO_IN3_R, 0);
    analogWrite(PINO_IN4_R, 0);
}

void parar_esquerda() {
    analogWrite(PINO_IN1_L, 0);
    analogWrite(PINO_IN2_L, 0);
}

void frente() {
    // Impulso quebrar inércia
    // motor_esquerda(255, FRENTE);
    // motor_direita(255, FRENTE);
    // delay(100);

    // Manter velocidade
    motor_esquerda(120, FRENTE);
    motor_direita(100, FRENTE);
}

void tras() {
    // Impulso quebrar inércia
    // motor_esquerda(255, TRAS);
    // motor_direita(255, TRAS);
    // delay(100);

    // Manter velocidade
    motor_esquerda(150, TRAS);
    motor_direita(150, TRAS);
}

void girar_direita() {
    // Impulso quebrar inércia
    // motor_esquerda(255, FRENTE);
    // parar_direita();
    // delay(100);

    // Manter velocidade
    motor_esquerda(150, FRENTE);
    parar_direita();
}

void girar_esquerda() {
    // Impulso quebrar inércia
    // parar_esquerda();
    // motor_direita(255, FRENTE);
    // delay(100);

    // Manter velocidade
    parar_esquerda();
    motor_direita(150, FRENTE);
}

int sensor_esquerdo() {
    return digitalRead(PINO_SEN_L);
}

int sensor_direito() {
    return digitalRead(PINO_SEN_R);
}

