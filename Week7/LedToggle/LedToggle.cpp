#include "LedToggle.h"

LedToggle::LedToggle(int pin){
	_pin = pin;
	_state = false;
	_delayTime =0;
	pinMode(_pin, OUTPUT);
	digitalWrite(_pin , LOW);

}

LedToggle::LedToggle(int pin, unsigned long delaytime){
	_pin = pin;
	_state = false;
	_delayTime = delaytime;
	pinMode(_pin, OUTPUT);
	digitalWrite(_pin , LOW);

}


void LedToggle::toggle(){
if(_delayTime >0){
	delay(_delayTime);
}
_state = !_state;
digitalWrite(_pin, _state ? HIGH: LOW);
}