#pragma once
#include "AbstractScene.h"
#include"common.h"

class Energy : public AbstractScene
{
private:
	int ENE;
public:
	Energy();
	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update();
	//�`��Ɋւ��邱�����������
	virtual void Draw()const;
};