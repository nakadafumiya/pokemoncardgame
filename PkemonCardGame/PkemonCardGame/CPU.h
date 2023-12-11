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
	int DeckType;  //デッキの種類
	int CardBack;    //カードの裏面
	int BattleField; //バトルフィールドに出すカードのID
	int Trash[60]; //トラッシュされたカード
	int tCount;    //トラッシュにいるカードの枚数
	Data poke_data[20];
	Pokemon poke;
};

