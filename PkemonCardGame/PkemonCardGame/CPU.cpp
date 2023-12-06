#include "CPU.h"
#define PI    3.1415926535897932384626433832795f

CPU::CPU()
{
	DeckType = 0;
	cardBack = -1;
	cardBack = LoadGraph("images/Pokemon_Card_D2/CardBack.png");

	for (int i = 0; i < 6; i++)
	{
		if (CheckCard())
		{
			SetSide(CardDraw());
		}
	}
}

void CPU::Update()
{
}

void CPU::Draw()const
{
	DrawString(1100, 680, "ŽèŽD", 0xffffff);
	for (int i = 0; i < 6; i++) //HandNum
	{
		DrawFormatString(500 + 25 * i, 100, 0xffffff, "%d", GetSide(i));//hand[i]
	}

	for (int i = 0; i < HandNum; i++)
	{
		if (hand[i] != -1)
		{
			DrawRotaGraph(1100 + i * Push_X, 0, 1.0, PI, cardBack, TRUE);
		}
	}
}
