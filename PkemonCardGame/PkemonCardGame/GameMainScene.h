#pragma once
#include "AbstractScene.h"
#include"common.h"

class GameMainScene : public AbstractScene
{
private:

public:
GameMainScene();
//�`��ȊO�̍X�V����������
virtual AbstractScene* Update();
//�`��Ɋւ��邱�����������
virtual void Draw()const;
};

