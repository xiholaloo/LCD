#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // 2 tipe hexa, default 0x27. 0x3f (optional)

void setup() {
  Wire.begin(21,22);
  lcd.init();
  lcd.backlight();

}

void loop(){
  lcd.clear();
  lcd.setCursor(7,0);
  lcd.print("BLK");
  lcd.setCursor(4,1);
  lcd.print("WONOJATI");
  delay(2000);
  
  lcd.setCursor(7,0);
  lcd.print("IOT");
  lcd.setCursor(1,1);
  lcd.print("SMART FARMING");
  delay(2000);
}