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
	//•`‰æˆÈŠO‚ÌXV‚ğÀ‘•‚·‚é
	virtual AbstractScene* Update();
	//•`‰æ‚ÉŠÖ‚·‚é‚±‚ë‚ğÀ‘•‚·‚é
	virtual void Draw()const;
};