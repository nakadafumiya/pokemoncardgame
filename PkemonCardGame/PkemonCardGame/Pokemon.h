#pragma once
#include "AbstractScene.h"
#include"common.h"

class Pokemon : public AbstractScene
{
private:
	int Kokuba;
	int Kokuba_M;
	int rarutosu;
	int kiruria;
	int sanaito_e;
	int dhianshi;
	int gekkouga;

	int ATK;
	int HP;
	int ENE;
	bool EVO;
public:
	Pokemon();
	//描画以外の更新を実装する
	virtual AbstractScene* Update();
	//描画に関するころを実装する
	virtual void Draw()const;
};