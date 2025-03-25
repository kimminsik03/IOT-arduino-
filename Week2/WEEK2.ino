#define TRIG 12 // TRIG 핀
#define ECHO 11 // ECHO 핀

int led1 = 7; 
int led2 = 8; 

void setup() { // 시작 시 한 번만 실행  
  Serial.begin(9600); // 시리얼 통신 시작 (속도 높으면 빠름)
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  
  pinMode(TRIG, OUTPUT); // 초음파가 나감
  pinMode(ECHO, INPUT);  // 나갔다가 돌아옴 
}

void loop() { // 루프 함수
  long duration;
  float distance;
  
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2); // 초기화  
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10); // 에코로 돌아오는 시간 만큼 약간 딜레이  
  digitalWrite(TRIG, LOW);
  
  duration = pulseIn(ECHO, HIGH); // HIGH에서 LOW 변경까지 시간 측정
  distance = duration * 0.034 / 2; // 왕복 거리 계산 (cm)
  
  // ====================== 계산값 출력
  Serial.print("Duration: ");
  Serial.print(duration);
  Serial.print(" us, Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // LED 동작
  digitalWrite(led1, HIGH); // 첫 번째 LED 켜기
  delay(1000); // 1초 대기
  digitalWrite(led1, LOW);  // 첫 번째 LED 끄기
  
  digitalWrite(led2, HIGH); // 두 번째 LED 켜기
  delay(1000); // 1초 대기
  digitalWrite(led2, LOW);  // 두 번째 LED 끄기
}