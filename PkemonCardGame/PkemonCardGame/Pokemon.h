
#pragma once
#include "AbstractScene.h"
#include "Card_Deck.h"
#include"common.h"
struct Data
{
	char NAME[20];
	int HP;
	char WEAK[10];
	char NOWEEK[10];
	int RUN;
	int SIDE;
	int EVO;
	char SINKAMOTO[20];
};

class Pokemon : public Card_Deck
{
private:
	Data Poke_id[7];
	bool Action;
protected:
	int ENE;
public:
	Pokemon();
	//�`��ȊO�̍X�V����������
	virtual void Update();
	//�`��Ɋւ��邱�����������
	virtual void Draw()const;
};