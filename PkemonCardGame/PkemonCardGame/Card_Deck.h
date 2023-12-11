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

private:
	bool DrawCheck[31];  //山札にカードが存在するか true:ある false:ない
public:
	//ドロー
	int CardDraw();
	//山札にカードが残っているか? true：ある false:ない
	bool CheckCard()const
	{
		for (int i = 0; i < 31; i++)
		{
			if (DrawCheck[i])
			{
				return true;
			}
		}
		return false;
	}
	//山札にカードを戻す
	void ReturnCard(int card_id)
	{
		DrawCheck[card_id] = true;
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