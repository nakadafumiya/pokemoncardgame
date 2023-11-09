#pragma once
#include "DxLib.h"
//#include "Pokemon.h"

#define DECK 60

class Card_Deck
{
private:
	bool First_Draw;
	int Hand_Card;
	int Card_num;

public:
	Card_Deck();
	void Update();
	void Draw();
};