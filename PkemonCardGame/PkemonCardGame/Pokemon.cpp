#include <fstream>
#include <iostream>
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
	i = 0;
	FILE* fp = nullptr;
	
	errno_t err = fopen_s(&fp, "data/Pokemon.txt", "r");

	// �G���[�`�F�b�N
	if (fp == nullptr)
	{
		OutputDebugString("�t�@�C�����J���Ȃ�\n");
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
	{
		//card_d.Hand_Card;
		/*if (card_d.Hand_Card > 19)
		{
			Poke_id[i].NAME;
			Poke_id[i].HP;
			Poke_id[i].WEEK;
			Poke_id[i].NOWEEK;
			Poke_id[i].RUN;
			Poke_id[i].SIDE;
			Poke_id[i].EVO;
			Poke_id[i].SINKAMOTO;
		}*/

		 if (CheckHitKey(KEY_INPUT_SPACE))
		 {
			//int i = Hand_Card;
		    i = GetRand(18);
			Poke_id[i].NAME;
			Poke_id[i].HP;
			Poke_id[i].WEEK;
			Poke_id[i].NOWEEK;
			Poke_id[i].RUN;
			Poke_id[i].SIDE;
			Poke_id[i].EVO;
			Poke_id[i].SINKAMOTO;
			
		 }

	}
}
void Pokemon::Draw() const
{
	DrawFormatString(0, 0, 0x000000, "%s %d %s %s %d %d %d %s", Poke_id[i].NAME, Poke_id[i].HP, Poke_id[i].WEEK, Poke_id[i].NOWEEK, Poke_id[i].RUN, Poke_id[i].SIDE, Poke_id[i].EVO, Poke_id[i].SINKAMOTO);
}