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

	/*個人用*/
	bool DrawCheck[19];  //true:山札にある false:山札にない
	int CardDraw();
	bool CheckCard()
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
	/*ここまで*/

public:
	Card_Deck();
	void Update();
	virtual void Draw()const;
	int GetCard()const { return Hand_Card; }
};