// Programa: Controle de velocidade e direção de um motor Dc utilizando o módulo L298D

// Define os pinos de controle do motor ligados ao Arduino
#define PINO_IN1 6  // Pino responsável pelo controle no sentido horário
#define PINO_IN2 5  // Pino responsável pelo controle no sentido anti-horário
#define PINO_IN3 11  // Pino responsável pelo controle no sentido anti-horário
#define PINO_IN4 10  // Pino responsável pelo controle no sentido anti-horário
  
void setup(){ 
  // Configura os pinos de controle como saída
  pinMode(PINO_IN1, OUTPUT);  // Define o pino IN1 como saída
  pinMode(PINO_IN2, OUTPUT);  // Define o pino IN2 como saída
  pinMode(PINO_IN3, OUTPUT);  // Define o pino IN1 como saída
  pinMode(PINO_IN4, OUTPUT);  // Define o pino IN2 como saída
  Serial.begin(115200);
}
  
void loop() {   
  int valor_pwm = 0;  // Variável para armazenar o valor PWM (0-255)

  // Aumenta a velocidade gradualmente de 0% a 100% no sentido horário
  for (valor_pwm = 0; valor_pwm < 256; valor_pwm++) {
    analogWrite(PINO_IN1, valor_pwm);  // Aplica o valor PWM no pino IN1
    analogWrite(PINO_IN4, valor_pwm);  // Aplica o valor PWM no pino IN1
    Serial.println(valor_pwm);
    delay(100);  // Espera 100 ms antes de aumentar a velocidade
  }
 
  // Diminui a velocidade gradualmente de 100% a 0% no sentido horário
  for (valor_pwm = 255; valor_pwm >= 0; valor_pwm--) {
    analogWrite(PINO_IN1, valor_pwm);  // Reduz o valor PWM no pino IN1
    analogWrite(PINO_IN4, valor_pwm);  // Aplica o valor PWM no pino IN1
    Serial.println(valor_pwm);
    delay(100);  // Espera 100 ms antes de diminuir mais a velocidade
  }

  // Aumenta a velocidade gradualmente de 0% a 100% no sentido anti-horário
  for (valor_pwm = 0; valor_pwm < 256; valor_pwm++) {
    analogWrite(PINO_IN2, valor_pwm);  // Aplica o valor PWM no pino IN2
    analogWrite(PINO_IN3, valor_pwm);  // Aplica o valor PWM no pino IN1
    Serial.println(valor_pwm);
    delay(100);  // Espera 100 ms antes de aumentar a velocidade
  }
 
  // Diminui a velocidade gradualmente de 100% a 0% no sentido anti-horário
  for (valor_pwm = 255; valor_pwm >= 0; valor_pwm--) {
    analogWrite(PINO_IN2, valor_pwm);  // Reduz o valor PWM no pino IN2
    analogWrite(PINO_IN3, valor_pwm);  // Aplica o valor PWM no pino IN1
    Serial.println(valor_pwm);
    delay(100);  // Espera 100 ms antes de diminuir mais a velocidade
  } 
}
