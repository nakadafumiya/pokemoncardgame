#pragma once
#include "DxLib.h"
//#include "Pokemon.h"
#include "GameMainScene.h"

#define DECK 60

class Card_Deck
{
public:
	bool First_Draw;
	int Hand_Card;
	int Card_num;
	int turn;

public:
	Card_Deck();
	virtual AbstractScene* Update(GameMainScene* a);
	virtual void Draw() const;

	void setturn(int val);

	int getturn()
	{
		return turn;
	}
};