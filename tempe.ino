#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Se establece la dirección del módulo LCD I2C
LiquidCrystal_I2C lcd(0x27,16,2);

int sensorPin = A0;  // Pin del LM35

void setup() {
  //lcd.begin();  // Inicia la comunicación con el LCD
  lcd.init();
  lcd.backlight();  // Encender el backlight del LCD
}

void loop() {
  int sensorValue = analogRead(sensorPin);  // Lee el valor del LM35
  float voltage = sensorValue * (5.0 / 1023.0);  // Convierte el valor a voltaje
  float temperature = (voltage - 0.5) * 100;  // Convierte el voltaje a grados Celsius
  
  lcd.clear();  // Limpia el contenido del LCD
  lcd.setCursor(0,0);  // Se posiciona en la primera línea del LCD
  lcd.print("Temp: ");  // Imprime "Temp: "
  lcd.print(temperature);  // Imprime la temperatura
  lcd.print(" C");  // Imprime " C"
  delay(1000);  // Espera 1 segundo antes de volver a medir la temperatura
}
