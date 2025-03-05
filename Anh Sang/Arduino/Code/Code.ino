int LED1=3; //Cài đặt biến LED1 là chân 3
int LED2=5; //Cài đặt biến LED2 là chân 5
int LED3=6; //Cài đặt biến LED3 là chân 6
int LDR = A0; ////Cài đặt biến LDR là chân A0
void setup() {
  // put your setup code here, to run once:3 
pinMode(LED1, OUTPUT);//Thiết lập biến Led1 là ngõ ra
pinMode(LED2, OUTPUT);//Thiết lập biến Led2 là ngõ ra
pinMode(LED3, OUTPUT);//Thiết lập biến Led3 là ngõ ra
pinMode(LDR, INPUT);  //Thiết lập biến LDR là ngõ vào
}

void loop() {
  // Các lệnh trong hàm loop sẽ được lặp lại liên tục

int ldr = map(analogRead(LDR), 0, 520, 255, 0);//thiết lập biến ldr = với giá trị tín hiệu đọc được từ biến ngõ vào. 0 dến 520 ngõ vào tương ứng với giá trị 255 - 0 ở ngõ ra
analogWrite(LED1, ldr);//Ghi giá trị biến ldr phía trên lên biến ngõ ra LED1
analogWrite(LED3, ldr);//Ghi giá trị biến ldr phía trên lên biến ngõ ra LED2
analogWrite(LED2, ldr);//Ghi giá trị biến ldr phía trên lên biến ngõ ra LED3
}
