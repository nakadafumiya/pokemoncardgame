#include "DxLib.h"
#include "Card_Deck.h"

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

Card_Deck::Card_Deck()
{
	First_Draw = false;
	Hand_Card;
	Card_num;

	/*ŒÂl—p*/
	for (int i = 0; i < 19; i++)
	{
		DrawCheck[i] = true;
	}
}

void Card_Deck::Update()
{
	//if (Turn == true)
	///*{
	//	First_Draw = true;

	//	if (First_Draw == true)
	//	{
	//		Card_num = GetRand(60);
	//		Hand_Card = Card_num;
	//		First_Draw = false;
	//	}
	//	else if (Card_num == Hand_Card)
	//	{
	//		while (Card_num != Hand_Card)
	//		{
	//			Card_num = GetRand(60);
	//		}
	//		First_Draw = false;
	//	}
	//}*/
	//if (CheckHitKey(KEY_INPUT_SPACE))
	//{

	//	Hand_Card = GetRand(60);
	//}
}

void Card_Deck::Draw() const
{
	//DrawFormatString(0, 200, 0x000000, "%d", Hand_Card);
}