// YL-69 Soil Moisture Sensor

void setup() {
  Serial.begin(9600);
}
 
void loop() {
  
  int Soil_moisture = analogRead(A1); // 아날로그 핀에서 값 가져오기
  int humi = map(Soil_moisture, 0, 1023, 100, 0); // 아날로그 값을 퍼센트로 매핑

  Serial.print("저항 : ");
  Serial.println(Soil_moisture);
  Serial.print("토양 습도(%) : ");
  Serial.println(humi);
        
  delay(1000);
}