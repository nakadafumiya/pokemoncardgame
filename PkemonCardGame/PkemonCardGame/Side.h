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
	//描画以外の更新を実装する
	virtual AbstractScene* Update();
	//描画に関するころを実装する
	virtual void Draw()const;
}; 

