#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);   //Địa chỉ i2c LCD
#define sensor A1
#define led 9
#define motor 8
#define quangtro A2

const int analogInPin = A0;
int sensorValue = 0;
unsigned long int avgValue;
float b;
int buf[10], temp;


//.................................................
void setup() {
  Serial.begin(9600);
  lcd.init();
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
  pinMode(motor, OUTPUT);
  pinMode (quangtro, INPUT);
  pinMode (analogInPin, INPUT); 
  lcd.setCursor(0,0);
  lcd.print("Do Am = ");
  lcd.setCursor(0,1);
  lcd.println("Do PH = ");
  lcd.setCursor(0,2);
  lcd.print("Den:");
  lcd.setCursor(0,3);
  lcd.print("Bom:");

}
//.................................................
void loop() {
  //Độ ẩm
  int value = analogRead(sensor);
  value = map(value, 0, 1023, 0, 100);
  lcd.setCursor(10, 0);
  lcd.println(value);
  delay(20);
  if (value > 70) {                           //set độ ẩm nếu cao hơn thì off, thấp hơn thì on
    Serial.println("Do am binh thuong");
    digitalWrite(motor, LOW);
    lcd.setCursor(7, 3);
    lcd.print("OFF");
  }
  else {
    Serial.println("Dat kho thieu nuoc");
    digitalWrite(motor, HIGH);
    lcd.setCursor(7, 3);
    lcd.print("ON ");
  }

   
//Ánh sáng
if (digitalRead(quangtro) == LOW){
    Serial.println("Troi toi - Den ON");
    digitalWrite(led, HIGH);
    lcd.setCursor(7, 2);
    lcd.print("ON ");
  }
  else {
    Serial.println("Troi Sang - Den OFF");
    digitalWrite(led, LOW);
    lcd.setCursor(7, 2);
    lcd.print("OFF");
  }
    
  // Độ PH
  for (int i = 0; i < 10; i++){
    buf[i] = analogRead(analogInPin);
    delay(10);
  }
  for (int i = 0; i < 9; i++){
    for (int j = i + 1; j < 10; j++){
      if (buf[i] > buf[j]){
        temp = buf[i];
        buf[i] = buf[j];
        buf[j] = temp;
      }
    }
  }
  avgValue = 0;
  for (int i = 2; i < 8; i++)
    avgValue += buf[i];
  float pHVol = (float)avgValue * 5.0 / 1024 / 6;
  float phValue = -5.70 * pHVol + 21.34;
  Serial.print("Do pH = ");
  Serial.println(phValue);
  lcd.setCursor(10, 1);
  lcd.println(phValue);
   delay(20);
  }
