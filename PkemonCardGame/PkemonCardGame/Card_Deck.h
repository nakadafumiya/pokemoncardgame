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
	bool DrawCheck[31];  //�R�D�ɃJ�[�h�����݂��邩 true:���� false:�Ȃ�
public:
	//�h���[
	int CardDraw();
	//�R�D�ɃJ�[�h���c���Ă��邩? true�F���� false:�Ȃ�
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
	//�R�D�ɃJ�[�h��߂�
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