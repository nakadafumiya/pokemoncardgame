#pragma once
#include "AbstractScene.h"
#include"common.h"


class Pokemon
{
private:

	int Kokuba;
	int Kokuba_M;
	int rarutosu;
	int kiruria;
	int sanaito_e;
	int dhianshi;
	int gekkouga;

	bool Action;
protected:
	int ATK;
	int HP;
	int ENE;
	bool EVO;
public:
	Pokemon();
	//�`��ȊO�̍X�V����������
	virtual void Update();
	//�`��Ɋւ��邱�����������
	virtual void Draw()const;
};