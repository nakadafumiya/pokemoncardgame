
#pragma once
#include "AbstractScene.h"
#include "Card_Deck.h"
#include"common.h"
#include "PadInput.h"
struct Data
{
	char NAME[20];
	int HP;
	char TYPE[10];
	char WEEK[10];
	char NOWEEK[10];
	int RUN;
	int SIDE;
	int EVO;
	char SINKAMOTO[20];
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
	int kokuba_m;
	int kiruria;
	int sa_naito;
protected:
	int ENE;
public:
	Pokemon();
	//・ｽ`・ｽ・ｽﾈ外・ｽﾌ更・ｽV・ｽ・ｽ・ｽ・ｽ・ｽ・ｽ・ｽ・ｽ・ｽ・ｽ
	virtual void Update(class GameMainScene* a) override;
	//・ｽ`・ｽ・ｽﾉ関ゑｿｽ・ｽ驍ｱ・ｽ・ｽ・ｽ・ｽ・ｽ・ｽ・ｽ・ｽ・ｽ・ｽ・ｽ
	virtual void Draw()const override;

	int Weak()const;
	Data GetPokeID(int i)const { return Poke_id[i]; }
};