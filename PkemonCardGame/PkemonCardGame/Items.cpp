#include "Items.h"
#include "Pokemon.h"
#include "DxLib.h"

Items::Items()
{
	ATK = 0;
}

AbstractScene* Items::Update()
{
	int Genki = (ATK = 10);
	int Beruto = (ATK = 30);
	return this;
}

void Items::Draw() const
{

}