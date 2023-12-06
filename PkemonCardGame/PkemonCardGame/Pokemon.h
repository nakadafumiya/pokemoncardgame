
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
	Data Poke_id[20];
	bool Action;
	
	int BattlePoke;

	//ポケモンカード画像
	int kokuba;
	int rarutosu;
	int dhianshi;
	int gekkouga;

protected:
	int ENE;
public:
	Pokemon();
	//・ｽ`・ｽ・ｽﾈ外・ｽﾌ更・ｽV・ｽ・ｽ・ｽ・ｽ・ｽ・ｽ・ｽ・ｽ・ｽ・ｽ
	virtual void Update(class GameMainScene* a) override;
	//・ｽ`・ｽ・ｽﾉ関ゑｿｽ・ｽ驍ｱ・ｽ・ｽ・ｽ・ｽ・ｽ・ｽ・ｽ・ｽ・ｽ・ｽ・ｽ
	virtual void Draw()const override;

	Data GetPokeID(int i)const { return Poke_id[i]; }

	int Battle(int id);
};