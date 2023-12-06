#pragma once
#include "Hand.h"
#include "Card_Deck.h"
#include "Pokemon.h"
#include "Side.h"

class Player :public Hand,public Card_Deck,public Side
{
public:
	Player();
	Player(int dtype);
	void Update();
	void Draw()const;
	//画像読み込み
	void LoadImages();
	//スティック制御
	void SticControl();
	//カーソル位置の調整
	void AdjustmentCursor();

private:
	int cardImg[27]; //カード画像
	int Cursor_X;  //カーソル位置
	int DeckType;  //デッキの種類
	int OldX;
	int FlgX;

	Data poke_data[19];
	Pokemon poke;
};

