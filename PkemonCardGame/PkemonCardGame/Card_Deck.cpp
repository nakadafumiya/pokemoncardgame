#include "DxLib.h"
#include "Card_Deck.h"
#include "GameMainScene.h"

Card_Deck::Card_Deck()
{
	First_Draw = false;
	Hand_Card = 0;
	Card_num = 0;
}

AbstractScene* Card_Deck::Update(GameMainScene* a)
{
	int turn_tmp = a->GetTurn();
	if (turn_tmp == 1)
	{
		First_Draw = true;

		if (First_Draw == true)
		{
			Card_num = GetRand(60);
			Hand_Card = Card_num;
			First_Draw = false;
		}
		else if (Card_num == Hand_Card)
		{
			while (Card_num != Hand_Card)
			{
				Card_num = GetRand(60);
			}
			First_Draw = false;
		}
	}

	if (CheckHitKey(KEY_INPUT_SPACE))
	{

		Hand_Card = GetRand(60);
	}
	setturn(turn_tmp);
}

void Card_Deck::Draw() const
{
	DrawFormatString(0, 200, 0x000000, "%d", Hand_Card);
}

void Card_Deck::setturn(int val)
{
	turn = val;
}