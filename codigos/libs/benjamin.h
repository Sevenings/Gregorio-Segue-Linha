// Programa: Controle de velocidade e direção de um motor Dc utilizando o módulo L298D

// Define os pinos de controle do motor ligados ao Arduino
#define PINO_IN1_L 6  // Pino responsável pelo controle no sentido horário
#define PINO_IN2_L 5  // Pino responsável pelo controle no sentido anti-horário
#define PINO_IN3_R 10  // Pino responsável pelo controle no sentido horário
#define PINO_IN4_R 11  // Pino responsável pelo controle no sentido anti-horário

#define FRENTE 1
#define TRAS 0

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


void frente() {
    // Impulso quebrar inércia
    motor_esquerda(70, FRENTE);
    motor_direita(60, FRENTE);
    delay(100);

    // Manter velocidade
    motor_esquerda(65, FRENTE);
    motor_direita(55, FRENTE);
}

void tras() {
    // Impulso quebrar inércia
    motor_esquerda(70, TRAS);
    motor_direita(60, TRAS);
    delay(100);

    // Manter velocidade
    motor_esquerda(58, TRAS);
    motor_direita(55, TRAS);
}

void girar_direita() {
    // Impulso quebrar inércia
    motor_esquerda(70, FRENTE);
    motor_direita(60, TRAS);
    delay(100);

    // Manter velocidade
    motor_esquerda(45, FRENTE);
    motor_direita(40, TRAS);
}

void girar_esquerda() {
    // Impulso quebrar inércia
    motor_esquerda(70, TRAS);
    motor_direita(60, FRENTE);
    delay(100);

    // Manter velocidade
    motor_esquerda(45, TRAS);
    motor_direita(40, FRENTE);
}
