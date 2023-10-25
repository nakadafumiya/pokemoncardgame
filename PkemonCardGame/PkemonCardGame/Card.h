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
	//描画以外の更新を実装する
	virtual AbstractScene* Update();
	//描画に関するころを実装する
	virtual void Draw()const;
};