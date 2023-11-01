#pragma once
#include "SceneManager.h"
#include "common.h"

class Turn : public AbstractScene
{
public:
	int Player;
	int CPU;
	int BattleStart;
	int BattleEnd;
	int MyTurn;
	int EnemyTurn;

private:
	
	Turn();
	//描画以外の更新を実装する
	virtual AbstractScene* Update();
	//描画に関するころを実装する
	virtual void Draw()const;
};

