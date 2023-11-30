User
int analogPin = A0;  // 조도센서가 연결된 아날로그 핀
const int RED_PIN = 11;    //RED LED와 디지털 11 핀 연결
const int GREEN_PIN = 9;  //GREEN LED와 디지털 10 핀 연결
const int YELLOW_PIN = 10;    //BLUE LED와 디지털 9 핀 연결

int totalLight = 0;       // 하루 동안의 누적 빛의 양을 저장하는 변수
unsigned long previousMillis = 0;  // 이전에 조도를 측정한 시간을 저장하는 변수
unsigned long redLedMillis = 0;  // 빨간색 LED가 켜진 시간을 저장하는 변수
const long interval = 1000;  // 1초에 1번 측정 측정주기는 차후에 수정
const long maxRedLedOnTime = 6 * 60 * 60 * 1000;  // 6시간 주기

void setup() {
 Serial.begin(9600);
 pinMode(RED_PIN, OUTPUT);    //11번 핀을 출력으로 설정
 pinMode(GREEN_PIN, OUTPUT);  //10번 핀을 출력으로 설정
 pinMode(YELLOW_PIN, OUTPUT);   //9번 핀을 출력으로 설정
}

void loop() {
  unsigned long currentMillis = millis();

  // 일정 간격마다 조도를 측정하고 누적 빛의 양을 계산
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    int sensorValue = analogRead(analogPin);
    totalLight += sensorValue;

    Serial.print("현재 조도센서 값: ");
    Serial.println(sensorValue);
    Serial.print("누적 빛의 양: ");
    Serial.println(totalLight);

    // 여기에서 조도센서 값을 기반으로 LED를 제어
    if (sensorValue < 300) { // 겨울이라 실내가 어두움으로 값을 크게 줌
      digitalWrite(RED_PIN, LOW);  // 밝을 때 LED를 끔
      digitalWrite(YELLOW_PIN, LOW);
      digitalWrite(GREEN_PIN, HIGH);
      redLedMillis = 0;  // 리셋 빨간색 LED가 켜진 시간을 초기화
      Serial.println("It`s bright around here");
    } else if (sensorValue < 500 && redLedMillis < maxRedLedOnTime) {
      digitalWrite(RED_PIN, LOW);  // 밝을 때 LED를 끔
      digitalWrite(YELLOW_PIN, HIGH);
      digitalWrite(GREEN_PIN, LOW);
      redLedMillis += interval;  // 빨간색 LED가 켜진 시간을 업데이트
      Serial.println("It`s dark around here");
    } else {
      digitalWrite(RED_PIN, HIGH);  // 밝을 때 LED를 끔
      digitalWrite(YELLOW_PIN, LOW);
      digitalWrite(GREEN_PIN, LOW);
      Serial.println("It`s very dark around right now");
    }
  }
  delay(1000);  
}
