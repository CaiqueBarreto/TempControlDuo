#include <LiquidCrystal.h>

// Pinos do LCD conforme seu circuito
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int sensorTemp = A0;
float temperatura;

void setup() {
  Serial.begin(9600); // Inicia comunicação com o outro Arduino
  lcd.begin(16, 2);
  lcd.print("Monitor de Temp");
  delay(2000);
  lcd.clear();
}

void loop() {
  int valor = analogRead(sensorTemp);
  float tensao = valor * (5.0 / 1023.0);
  temperatura = (tensao - 0.5) * 100;

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatura);
  lcd.print(" C ");

  if (temperatura >= 30.0) {
    lcd.setCursor(0, 1);
    lcd.print("Servo: LIGADO ");
    Serial.write('H'); // Envia 'H' (High) para o Arduino 2
  } else {
    lcd.setCursor(0, 1);
    lcd.print("Servo: DESLIG ");
    Serial.write('L'); // Envia 'L' (Low) para o Arduino 2
  }

  delay(1000);
}