#include "Pokemon.h"
#include <stdio.h>
#include "DxLib.h"
#include <stdlib.h>	
#include <fstream>
#define N 256
#define ROW 20

Pokemon::Pokemon()
{
	FILE* fp = nullptr;
	
	errno_t err = fopen_s(&fp, "data/Pokemon.txt", "r");

	// エラーチェック
	if (fp == nullptr)
	{
		OutputDebugString("ファイルを開けない\n");
		throw (-1);
	}

	for (int i = 0; i < 20; i++)
	{
		fscanf_s(fp, "%[^,],%d,%[^,],%[^,],%d,%d,%d,%[^,]", Poke_id[i].NAME, 20, &Poke_id[i].HP, Poke_id[i].WEEK, 10, Poke_id[i].NOWEEK, 10, &Poke_id[i].RUN, &Poke_id[i].SIDE, &Poke_id[i].EVO, Poke_id[i].SINKAMOTO, 20);
	}
	Action = false;
	fclose(fp);
}

void Pokemon::Update()
{
	{
		int i = 5;
		// if (Hand_Card > 19)
		// {
			//int i = Hand_Card;

			//Poke_d[i].NAME;
			//Poke_d[i].HP;
			//Poke_d[i].WEEK;
			//Poke_d[i].NOWEEK;
			//Poke_d[i].RUN;
			//Poke_d[i].SIDE;
			//Poke_d[i].EVO;
			//Poke_d[i].SINKAMOTO;
		 //}

	}
}
void Pokemon::Draw() const
{
	DrawFormatString(0, 0, 0x000000, "%s %d %s %s %d %d %d %s", Poke_id[1].NAME, Poke_id[1].HP, Poke_id[1].WEEK, Poke_id[1].NOWEEK, Poke_id[1].RUN, Poke_id[1].SIDE, Poke_id[1].EVO, Poke_id[1].SINKAMOTO);
}