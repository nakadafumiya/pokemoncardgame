#pragma once
#include "AbstractScene.h"
#include"common.h"

class Card : public AbstractScene
{
private:
	int type[23];
	int ATK;
	int HP;
	int ENE;
	bool EVO;
public:
	Card();
	//描画以外の更新を実装する
	virtual AbstractScene* Update();
	//描画に関するころを実装する
	virtual void Draw()const;
};