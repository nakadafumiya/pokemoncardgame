#pragma once
#include "DxLib.h"
//#include "Pokemon.h"

#define DECK 60

class Card_Deck
{
public:
	bool First_Draw;
	static int Hand_Card;
	int Card_num;
	int turn;

public:
	Card_Deck();
	virtual void Update(class GameMainScene* a);
	virtual void Draw() const;

	void setturn(int val);

	int getturn()
	{
		return turn;
	}

	int GetCard()const { return Hand_Card; }
};