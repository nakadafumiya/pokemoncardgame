
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
};

class Pokemon : public Card_Deck
{
private:
	Data Poke_id1[20];

	Data Poke_id2[20];
	bool Action;
	
	int BattlePoke;

	//ポケモンカード画像
	int kokuba;
	int rarutosu;
	int dhianshi;
	int gekkouga;

	int aruseusu;
	int rekkuza;
	int mafokushi;
	int neoranto;
	int karubou;
	int bakettya;
	int hoshigarisu;
	int hi_doran;

protected:
	int ENE;
public:
	Pokemon();
	//
	virtual void Update(class GameMainScene* a) override;
	//
	virtual void Draw()const override;

	Data GetPokeID1(int i)const { return Poke_id1[i]; }

	Data GetPokeID2(int i)const { return Poke_id2[i]; }

	int Battle(int id);
};