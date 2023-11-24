int A = 10;  // in 1
int B = 6;   // in 2

void setup()
{
  pinMode(A, OUTPUT);  
  pinMode(B, OUTPUT);  
}
 
void loop()
{
  digitalWrite(A, HIGH);  // 모터 회전
  digitalWrite(B, LOW);
  delay(5000);  // 5초동안 상태 유지
 
  digitalWrite(A, LOW);  // 모터 정지
  digitalWrite(B, LOW);
  delay(5000);  // 5초동안 상태 유지
}