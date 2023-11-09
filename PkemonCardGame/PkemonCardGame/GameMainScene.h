#pragma once
#include "AbstractScene.h"
#include"common.h"
#include "Field.h"

class GameMainScene : public AbstractScene
{
private:
	Field field;
	int Turn;
	int Cr;
	int Player;
	int CPU;
	 
	bool NextTurn;
public:
GameMainScene();
//描画以外の更新を実装する
virtual AbstractScene* Update();
//描画に関するころを実装する
virtual void Draw()const;
};

