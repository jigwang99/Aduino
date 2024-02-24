#include <LiquidCrystal.h>

LiquidCrystal lcd(44, 45, 46, 47, 48, 49);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  
  int temperatureValue = analogRead(55);
  float temperatureC = (temperatureValue * 5.0 / 1024.0) * 100.0;

  
  int lightValue = analogRead(56);

  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatureC);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Light: ");
  lcd.print(lightValue);

  delay(1000);
}
