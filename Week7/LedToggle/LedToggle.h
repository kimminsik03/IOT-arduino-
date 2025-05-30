#ifndef LedToggle_h
#define LedToggle_h // 중복 방지

#include "Arduino.h" // 아두이노에서 사용할 함수를 import

class LedToggle {
public:
	LedToggle(int pin); // 생성자
	LedToggle(int pin, unsigned long delay); // 생성자 오버로딩
	void toggle(); // 토글 메서드

private:
	int _pin;
	bool _state;
	unsigned long _delayTime; // 지연 시간
};

#endif