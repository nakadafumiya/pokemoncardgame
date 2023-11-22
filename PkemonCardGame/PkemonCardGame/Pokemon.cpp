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
	/*std::ifstream ifs("data/Pokemon.txt");
	if (ifs.is_open()) {
		std::string a;
		ifs >> a;
		ifs.close();
	}*/
	errno_t err = fopen_s(&fp, "C:/Pokemon.txt", "r");
	if (fp != nullptr)
	for (int i = 0; i < 20; i++)
	{
		fscanf_s(fp, "%s,%d,%s,%s,%d,%d,%d,%s", Poke_id[0].NAME, 20, &Poke_id[0].HP, Poke_id[0].WEEK, 10, Poke_id[0].NOWEEK, 10, &Poke_id[0].RUN, &Poke_id[0].SIDE, &Poke_id[0].EVO, Poke_id[0].SINKAMOTO, 20);
	}
	Action = false;
	if (fp == NULL)
	{
		int fclose(FILE * fp);
		Action = false;
	}
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
	DrawFormatString(0, 0, 0x00FFFF, "%s %d %s %s %d %d %d %s", Poke_id[0].NAME, Poke_id[0].HP, Poke_id[0].WEEK, Poke_id[0].NOWEEK, Poke_id[0].RUN, Poke_id[0].SIDE, Poke_id[0].EVO, Poke_id[0].SINKAMOTO);
}