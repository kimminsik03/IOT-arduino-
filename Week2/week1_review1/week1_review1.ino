// C++ code
//
#define TRIG  8
#define ECHO  9

int red = 6; //보통 전역 변수로 선언함
int green = 7;

void setup()
{
  Serial.begin(9600);//숫자가 높을수록 빠름
  //pinMode(LED_BUILTIN, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  
}

void loop()
{
  long distance, duration;
  
  //digitalWrite(LED_BUILTIN, HIGH);
  //delay(1000); // Wait for 1000 millisecond(s)
  //digitalWrite(LED_BUILTIN, LOW);
  //delay(1000); // Wait for 1000 millisecond(s)
  
  digitalWrite(red, HIGH);
  delay(1000);
  digitalWrite(red, LOW);

  digitalWrite(green, HIGH);
  delay(1000);
  digitalWrite(green, LOW);
  
  
  
  
  digitalWrite(TRIG, LOW);//이전에 어떤 상태일지 모르기 때문에 초기화
  delayMicroseconds(2);//0.002초 동안 대기 
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);// 초음파가 되돌아오는 시간 동안 대기
  digitalWrite(TRIG, LOW);
  
  
  duration = pulseIn(ECHO, HIGH);
  //트리거에서 초음파가 되돌아오면 에코로 들어가면 HIGH로 바뀌는데 
  //여기에서 LOW로 바뀌는 시간을 측정하는 함수
  distance = duration * 17 /1000;
  
  
 
  Serial.println(duration );
  Serial.print("distance : ");
  Serial.print(distance);
  Serial.println(" Cm");

}