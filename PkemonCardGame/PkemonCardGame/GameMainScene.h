#pragma once
#include "AbstractScene.h"
#include"common.h"

class GameMainScene
{


public:
//�`��ȊO�̍X�V����������
virtual AbstractScene* Update();
//�`��Ɋւ��邱�����������
virtual void Draw()const;
};

