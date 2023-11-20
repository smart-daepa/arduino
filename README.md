# 토양 수분 감지 및 워터 펌프 - 김건우
**대파의 적정 습도 - 40% ~ 70%**

-> 화분의 토양 습도가 40% ~ 70%를 유지하도록 워터펌프가 작동해야 함

**토양 수분 감지 센서(YL-69)**

-> 토양의 수분을 감지하는 데 사용, 이를 이용하여 자동 급수 시스템이나 식물의 토양의 수분을 모니터링할 수 있음.
<br>-> 토양의 수분 함량이 높을수록 전류가 잘 흘려 저항이 낮아짐.
<br>-> 토양의 수분 함량이 낮을수록 전류가 잘 흐르지 않아 저항이 높아짐.
<br>-> 디지털 핀은 토양의 수분 함량이 미리 정의된 임계 값을 초과하면 LOW를 출력, 그렇지 않으면 HIGH를 출력
<br>-> 아날로그 핀은 0 ~ 1023 사이의 저항 값을 측정


<table border="1">
  <tr>
   <th colspan=5>
     토양 수분 감지 센서 특징
   </th>
  </tr>
  <tr>
    <th>제품명</th>
    <th>특징</th>
    <th>입력 전압</th>
    <th>출력 값</th>
    <th>핀 배치</th>
  </tr>
  <tr>
    <td rowspan="3">YL-69</td>
    <td>아날로그 인터페이스</td>
    <td>3.3V ~ 5V</td>
    <td>마른 땅: 600 ~ 1000<br>젖은 땅: 370 ~ 600<br>물: 0 ~ 370</td>
    <td>A0: 아날로그 핀<br>D0: 디지털 핀<br>VCC: 전원 공급<br>GND: 접지</td>
  </tr>
</table>


 토양 수분 감지 센서 모듈(YL-69) 예시 코드
```
// YL-69 Soil Moisture Sensor

void setup() {
  Serial.begin(9600);
}
 
void loop() {
  
  int Soil_moisture = analogRead(A1); // 아날로그 핀에서 값 가져오기
  int humi = map(Soil_moisture, 0, 1023, 100, 0) // 아날로그 값을 퍼센트로 매핑

  Serial.print("토양 습도(%) : ");
  Serial.println(humi);
        
  delay(1000);


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
