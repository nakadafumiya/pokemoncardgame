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

	bool DrawCheck[19];  //�R�D�ɃJ�[�h�����݂��邩 true:���� false:�Ȃ�
	int CardDraw();  //�h���[
	bool CheckCard() //�R�D�ɃJ�[�h���c���Ă��邩? true�F���� false:�Ȃ�
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
	void Update();
	virtual void Draw()const;
	int GetCard()const { return Hand_Card; }
};