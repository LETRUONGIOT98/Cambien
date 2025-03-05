#include <LiquidCrystal_I2C.h>
#include "DHT.h"
LiquidCrystal_I2C lcd(0x3f, 16, 2); // 0x3f or 0x27 
DHT dht(4, DHT11);
void setup() {
  // initialize LCD and turn on LCD backlight
  lcd.init();                     
  lcd.backlight();
// start the DHT
  dht.begin();
}
void loop() {
  // Wait a few seconds between measurements.
  delay(2000);
  //lcd.clear();
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  
  // set cursor to first column, first row
  lcd.setCursor(0, 0);
  // print message
  lcd.print("Humidity: ");
  lcd.print(h);
  lcd.print("%");
// set cursor to first column, second row
  lcd.setCursor(0,1);
  lcd.print("Heat index: ");
  lcd.print(t);
  lcd.print("°C");
}
