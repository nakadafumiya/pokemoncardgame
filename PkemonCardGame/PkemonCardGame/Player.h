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
	//トラッシュにカードを入れる
	void SetTrash(int card) { Trash[tCount++] = card; }

private:
	int cardImg[27]; //カード画像
	int CardBack;    //カードの裏
	int Cursor_X;  //カーソル位置
	int DeckType;  //デッキの種類
	int OldX;
	int FlgX;
	int Battle; //バトルフィールドに出すカードのID
	int Bench[5];  //ベンチに出すカードのID
	int Trash[60]; //トラッシュされたカードのID
	int tCount;    //トラッシュにいるカードの枚数

	Data poke_data[19];
	Pokemon poke;

	//手札を描画
	void HandDraw()const;
	//バトルフィールドに置いたカードを描画
	void BattleFieldDraw()const;
	//描画するカードを判別
	int DetermineCard(int card, int dtype)const;
};

