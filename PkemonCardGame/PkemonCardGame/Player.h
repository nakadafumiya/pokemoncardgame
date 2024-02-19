#pragma once
#include "Hand.h"
#include "Card_Deck.h"
#include "Pokemon.h"
#include "Side.h"

class Player :public Hand, public Card_Deck, public Side
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

	bool EndFirstDraw;//ゲーム開始時に7枚引いたか true：終わった false：終わっていない
	bool EndStartDraw;//ターン開始時に1枚引いたか true：終わった false：終わっていない
	bool EndFirstSet;//カードを置き終わったか true：終わった false：終わっていない
private:
	int cardImg[27]; //カード画像
	int CardBack;    //カードの裏
	int Cursor_X;  //カーソル位置 X座標
	int Cursor_Y;  //カーソル位置 Y座標
	int DeckType;  //デッキの種類
	int OldX;
	int OldY;
	int FlgX;
	int FlgY;
	int Battle; //バトルフィールドに出すカードのID
	int Bench[5];  //ベンチに出すカードのID
	int Trash[60]; //トラッシュされたカードのID
	int tCount;    //トラッシュにいるカードの枚数
	const int X[3] = { 950,980,700 };
	const int Y[3] = { 700,800,910 };

	Data poke_data[19];
	Pokemon poke;

	//手札を描画
	void HandDraw()const;
	//バトルフィールドに置いたカードを描画
	void BattleFieldDraw()const;
	//描画するカードを判別
	int DetermineCard(int card_id, int dtype)const;
	//1ターン目にバトルフィールドとベンチにカードを置く
	void FirstCardSet();
};