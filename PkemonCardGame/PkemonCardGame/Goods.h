#pragma once
#include "AbstractScene.h"
#include"common.h"

class Goods : public AbstractScene
{
private:
	int ENE;
public:
	Goods();
	//描画以外の更新を実装する
	virtual AbstractScene* Update();
	//描画に関するころを実装する
	virtual void Draw()const;
};