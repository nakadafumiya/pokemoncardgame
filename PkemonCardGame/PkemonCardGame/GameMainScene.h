#pragma once
#include "AbstractScene.h"
#include"common.h"
#include "Field.h"

class GameMainScene : public AbstractScene
{
private:
	Field field;

public:
GameMainScene();
//�`��ȊO�̍X�V����������
virtual AbstractScene* Update();
//�`��Ɋւ��邱�����������
virtual void Draw()const;
};

