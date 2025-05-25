//#include <Wire.h>                    //I2C 통신을 위한 라이브러리 아래 헤더에서 포함되어 있기 때문에 중복 제거 
#include <LiquidCrystal_I2C.h>		     //I2C 라이브러리 이 안에 들어 있음 

LiquidCrystal_I2C lcd(0x27 , 16 ,2);


void setup(){

  lcd.init();             //I2C LCD 초기화
	lcd.backlight();	      // 백라이트 켜기
	lcd.print("LCD init");  //화면 출력
	delay(2000);            //2초 대기
	lcd.clear();            //화면 새로고침 
  
}

void loop()
{
 lcd.setCursor(15,0); // 위치를 가로 맨 오른쪽 세로 1번 줄에 커서를 옮김
  lcd.print("hello world!"); //출력
  
  for(int position = 0; position <16; position++){ // 출력결과를 계속 왼쪽으로 이동하는 함수
  	lcd.scrollDisplayLeft();//왼쪽으로 커서를 계속 옮김
    delay(150); 
  }
    
   delay(1000);
}

  