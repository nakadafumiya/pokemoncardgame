#include "DxLib.h"
#include "Card_Deck.h"

Card_Deck::Card_Deck()
{
	image = LoadGraph("images/Pokemon_Card_D1/�|�P�J�w��.png");
}

void Card_Deck::Draw()
{
	DrawGraph(50, 170, image, true);
}