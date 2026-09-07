#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // 2 tipe hexa, default 0x27. 0x3f (optional)
#define DHTPin 25
#define DHTTYPE DHT22

DHT dht(25, DHT22);

void setup() {
  Wire.begin(21,22);
  lcd.init();
  lcd.backlight();
  dht.begin();
  
}

void loop(){
  float suhu = dht.readTemperature();
  float kelembaban = dht.readHumidity();

  if (isnan(suhu) || isnan (kelembaban)) {
    lcd.setCursor(3,0);
    lcd.print("Gagal Membaca");
    lcd.setCursor(3,1);
    lcd.print("Sensor");
    return;
  }

  lcd.setCursor(0,0);
  lcd.print("Suhu:");
  lcd.print(suhu, 0);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("kelembaban:");
  lcd.print(kelembaban, 0);
  lcd.print("%");
  delay(1000);
}