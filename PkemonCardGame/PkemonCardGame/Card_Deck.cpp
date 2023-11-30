#include "DxLib.h"
#include "Card_Deck.h"

int Card_Deck::Hand_Card = 0;

Card_Deck::Card_Deck()
{
	First_Draw = false;
	Hand_Card = 0;
	Card_num;
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
	
	if (CheckHitKey(KEY_INPUT_SPACE))
	{

		Hand_Card = GetRand(18);
	}
}

void Card_Deck::Draw() const
{
	DrawFormatString(0, 200, 0x000000, "%d", Hand_Card);
}