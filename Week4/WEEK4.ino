#include <Wire.h>                        //I2C 통신을 위한 라이브러리
#include <LiquidCrystal_I2C.h>		     //I2C 라이브러리 이 안에 들어 있음 

LiquidCrystal_I2C lcd(0x27 , 16 ,2);


void setup(){

  lcd.init();              //I2C LCD 초기화
	lcd.backlight();	   // 백라이트 켜기
	lcd.print("LCD init");
	delay(2000);
	lcd.clear();
  
}

void loop()
{
 lcd.setCursor(16,0);
  lcd.print("hello world!");
  
  for(int position = 0; position <16; position++){
  	lcd.scrollDisplayLeft();
    delay(150);
  }
    
   delay(1000);
}

  