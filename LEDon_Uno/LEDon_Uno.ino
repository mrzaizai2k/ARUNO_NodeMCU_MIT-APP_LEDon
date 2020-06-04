#include <SoftwareSerial.h>

SoftwareSerial ArduinoUno(3, 2); //3 = RX; 2 = TX
const int trig = 8;     // chân trig của HC-SR04
const int echo = 7;     // chân echo của HC-SR04
int LED = 12;

void setup() {
  Serial.begin(9600);
  ArduinoUno.begin(4800); /// Thiết lập kênh truyền DL qua softwareserial
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  pinMode(trig, OUTPUT);  // chân trig sẽ phát tín hiệu
  pinMode(echo, INPUT);  //chân echo sẽ nhận tín hiệu
  Serial.print("Mrzaizai2k");
  Serial.print("\n");

}
///////////đo khoảng cách////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int distance() {
  int distance;
  unsigned long duration; // biến đo thời gia
  // biến lưu khoảng cách
  //​/* Phát xung từ chân trig */
  digitalWrite(trig, 0);  // tắt chân tri
  delayMicroseconds(2);
  digitalWrite(trig, 1);  // phát xung từ chân tri
  delayMicroseconds(5);   // xung có độ dài 5 microSecond
  digitalWrite(trig, 0);  // tắt chân tri
  duration = pulseIn(echo, HIGH);
  //​// Tính khoảng cách đến vật//

  distance = int(duration / 2 / 29.412);

  return distance;
}

void loop() {
  int a = distance();
  Serial.print(a);
  Serial.println("cm");
  delay(200);
  while (ArduinoUno.available() > 0) {
    float val = ArduinoUno.parseFloat();

    if (val == 9) {
      Serial.println(val);
      digitalWrite(LED, HIGH);
    }
    else if (val == 8) {
      Serial.println(val);
      digitalWrite(LED, LOW);
    }
    break;
  }
  ArduinoUno.print(a);
  ArduinoUno.print("\n");
  delay(30);
}
