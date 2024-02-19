#include "DxLib.h"
#include "Card_Deck.h"
#include "GameMainScene.h"

int Card_Deck::CardDraw()
{
	int ret = 0;
	do
	{
		ret = GetRand(MaxDeck - 1); //31
	} while (!DrawCheck[ret]);
	DrawCheck[ret] = false;
	return ret;
}
int Card_Deck::Hand_Card = 0;

Card_Deck::Card_Deck()
{
	Hand_Card = 0;

	for (int i = 0; i < MaxDeck; i++)
	{
		if (10 <= i && i <= 16)
		{
			DrawCheck[i] = false;
		}
		else
		{
			DrawCheck[i] = true;
		}
	}
	Card_num = 0;
}

void Card_Deck::Update(GameMainScene* a)
{
	/*int turn_tmp = a->GetTurn();
	if (turn_tmp == 1)
	{
		First_Draw = true;

		if (First_Draw == true)
		{
			Card_num = GetRand(18);
			Hand_Card = Card_num;
			First_Draw = false;
		}
		else if (Card_num == Hand_Card)
		{
			while (Card_num != Hand_Card)
			{
				Card_num = GetRand(18);
			}
			First_Draw = false;
		}
	}*/

	if (PAD_INPUT::OnClick(XINPUT_BUTTON_B))
	{

		Hand_Card = GetRand(12);
	}
	//setturn(turn_tmp);
}

void Card_Deck::Draw() const
{
	DrawFormatString(0, 200, 0x000000, "%d", Hand_Card);
}

void Card_Deck::setturn(int val)
{
	turn = val;
}