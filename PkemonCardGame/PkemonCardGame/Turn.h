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
	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update();
	//�`��Ɋւ��邱�����������
	virtual void Draw()const;
};

