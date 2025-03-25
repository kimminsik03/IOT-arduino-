#include <Wire.h> // I2C통신을 위한 라이브러리

void setup() {

  Serial.begin(9600); // 시리얼 모니터 시작 속도9600baud
  Wire.begin(); //I2C 통시 시작
  Serial.println("I2C Scanner Running..."); //시작 메세지 춫력
  

}

void loop() {
  Serial.println("Scanning"); // 검색 시작 메세지 출력

  for(byte address =1; address<127 ; address++){ //주소 범위 0x01 ~ 0x7F (1~127)
    Wire.beginTransmission(address); //특정  주소로 통신 시작 
    if(Wire.endTransmission() ==0 ){//응답이 9이면 I2C 장치가 존재함 
      Serial.print("I2C 장치 발견 : 0X"); // 발견된 장치 주소 출력 
      Serial.print(address,HEX);// 16진수 형식으로 출력
      delay(500);// 0.5초 대기 너무 빠르게 반복되지 않도록
    }
  }
  Serial.println("Scan Complete! Retrying in 5 seconds ...");
   delay(5000); //5초 후 다시 검색

}

