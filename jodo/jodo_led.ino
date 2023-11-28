변경전 코드

int analogPin = A0;  // 조도센서가 연결된 아날로그 핀
int digiPin = 9;     // 식물 생장 LED가 연결된 디지털 핀

int totalLight = 0;       // 하루 동안의 누적 빛의 양을 저장하는 변수
unsigned long previousMillis = 0;  // 이전에 조도를 측정한 시간을 저장하는 변수
const long interval = 1000 * 60 * 60;  // 1시간마다 조도를 측정

void setup() {
pinMode(digiPin, OUTPUT);
Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();

 // 일정 간격마다 조도를 측정하고 누적 빛의 양을 계산
 if (currentMillis - previousMillis >= interval) {
 
   int sensorValue = analogRead(analogPin);
   totalLight += sensorValue;~~

    Serial.print("현재 조도센서 값: ");
    Serial.println(sensorValue);
    Serial.print("누적 빛의 양: ");
    Serial.println(totalLight);~~

    // 여기에서 조도센서 값을 기반으로 LED를 제어
   if (sensorValue < 400) {
      digitalWrite(digiPin, LOW);  // 밝을 때 LED를 끔
     Serial.println("LED 끔");
  } else if (sensorValue >= 400) {
      digitalWrite(digiPin, HIGH);   // 어두울 때 LED를 켬
      Serial.println("LED 켬");~~
    }
  }
 delay(1000); 
}
      
변경후 코드
  
int analogPin = A0;  // 조도센서가 연결된 아날로그 핀
const int RED_PIN = 11;    //RED LED와 디지털 11 핀 연결
const int GREEN_PIN = 9;  //GREEN LED와 디지털 10 핀 연결
const int YELLOW_PIN = 10;    //BLUE LED와 디지털 9 핀 연결

int totalLight = 0;       // 하루 동안의 누적 빛의 양을 저장하는 변수
unsigned long previousMillis = 0;  // 이전에 조도를 측정한 시간을 저장하는 변수
const long interval = 3000;  // 3초에 1번 측정 측정주기는 차후에 수정

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
    if (sensorValue < 300) { //겨울이라 실내가 어두움으로 값을 크게 줌
      digitalWrite(RED_PIN, LOW);  // 밝을 때 LED를 끔
      digitalWrite(YELLOW_PIN, LOW);
      digitalWrite(GREEN_PIN, HIGH);
      Serial.println("현재 주변이 밝습니다");
    } else if (sensorValue < 500) {
      digitalWrite(RED_PIN, LOW);  // 밝을 때 LED를 끔
      digitalWrite(YELLOW_PIN, HIGH);
      digitalWrite(GREEN_PIN, LOW);
      Serial.println("현재 주변이 어둡습니다");
    }
    else{
      digitalWrite(RED_PIN, HIGH);  // 밝을 때 LED를 끔
      digitalWrite(YELLOW_PIN, LOW);
      digitalWrite(GREEN_PIN, LOW);
      Serial.println("현재 주변이 많이 어둡습니다");
    }
  }
  delay(1000);  
}

