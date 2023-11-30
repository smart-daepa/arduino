int A = 10;  // A를 연결한 디지털 핀
int B = 6;   // B를 연결한 디지털 핀
 
// YL-69 Soil Moisture Sensor

void setup() {
  pinMode(A, OUTPUT);  // A를 출력 핀으로 설정
  pinMode(B, OUTPUT);  // B를 출력 핀으로 설정
  Serial.begin(9600);
}
 
void loop() {
  
  int Soil_moisture = analogRead(A1); // 아날로그 핀에서 값 가져오기
  int humi = map(Soil_moisture, 0, 1023, 100, 0); // 아날로그 값을 퍼센트로 매핑

  Serial.print("토양 습도(%) : ");
  Serial.println(humi);

  if(humi < 40){
    digitalWrite(A, HIGH);  // 정방향으로 모터 회전
    digitalWrite(B, LOW);
    delay(5000);  // 5초동안 상태 유지
  }
 
  digitalWrite(A, LOW);  // 모터 정지
  digitalWrite(B, LOW);
        
  delay(1000);
}


