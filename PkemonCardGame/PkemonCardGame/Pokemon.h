
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
	//���ꂼ��̃G�l���M�[
	int ENE;
	int E_ENE;
	int F_ENE;
};

class Pokemon : public Card_Deck
{
private:
	//�f�b�L�P�̏����i�[����
	Data Poke_id1[20];
	//�f�b�L�Q�̏����i�[����
	Data Poke_id2[20];
	bool Action;
	
	int BattlePoke;

	//�f�b�L�P�|�P�����J�[�h�摜
	int kokuba;
	int rarutosu;
	int dhianshi;
	int gekkouga;
	//�f�b�L�Q�|�P�����J�[�h�摜
	int aruseusu;
	int rekkuza;
	int mafokushi;
	int neoranto;
	int karubou;
	int bakettya;
	int hoshigarisu;
	int hi_doran;

protected:
	////���ꂼ��̃G�l���M�[
	//int ENE;
	//int E_ENE;
	//int F_ENE;
public:
	Pokemon();

	virtual void Update(class GameMainScene* a) override;

	virtual void Draw()const override;
	//�f�b�L�P��ID�擾
	Data GetPokeID1(int i)const { return Poke_id1[i]; }
	//�f�b�L�Q��ID�擾
	Data GetPokeID2(int i)const { return Poke_id2[i]; }
	//�f�b�L�P�|�P�����̋Z����
	int Battle1(int id);
	//�f�b�L�Q�|�P�����̋Z����
	int Battle2(int id);
};