
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
	struct Data Poke_id[20];
	bool Action;
	
	int BattlePoke;

	//�|�P�����J�[�h�摜
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
	//�`��ȊO�̍X�V����������
	virtual void Update(class GameMainScene* a) override;
	//�`��Ɋւ��邱�����������
	virtual void Draw()const override;
};