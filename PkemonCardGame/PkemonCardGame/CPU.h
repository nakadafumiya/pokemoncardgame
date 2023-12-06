#pragma once
#include "Hand.h"
#include "Card_Deck.h"
#include "Pokemon.h"
#include "Side.h"

class CPU :public Hand,public Card_Deck,public Side
{
public:
	CPU();
	void Update();
	void Draw()const;

private:
	int DeckType;  //ƒfƒbƒL‚ÌŽí—Þ
	int cardBack;
	Data poke_data[20];
};

