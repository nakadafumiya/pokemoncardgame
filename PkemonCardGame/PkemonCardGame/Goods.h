#pragma once
#include "AbstractScene.h"
#include"common.h"

class Goods : public AbstractScene
{
private:
	int ENE;
public:
	Goods();
	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update();
	//�`��Ɋւ��邱�����������
	virtual void Draw()const;
};