int analogPin = A0;  // 조도센서가 연결된 아날로그 핀    
const int GREEN_PIN = 9;  //GREEN LED와 디지털 10 핀 연결
const int YELLOW_PIN = 10;    //BLUE LED와 디지털 9 핀 연결
const int RED_PIN = 11;      //RED LED와 디지털 11 핀 연결

void setup() {
 Serial.begin(9600);
 pinMode(RED_PIN, OUTPUT);    //11번 핀을 출력으로 설정
 pinMode(GREEN_PIN, OUTPUT);  //10번 핀을 출력으로 설정
 pinMode(YELLOW_PIN, OUTPUT);   //9번 핀을 출력으로 설정
}

void loop() {
 
    int sensorValue = analogRead(analogPin);
    
    Serial.print("jodo ");
    Serial.print(sensorValue);

    // 여기에서 조도센서 값을 기반으로 LED를 제어
    if (sensorValue < 300) { // 겨울이라 실내가 어두움으로 값을 크게 줌
      digitalWrite(RED_PIN, LOW);  // 밝을 때 LED를 끔
      digitalWrite(YELLOW_PIN, LOW);
      digitalWrite(GREEN_PIN, HIGH);      
    } else if (sensorValue < 500) {
      digitalWrite(RED_PIN, LOW);  //
      digitalWrite(YELLOW_PIN, HIGH);
      digitalWrite(GREEN_PIN, LOW);     
    } else {
      digitalWrite(RED_PIN, HIGH);  // 어두울 때 LED를 켬
      digitalWrite(YELLOW_PIN, LOW);
      digitalWrite(GREEN_PIN, LOW);
    }
}
