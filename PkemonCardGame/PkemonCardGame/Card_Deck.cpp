#include "DxLib.h"
#include "Card_Deck.h"
#include "GameMainScene.h"

int Card_Deck::CardDraw()
{
	int ret = 0;
	do
	{
		ret = GetRand(19 - 1);
	} while (!DrawCheck[ret]);
	DrawCheck[ret] = false;
	return ret;
}
int Card_Deck::Hand_Card = 0;

Card_Deck::Card_Deck()
{
	First_Draw = true;
	Hand_Card = 0;

	/*�l�p*/
	for (int i = 0; i < 19; i++)
	{
		DrawCheck[i] = true;
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

		Hand_Card = GetRand(18);
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