#pragma once
#include "Hand.h"
#include "Card_Deck.h"
#include "Pokemon.h"

class CPU :public Hand,public Card_Deck
{
public:
	CPU();
	void Update();
	void Draw()const;

private:
	int DeckType;  //�f�b�L�̎��
	int cardBack;
	Data poke_data[20];
};

