int sen =A2; // Set biến lưu giá trị (CẢm biến nối với chân A2)
int coi = 3; ///Còi ở chân D4
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sen, INPUT);//Set chân A2 là chân nhận tín hiệu
  pinMode(coi, OUTPUT);      //Set chân 4 là chân ngõ ra
    lcd.init();
  lcd.backlight();
  lcd.setCursor(2, 0);
  lcd.print("HE THONG PIR");
  
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(sen) == HIGH){
  lcd.setCursor(0, 1);
  lcd.print(" CO CHUYEN DONG ");
  Serial.println("PHAT HIEN CHUYEN DONG");
  digitalWrite(coi, HIGH);
  delay(300);
  digitalWrite(coi, LOW);
   delay(300);
}
else{
  digitalWrite(coi, LOW);
  lcd.setCursor(0, 1);
lcd.print("  BINH THUONG   ");
Serial.println("BINH THUONG");
}
}
