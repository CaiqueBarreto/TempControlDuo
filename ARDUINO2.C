#include <Servo.h>

Servo meuServo;
char comando;

void setup() {
  Serial.begin(9600); // Inicia comunicação na mesma velocidade
  meuServo.attach(9); // Pino do servo no Arduino 2
  meuServo.write(0);  // Começa em 0 graus
}

void loop() {
  // Verifica se chegou alguma mensagem do Arduino 1
  if (Serial.available() > 0) {
    comando = Serial.read();

    if (comando == 'H') {
      meuServo.write(180); // Move para 180 graus (máximo do SG90)
    } 
    else if (comando == 'L') {
      meuServo.write(0);   // Volta para a posição inicial
    }
  }
}