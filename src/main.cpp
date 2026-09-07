#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // 2 tipe hexa, default 0x27. 0x3f (optional)

void setup() {
  Wire.begin(21,22);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3, 0);
  lcd.print("KEJURUAN");
  lcd.setCursor(6, 1);
  lcd.print("TIK");
}

void loop(){



}