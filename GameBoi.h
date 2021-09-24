
#ifndef GameBoi_h
#define GameBoi_h

#include "Arduino.h"


class Key
{
  public:
  	Key();
  	Key(int);
  	int isPressed();
  	void setAction(int (*func)());
  	int invoke();
    int (*_action)();
    void attach(int);
    int _pin;
  private:
  	
};

class GameBoi
{
  public:
  	GameBoi(int, int,int,int,int,int);
  	void begin(int);
  	bool loadGame(bool (*func)());
  	bool startGame();
  	Key UP, DOWN, RIGHT, LEFT, actionA, actionB;
  	//Key UP;
  	bool (*_mainLoop)();
  private:
  	
};

#endif