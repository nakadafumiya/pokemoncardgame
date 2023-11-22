#include "DxLib.h"
#include "Card_Deck.h"

Card_Deck::Card_Deck()
{
	First_Draw = false;
	Hand_Card;
	Card_num;
}

void Card_Deck::Update()
{
	//if (Turn == true)
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
}

void Card_Deck::Draw()
{
	
}