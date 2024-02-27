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
	void LoadImages();
	//バトルフィールドにカードを置く
	void SetBattleField();
	//ベンチにカードを置く
	void SetBench();
	//最初に手札を7枚引く
	void FirstDraw();
	//ターン情報を受け取る
	void SetTrun(int t) { Turn = t; }

	bool EndFirstDraw; //ゲーム開始時に7枚引いたか true：終わった false：終わっていない
	bool EndFirstSet;  //カードを置き終わったか true：終わった false：終わっていない
	bool EndSetSide;   //カードをサイドに置き終わったか true：終わった false：終わっていない
	bool EndStartDraw; //ターン開始時に1枚引いたか true：終わった false：終わっていない

private:
	int DeckType;  //デッキの種類
	int CardBack;    //カードの裏面
	int cardImg[27]; //カード画像
	int Battle; //バトルフィールドに出すカードのID
	int Bench[5];  //ベンチに出すカードのID
	int Trash[60]; //トラッシュされたカードのID
	int tCount;    //トラッシュにいるカードの枚数
	int Turn;	   //ターン
	Data poke_data[20];
	Pokemon poke;

	//手札を描画
	void HandDraw()const;
	//バトルフィールドに置いたカードを描画
	void BattleFieldDraw()const;
	//ベンチに置いたカードを描画
	void BenchDraw()const;
	//描画するカードを判別
	int DetermineCard(int card_id, int dtype)const;
};

