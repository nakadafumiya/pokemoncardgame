#include "Pokemon.h"
#include "DxLib.h"

Pokemon::Pokemon()
{
	ATK = 0;
	HP = 0;
	ENE = 0;
	EVO = false;
}

AbstractScene* Pokemon::Update()
{
	int kokuba = (HP = 210);
	if (ENE == 1)
	{
		ATK = 0;
		ATK = 10;
	}
	if (ENE == 3)
	{
		ATK = 0;
		ATK = 10 * 5;
	}

	int kokuba_M = (HP = 320);
	if (ENE == 3)
	{
		ATK = 0;
		ATK = ENE * 30 + 10;
	}

	int rarutosu = (HP = 70);
	if (ENE == 1)
	{
		ATK = 0;
		ATK = 10;
	}

	int kiruria = (HP = 80);
	if (ENE == 2)
	{
		ATK = 0;
		ATK = 30;
	}

	int sanaito_e = (HP = 310);
	if (ENE == 3)
	{
		ATK = 0;
		ATK = 190;
	}

	int dhianshi = (HP = 90);
	if (ENE == 1)
	{
		ATK = 0;
		ATK = 20;
	}

	int gekkouga = (HP = 130);
	if (ENE == 3)
	{
		ATK = 0;
		ATK = 90;
	}
	return this;
}

void Pokemon::Draw() const
{

}