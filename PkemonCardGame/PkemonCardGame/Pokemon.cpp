#include <fstream>
#include <iostream>
#include "Pokemon.h"
#include <stdio.h>
#include "PadInput.h"
#include "DxLib.h"
#include <stdlib.h>	
#include <fstream>
#include "GameMainScene.h"
#define N 256
#define ROW 20

Pokemon::Pokemon()
{
	BattlePoke = -1;

	FILE* fp = nullptr;
	
	errno_t err = fopen_s(&fp, "data/Pokemon1.txt", "r");

	//
	if (fp == nullptr)
	{
		OutputDebugString("images/Pokemon_Card_D2/CardBack.png");
		throw (-1);
	}

	for (int i = 0; i < 10; i++)
	{
		fscanf_s(fp, "%[^,],%d,%d,",
			Poke_id1[i].NAME, 20,
			&Poke_id1[i].HP,
			&Poke_id1[i].SIDE);
	}
	Action = false;
	fclose(fp);

	 err = fopen_s(&fp, "data/Pokemon2.txt", "r");

	if (fp == nullptr)
	{
		OutputDebugString("images/Pokemon_Card_D2/CardBack.png");
		throw (-1);
	}

	for (int i = 0; i < 13; i++)
	{
		fscanf_s(fp, "%[^,],%d,%d,",
			Poke_id2[i].NAME, 20,
			&Poke_id2[i].HP,
			&Poke_id2[i].SIDE);
	}
	fclose(fp);

	kokuba = LoadGraph("images/Pokemon_Card_D1/こくばバドレックスV.png");
	rarutosu = LoadGraph("images/Pokemon_Card_D1/Ralts.png");
	dhianshi = LoadGraph("images/Pokemon_Card_D1/ディアンシー.png");
	gekkouga = LoadGraph("images/Pokemon_Card_D1/ShiningGreninja.png");
}

void Pokemon::Update(GameMainScene* a)
{
	
}

void Pokemon::Draw() const
{
	DrawFormatString(0, 100, 0x000000, "%d", Hand_Card);

	DrawFormatString(0, 0, 0x000000, "%s %d %d ", 
		Poke_id2[Hand_Card].NAME, 
		Poke_id2[Hand_Card].HP,
		Poke_id2[Hand_Card].SIDE);
}

int Pokemon::Battle1(int id)
{
	if (id < 4)
	{
		if (ENE <= 1)
		{
			return 10;
		}
	}
	if (id >= 4 && id < 8)
	{
		if (ENE <= 1)
		{
			return 10;
		}
	}
	if (id == 8)
	{
		if (ENE <= 1)
		{
			return 20;
		}
	}
	if (id == 9)
	{
		if (ENE <= 3)
		{
			ENE = -2;
			return 90;
		}
	}
}

int Pokemon::Battle2(int id)
{
	if (id < 3)
	{
		if (ENE <= 3)
		{
			return 130;
		}
	}

	if (id >= 3 && id < 5)
	{
		if (E_ENE <= 1)
		{
			return 40;
		}
		else if (F_ENE <= 1 && E_ENE <= 1)
		{
			return 100;
		}
	}

	if (id >= 5 && id < 7)
	{
		if (F_ENE <= 3 || F_ENE <= 2 && E_ENE <= 1)
		{
			return 120;
		}
	
	}

	if (id >= 8 && id < 10)
	{
		if (F_ENE <= 1 || E_ENE <= 1)
		{
			return 10;
		}
		else if (F_ENE <= 2 || F_ENE <= 1 && E_ENE <= 1)
		{
			return 20;
		}
	}

	if (id == 10)
	{
		if (F_ENE <= 2 || E_ENE <= 2)
		{
			return 20;
		}
	}

	if (id == 11)
	{
		if (F_ENE <= 2 || E_ENE <= 2)
		{
			return 20;
		}
	}

	if (id == 12)
	{
		if (F_ENE <= 3 || F_ENE <= 2 && E_ENE <= 1 || F_ENE <= 1 && E_ENE <= 2)
		{
			return 70;
		}
	}
}



