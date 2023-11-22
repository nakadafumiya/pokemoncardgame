#pragma once
#include "AbstractScene.h"
#include"common.h"

struct Pokemon_Data
{
	char NAME[30];
	int HP;
	int WEAK[10];
	int RESIST[10];
	int EVO;
	int B_EVO[30];
	int RETREAT;
	int SIDE;
};

class Pokemon
{
private:
	Pokemon_Data pData[7];

	int Kokuba;
	int Kokuba_M;
	int rarutosu;
	int kiruria;
	int sanaito_e;
	int dhianshi;
	int gekkouga;

	bool Action;
protected:
	int ATK;
	int HP;
	int ENE;
	bool EVO;
public:
	Pokemon();
	//描画以外の更新を実装する
	virtual void Update();
	//描画に関するころを実装する
	virtual void Draw()const;
};