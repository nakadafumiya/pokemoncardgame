
#pragma once
#include "AbstractScene.h"
#include "Card_Deck.h"
#include"common.h"
#include "PadInput.h"
struct Data
{
	char NAME[20];
	int HP;
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
	//�ｿｽ`�ｿｽ�ｿｽﾈ外�ｿｽﾌ更�ｿｽV�ｿｽ�ｿｽ�ｿｽ�ｿｽ�ｿｽ�ｿｽ�ｿｽ�ｿｽ�ｿｽ�ｿｽ
	virtual void Update(class GameMainScene* a) override;
	//�ｿｽ`�ｿｽ�ｿｽﾉ関ゑｿｽ�ｿｽ驍ｱ�ｿｽ�ｿｽ�ｿｽ�ｿｽ�ｿｽ�ｿｽ�ｿｽ�ｿｽ�ｿｽ�ｿｽ�ｿｽ
	virtual void Draw()const override;

	Data GetPokeID(int i)const { return Poke_id[i]; }
};