// Programa: Controle de velocidade e direção de um motor Dc utilizando o módulo L298D

// Define os pinos de controle do motor ligados ao Arduino
#define PINO_IN1_L 6  // Pino responsável pelo controle no sentido horário
#define PINO_IN2_L 5  // Pino responsável pelo controle no sentido anti-horário
#define PINO_IN3_R 11  // Pino responsável pelo controle no sentido horário
#define PINO_IN4_R 10  // Pino responsável pelo controle no sentido anti-horário


void parar() {
    analogWrite(PINO_IN1_L, 0);  // Aplica o valor PWM no pino IN1
    analogWrite(PINO_IN2_L, 0);
    analogWrite(PINO_IN4_R, 0);  // Aplica o valor PWM no pino IN1
    analogWrite(PINO_IN3_R, 0);  // Aplica o valor PWM no pino IN1
}


void frente() {
    analogWrite(PINO_IN1_L, 65);  // Aplica o valor PWM no pino IN1
    analogWrite(PINO_IN4_R, 55);  // Aplica o valor PWM no pino IN1

    analogWrite(PINO_IN2_L, 0);
    analogWrite(PINO_IN3_R, 0);
}


  
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
    delay(4000);
    parar();
    delay(4000);
}
