#pragma once
#include "AbstractScene.h"
#include"common.h"

class Pokemon : public AbstractScene
{
private:
	int Kokuba;
	int Kokuba_M;
	int rarutosu;
	int kiruria;
	int sanaito_e;
	int dhianshi;
	int gekkouga;

	int ATK;
	int HP;
	int ENE;
	bool EVO;
public:
	Pokemon();
	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update();
	//�`��Ɋւ��邱�����������
	virtual void Draw()const;
};