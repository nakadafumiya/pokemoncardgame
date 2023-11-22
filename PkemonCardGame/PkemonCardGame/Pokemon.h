#pragma once
#include "AbstractScene.h"
#include"common.h"


class Pokemon
{
private:

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
	//•`‰æˆÈŠO‚ÌXV‚ğÀ‘•‚·‚é
	virtual void Update();
	//•`‰æ‚ÉŠÖ‚·‚é‚±‚ë‚ğÀ‘•‚·‚é
	virtual void Draw()const;
};