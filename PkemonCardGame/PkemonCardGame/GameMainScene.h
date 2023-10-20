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
//•`‰æˆÈŠO‚ÌXV‚ğÀ‘•‚·‚é
virtual AbstractScene* Update();
//•`‰æ‚ÉŠÖ‚·‚é‚±‚ë‚ğÀ‘•‚·‚é
virtual void Draw()const;
};

