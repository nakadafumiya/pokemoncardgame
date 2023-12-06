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

	/*to do*/
	int SideNum = 0;
	/*ここまで*/
public:
	int count;

	Side();
	//描画以外の更新を実装する
	//virtual AbstractScene* Update();
	//描画に関するころを実装する
	virtual void Draw()const;

	/*to do*/
	void SetSide(int card) 
	{ 
		side[SideNum++] = card;
		++count;
	}
	int GetSide(int i)const { return side[i]; }
	/*ここまで*/
}; 

