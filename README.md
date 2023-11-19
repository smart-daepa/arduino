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
