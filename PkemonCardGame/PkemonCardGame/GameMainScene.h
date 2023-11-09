#pragma once
#include "AbstractScene.h"
#include"common.h"
#include "Field.h"

class GameMainScene : public AbstractScene
{
private:
	Field field;
	int Turn;
	int Cr;
	int Player;
	int CPU;
	 
	bool NextTurn;
public:
GameMainScene();
//�`��ȊO�̍X�V����������
virtual AbstractScene* Update();
//�`��Ɋւ��邱�����������
virtual void Draw()const;
};

