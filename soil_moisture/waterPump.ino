int A = 10;  // A를 연결한 디지털 핀
int B = 6;   // B를 연결한 디지털 핀
 
void setup()
{
  pinMode(A, OUTPUT);  // A를 출력 핀으로 설정
  pinMode(B, OUTPUT);  // B를 출력 핀으로 설정
}
 
void loop()
{
  digitalWrite(A, HIGH);  // 정방향으로 모터 회전
  digitalWrite(B, LOW);
  delay(5000);  // 5초동안 상태 유지
 
  digitalWrite(A, LOW);  // 모터 정지
  digitalWrite(B, LOW);
  delay(5000);  // 5초동안 상태 유지
}