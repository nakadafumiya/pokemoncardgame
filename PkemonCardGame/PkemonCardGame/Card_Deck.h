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

	bool DrawCheck[19];  //山札にカードが存在するか true:ある false:ない
	int CardDraw();  //ドロー
	bool CheckCard() //山札にカードが残っているか? true：ある false:ない
	{
		for (int i = 0; i < 19; i++)
		{
			if (DrawCheck[i])
			{
				return true;
			}
		}
		return false;
	}

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