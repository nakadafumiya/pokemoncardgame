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
	//•`‰æˆÈŠO‚ÌXV‚ğÀ‘•‚·‚é
	virtual AbstractScene* Update();
	//•`‰æ‚ÉŠÖ‚·‚é‚±‚ë‚ğÀ‘•‚·‚é
	virtual void Draw()const;
};

