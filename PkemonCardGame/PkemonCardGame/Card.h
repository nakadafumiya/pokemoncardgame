#pragma once
#include "AbstractScene.h"
#include"common.h"

class Card : public AbstractScene
{
private:
	int type[23];
	int ATK;
	int HP;
	int ENE;
	bool EVO;
public:
	Card();
	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update();
	//�`��Ɋւ��邱�����������
	virtual void Draw()const;
};