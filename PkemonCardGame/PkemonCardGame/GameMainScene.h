#pragma once
#include "AbstractScene.h"
#include"common.h"
#include "Field.h"
#include "Hand.h"

class GameMainScene : public AbstractScene
{
private:
	Field field;
	Hand hand;

public:
GameMainScene();
//描画以外の更新を実装する
virtual AbstractScene* Update();
//描画に関するころを実装する
virtual void Draw()const;
};

