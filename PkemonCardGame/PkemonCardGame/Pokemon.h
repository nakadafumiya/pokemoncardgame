
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

	//�|�P�����J�[�h�摜
	int kokuba;
	int rarutosu;
	int dhianshi;
	int gekkouga;

protected:
	int ENE;
public:
	Pokemon();
	//�E�`�E��E�ȊO�E�̍X�E�V�E��E��E��E��E��E��E��E��E��E�
	virtual void Update(class GameMainScene* a) override;
	//�E�`�E��E�Ɋւ��E�邱�E��E��E��E��E��E��E��E��E��E��E�
	virtual void Draw()const override;

	Data GetPokeID(int i)const { return Poke_id[i]; }

	int Battle(int id);
};