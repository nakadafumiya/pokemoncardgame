#pragma once
#include "AbstractScene.h"
#include"common.h"

class Trainer : public AbstractScene
{
private:
	int ENE;
public:
	Trainer();
	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update();
	//�`��Ɋւ��邱�����������
	virtual void Draw()const;
};