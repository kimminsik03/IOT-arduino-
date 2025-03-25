  int  v0 =A0;//아날로그
  int  v_led =2;//디지털

  float v0_value = 0;
  float voltage = 0;
  float dustdensity = 0;

  
  void setup() {
  Serial.begin(9600);
  pinMode(v_led, OUTPUT);
  pinMode(v0, INPUT);

}

void loop() {
  digitalWrite(v_led, LOW);//low가 키는 것 
  delayMicroseconds(280);
  v0_value = analogRead(v0);
   delayMicroseconds(40);
   digitalWrite(v_led, HIGH);
   delayMicroseconds(9680);

   voltage = v0_value*5.0 / 1023.0;
   dustdensity = (voltage - 0.3)/0.005;

   Serial.print("dust=");//미들웨어 키 값과 value 값이 같이 들어가기 때문에 만들어줌
   Serial.println(dustdensity);
   
   delay(1000);}
