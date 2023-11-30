#include "Pokemon.h"
#include <stdio.h>
#include "PadInput.h"
#include "DxLib.h"
#include <stdlib.h>	
#include <fstream>
#define N 256
#define ROW 20

Pokemon::Pokemon()
{
	BattlePoke = -1;

	i = 0;
	FILE* fp = nullptr;
	
	errno_t err = fopen_s(&fp, "data/Pokemon.txt", "r");

	// エラーチェック
	if (fp == nullptr)
	{
		OutputDebugString("ファイルを開けない\n");
		throw (-1);
	}

	for (int i = 0; i < 19; i++)
	{
		fscanf_s(fp, "%[^,],%d,%[^,],%[^,],%d,%d,%d,%[^,],",
			Poke_id[i].NAME, 20,
			&Poke_id[i].HP,
			Poke_id[i].WEEK, 10,
			Poke_id[i].NOWEEK, 10,
			&Poke_id[i].RUN,
			&Poke_id[i].SIDE,
			&Poke_id[i].EVO, 
			Poke_id[i].SINKAMOTO, 20);
	}
	Action = false;
	fclose(fp);
}

void Pokemon::Update()
{

	i = card_d.GetCard();

}
void Pokemon::Draw() const
{
	DrawFormatString(0, 100, 0x000000, "%d", i);

	DrawFormatString(0, 0, 0x000000, "%s %d %s %s %d %d %d %s", Poke_id[i].NAME, Poke_id[i].HP, Poke_id[i].WEEK, Poke_id[i].NOWEEK, Poke_id[i].RUN, Poke_id[i].SIDE, Poke_id[i].EVO, Poke_id[i].SINKAMOTO);
}