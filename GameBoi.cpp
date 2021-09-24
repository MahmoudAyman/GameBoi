
#include "GameBoi.h"
#include "Arduino.h"
// #include "WProgram.h"
#include "HardwareSerial.h"



Key::Key()
{
  // pinMode(pin, INPUT);
  // _pin=pin;
  int (*_action)();
  
}

void Key::attach(int pin)
{
	_pin=pin;
	pinMode(_pin, INPUT);
}

int Key::isPressed()
{
  return (digitalRead(_pin));
}

void Key::setAction(int (*func)())
{
  _action = func; 
}

int Key::invoke()
{
    return _action();
}

GameBoi::GameBoi(int up, int down, int right, int left, int a, int b)
{
	UP.attach(up);
	DOWN.attach(down);
	RIGHT.attach(right);
	LEFT.attach(left);
	actionA.attach(a);
	actionB.attach(b);

	bool (*_mainLoop)();
}

bool GameBoi::loadGame(bool (*func)())
{
  _mainLoop = func; 
}

void GameBoi::begin(int baud_rate)
{
    Serial.begin(9600);
}

bool GameBoi::startGame()
{
	return (_mainLoop());
}

