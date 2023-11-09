#pragma once
#include "AbstractScene.h"
#include"common.h"

class Energy : public AbstractScene
{
private:
	int ENE;
public:
	Energy();
	//描画以外の更新を実装する
	virtual AbstractScene* Update();
	//描画に関するころを実装する
	virtual void Draw()const;
};