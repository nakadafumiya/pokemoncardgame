#include "Card.h"
#include "DxLib.h"

Card::Card()
{
	ATK = 0;
	HP = 0;
	ENE = 0;
	EVO = false;
}

AbstractScene* Card::Update()
{
	type[0] = HP;
	return this;
}

void Card::Draw() const
{

}