
#pragma once
#include "AbstractScene.h"
#include "Card_Deck.h"
#include"common.h"
#include "PadInput.h"
struct Data
{
	char NAME[20];
	int HP;
	int SIDE;
	//それぞれのエネルギー
	int ENE;
	int E_ENE;
	int F_ENE;
};

class Pokemon : public Card_Deck
{
private:
	//デッキ１の情報を格納する
	Data Poke_id1[20];
	//デッキ２の情報を格納する
	Data Poke_id2[20];
	bool Action;
	
	int BattlePoke;

	//デッキ１ポケモンカード画像
	int kokuba;
	int rarutosu;
	int dhianshi;
	int gekkouga;
	//デッキ２ポケモンカード画像
	int aruseusu;
	int rekkuza;
	int mafokushi;
	int neoranto;
	int karubou;
	int bakettya;
	int hoshigarisu;
	int hi_doran;

protected:
	////それぞれのエネルギー
	//int ENE;
	//int E_ENE;
	//int F_ENE;
public:
	Pokemon();

	virtual void Update(class GameMainScene* a) override;

	virtual void Draw()const override;
	//デッキ１のID取得
	Data GetPokeID1(int i)const { return Poke_id1[i]; }
	//デッキ２のID取得
	Data GetPokeID2(int i)const { return Poke_id2[i]; }
	//デッキ１ポケモンの技条件
	int Battle1(int id);
	//デッキ２ポケモンの技条件
	int Battle2(int id);
};