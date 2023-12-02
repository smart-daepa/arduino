#include <DHT11.h>

int analogPin = A0;  // 조도센서가 연결된 아날로그 핀
const int GREEN_PIN = 9;  //GREEN LED와 디지털 10 핀 연결
const int YELLOW_PIN = 10;    //BLUE LED와 디지털 9 핀 연결
const int RED_PIN = 11;    //RED LED와 디지털 11 핀 연결
const int A = 8;  // A를 연결한 디지털 핀
const int B = 7;   // B를 연결한 디지털 핀

int pin = 2;
DHT11 dht11(pin);

void setup() {
  Serial.begin(9600);
  pinMode(RED_PIN, OUTPUT);    //11번 핀을 출력으로 설정
  pinMode(GREEN_PIN, OUTPUT);  //10번 핀을 출력으로 설정
  pinMode(YELLOW_PIN, OUTPUT);   //9번 핀을 출력으로 설정
  pinMode(A, OUTPUT);  // A를 출력 핀으로 설정
  pinMode(B, OUTPUT);  // B를 출력 핀으로 설정
}

void jodo() {
    int sensorValue = analogRead(analogPin);

    Serial.print("jodo ");
    Serial.print(sensorValue);

    // 여기에서 조도센서 값을 기반으로 LED를 제어
    if (sensorValue < 300) { // 겨울이라 실내가 어두움으로 값을 크게 줌
      digitalWrite(RED_PIN, LOW);  // 밝을 때 LED를 끔
      digitalWrite(YELLOW_PIN, LOW);
      digitalWrite(GREEN_PIN, HIGH);
    } else if (sensorValue < 500) {
      digitalWrite(RED_PIN, LOW);  // 밝을 때 LED를 끔
      digitalWrite(YELLOW_PIN, HIGH);
      digitalWrite(GREEN_PIN, LOW);
    } else {
      digitalWrite(RED_PIN, HIGH);  // 밝을 때 LED를 끔
      digitalWrite(YELLOW_PIN, LOW);
      digitalWrite(GREEN_PIN, LOW);
    }
  }
 

void soil_moisture() {
  int Soil_moisture = analogRead(A1); // 아날로그 핀에서 값 가져오기
  int humi = map(Soil_moisture, 0, 1023, 100, 0); // 아날로그 값을 퍼센트로 매핑

  Serial.print(" soil_moisture ");
  Serial.println(humi);

  if(humi < 40){
    digitalWrite(A, HIGH);  // 정방향으로 모터 회전
    delay(5000);  // 5초동안 상태 유지
  }
 
  digitalWrite(A, LOW);  // 모터 정지
}

void ondo() {
  float temp, humi;
  dht11.read(humi, temp);
  Serial.print(" ondo ");
  Serial.print(temp);
  Serial.print(" ");
  Serial.print(humi);

}

void loop() {
  
  jodo();
  ondo();
  soil_moisture();
  delay(100000);
}
