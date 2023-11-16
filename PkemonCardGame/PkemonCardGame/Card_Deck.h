#pragma once
#include "DxLib.h"
//#include "Pokemon.h"
#include "GameMainScene.h"

#define DECK 60

class Card_Deck : private GameMainScene
{
private:
	bool First_Draw;
	int Hand_Card;
	int Card_num;

public:
	Card_Deck();
	virtual AbstractScene* Update();
	void Draw();
};