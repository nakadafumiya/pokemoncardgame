#pragma once
#include "AbstractScene.h"
#include"common.h"

class Items : public AbstractScene
{
private:
	int ATK;
	int Genki;
	int Beruto;
public:
	Items();
	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update();
	//�`��Ɋւ��邱�����������
	virtual void Draw()const;
};