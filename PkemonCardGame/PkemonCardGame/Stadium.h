#pragma once
#include "AbstractScene.h"
#include"common.h"

class Stadium : public AbstractScene
{
private:
	int ENE;
public:
	Stadium();
	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update();
	//�`��Ɋւ��邱�����������
	virtual void Draw()const;
};