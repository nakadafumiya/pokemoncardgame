#include <fstream>
#include <iostream>
#include "Pokemon.h"
#include <stdio.h>
#include "DxLib.h"
#include <stdlib.h>	
#include <fstream>
#define N 256
#define ROW 20

Pokemon::Pokemon()
{
	Action = false;

	////ファイル読み込み
	//FILE* fp;
	//fopen_s(&fp, "data/pokemon.csv", "r");
	//if (fp != NULL)
	//{
	//	for (int i = 0; i < 7; i++)
	//	{
	//		fscanf_s(fp, "%[^,],%d,%[^,],%[^,],%d,%[^,],%d,%d", Poke_id[i].NAME, sizeof(Poke_id[i].NAME), &Poke_id[i].HP, Poke_id[i].WEAK, sizeof(Poke_id[i].WEAK), Poke_id[i].NOWEEK, sizeof(Poke_id[i].NOWEEK)
	//			, &Poke_id[i].EVO, Poke_id[i].SINKAMOTO, sizeof(Poke_id[i].SINKAMOTO), &Poke_id[i].RUN, &Poke_id[i].SIDE);
	//	}
	//	fclose(fp);
	//}
	//else //ファイル読み込みに失敗したら、ゲームを終了する
	//{
	//	DxLib_End();
	//}

	//ファイル読み込み
	std::ifstream ifs("data/pokemon.csv");
	//ファイル読み込みに失敗したら、ゲームを終了する
	if (ifs.fail())
	{
		DxLib_End();
	}
	char buff[1000];
	int i = 0;
	while (ifs.getline(buff,1000))
	{
		sscanf_s(buff, "%[^,],%d,%[^,],%[^,],%d,%[^,],%d,%d", Poke_id[i].NAME, sizeof(Poke_id[i].NAME), &Poke_id[i].HP, Poke_id[i].WEAK, sizeof(Poke_id[i].WEAK), Poke_id[i].NOWEEK, sizeof(Poke_id[i].NOWEEK)
			, &Poke_id[i].EVO, Poke_id[i].SINKAMOTO, sizeof(Poke_id[i].SINKAMOTO), &Poke_id[i].RUN, &Poke_id[i].SIDE);
		i++;
	}
	ifs.close();
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
	for (int i = 0; i < 7; i++)
	{
		DrawFormatString(0, 0 + 20 * i, 0x000000, "%s %d %s %s %d %s %d %d", Poke_id[i].NAME, Poke_id[i].HP, Poke_id[i].WEAK
			, Poke_id[i].NOWEEK, Poke_id[i].EVO, Poke_id[i].SINKAMOTO, Poke_id[i].RUN, Poke_id[i].SIDE);
	}
}