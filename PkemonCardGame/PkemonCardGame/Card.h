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
	//•`‰æˆÈŠO‚ÌXV‚ğÀ‘•‚·‚é
	virtual AbstractScene* Update();
	//•`‰æ‚ÉŠÖ‚·‚é‚±‚ë‚ğÀ‘•‚·‚é
	virtual void Draw()const;
};