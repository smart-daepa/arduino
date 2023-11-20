# Arduino

---
# 토양 수분 감지 및 워터 펌프 - 김건우
대파의 적정 습도 - 40% ~ 70%


 토양 수분 감지 센서 모듈(YL-69) 예시 코드
```
void setup() {
  Serial.begin(9600);
}
 
void loop() {
  
  int Soil_moisture = analogRead(A1);  
  Serial.println(Soil_moisture);        
  delay(100);

* 출처 : 에듀이노
```


워터펌프 예시코드
```
int AA = 10;  // AA를 연결한 디지털 핀
int AB = 6;   // AB를 연결한 디지털 핀
 
void setup()
{
  pinMode(AA, OUTPUT);  // AA를 출력 핀으로 설정
  pinMode(AB, OUTPUT);  // AB를 출력 핀으로 설정
}
 
void loop()
{
  digitalWrite(AA, HIGH);  // 정방향으로 모터 회전
  digitalWrite(AB, LOW);
  delay(5000);  // 5초동안 상태 유지(1000ms = 5s)
 
  digitalWrite(AA, LOW);  // 모터 정지
  digitalWrite(AB, LOW);
  delay(5000);  // 5초동안 상태 유지(1000ms = 5s)
}

* 출처 : 에듀이노
```

# 조도센서 빛의 양 확인(LED) - 김수지
조도센서 및 식물 생장 LED 코드
```
int analogPin = A0;  // 조도센서가 연결된 아날로그 핀
int ledPin = 9;     // LED가 연결된 디지털 핀

int totalLight = 0;       // 하루 동안의 누적 빛의 양을 저장하는 변수
unsigned long previousMillis = 0;  // 이전에 조도를 측정한 시간을 저장하는 변수
long interval = 1000 * 60 * 60;  // 1시간마다 조도를 측정

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
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

    // 여기에서 조도센서 값을 기반으로 식물 생장 LED를 제어
    if (sensorValue < 500) { // 어두울 때: 500이하, 밝을 때: 500이상
      digitalWrite(ledPin, HIGH);  // 어두울 때 LED를 켬
    } else {
      digitalWrite(ledPin, LOW);   // 밝을 때 LED를 끔
    }
  }

  delay(1000);  // 측정 주기를 조절
}
* 출처 : ChatGPT
```
