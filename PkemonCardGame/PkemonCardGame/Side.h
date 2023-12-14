#pragma once
#include "AbstractScene.h"
#include "DxLib.h"
class Side
{
private:
	float Side_X, Side_Y;
	const int Size_H = 150;
	const int Size_W = 110;

	
	int side[6];

	int BackCard;

public:
	int count;

	Side();
	//•`‰æˆÈŠO‚ÌXV‚ğÀ‘•‚·‚é
	//virtual AbstractScene* Update();
	//•`‰æ‚ÉŠÖ‚·‚é‚±‚ë‚ğÀ‘•‚·‚é
	virtual void Draw()const;

	/*to do*/
	void SetSide(int card) 
	{ 
		++count;
		side[count - 1] = card;
	}
	int GetSide(int i)const { return side[i]; }
	/*‚±‚±‚Ü‚Å*/
}; 

