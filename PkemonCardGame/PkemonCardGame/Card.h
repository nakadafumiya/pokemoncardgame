#pragma once
#include "AbstractScene.h"
#include"common.h"

class Card : public AbstractScene
{
private:
	int type[23];
	int value[60];
public:
	GameMainScene();
	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update();
	//�`��Ɋւ��邱�����������
	virtual void Draw()const;
};