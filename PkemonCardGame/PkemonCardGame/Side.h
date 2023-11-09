#pragma once
#include "AbstractScene.h"
#include "DxLib.h"
class Side
{
private:

	
	int count; 
	int side[6];

	int BackCard;
public:

	Side();
	//•`‰æˆÈŠO‚ÌXV‚ğÀ‘•‚·‚é
	virtual AbstractScene* Update();
	//•`‰æ‚ÉŠÖ‚·‚é‚±‚ë‚ğÀ‘•‚·‚é
	virtual void Draw()const;
}; 

