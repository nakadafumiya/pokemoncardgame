#pragma once
#include "AbstractScene.h"
#include"common.h"

class Energy : public AbstractScene
{
private:
	int ENE;
public:
	Energy();
	//•`‰æˆÈŠO‚ÌXV‚ğÀ‘•‚·‚é
	virtual AbstractScene* Update();
	//•`‰æ‚ÉŠÖ‚·‚é‚±‚ë‚ğÀ‘•‚·‚é
	virtual void Draw()const;
};