int analogPin = A0;  // 조도센서가 연결된 아날로그 핀
int digiPin = 9;     // 식물 생장 LED가 연결된 디지털 핀

int totalLight = 0;       // 하루 동안의 누적 빛의 양을 저장하는 변수
unsigned long previousMillis = 0;  // 이전에 조도를 측정한 시간을 저장하는 변수
const long interval = 1000 * 60 * 60;  // 1시간마다 조도를 측

void setup() {
  pinMode(digiPin, OUTPUT);
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

    // 여기에서 조도센서 값을 기반으로 LED를 제어할 수 있습니다.
    if (sensorValue < 400) {
      digitalWrite(digiPin, LOW);  // 어두울 때 LED를 끔
      Serial.println("LED 끔");
    } else if (sensorValue >= 400) {
      digitalWrite(digiPin, HIGH);   // 밝을 때 LED를 켬
      Serial.println("LED 켬");
    }
  }
  delay(1000);  
}
