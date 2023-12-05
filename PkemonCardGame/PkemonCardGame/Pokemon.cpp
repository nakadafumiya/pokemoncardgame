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
	
	errno_t err = fopen_s(&fp, "data/Pokemon.txt", "r");

	//
	if (fp == nullptr)
	{
		OutputDebugString("images/Pokemon_Card_D2/CardBack.png");
		throw (-1);
	}

	for (int i = 0; i < 19; i++)
	{
		fscanf_s(fp, "%[^,],%d,%[^,],%[^,],%[^,],%d,%d,%d,%[^,],",
			Poke_id[i].NAME, 20,
			&Poke_id[i].HP,
			Poke_id[i].TYPE, 10,
			Poke_id[i].WEEK, 10,
			Poke_id[i].NOWEEK, 10,
			&Poke_id[i].RUN,
			&Poke_id[i].SIDE,
			&Poke_id[i].EVO, 
			Poke_id[i].SINKAMOTO, 20);
	}
	Action = false;
	fclose(fp);

	//kokuba = LoadGraph("images/OriginalMaterial/Pokemon_Card_D1_Before/こくばバドレックスV.jpg");
	kokuba = LoadGraph("images/Pokemon_Card_D1/こくばバドレックスV.png");
	rarutosu = LoadGraph("images/Pokemon_Card_D1/Ralts.png");
	dhianshi = LoadGraph("images/Pokemon_Card_D1/ディアンシー.png");
	gekkouga = LoadGraph("images/Pokemon_Card_D1/ShiningGreninja.png");
	kokuba_m = LoadGraph("images/Pokemon_Card_D1/こくばバドレックスVMAX.png");
	kiruria = LoadGraph("images/Pokemon_Card_D1/Kirlia.png");
	sa_naito = LoadGraph("images/Pokemon_Card_D1/サーナイト.png");
}

void Pokemon::Update(GameMainScene* a)
{

}

void Pokemon::Draw() const
{
	DrawFormatString(0, 100, 0x000000, "%d", Hand_Card);

	DrawFormatString(0, 0, 0x000000, "%s %d %s %s %s %d %d %d %s", 
		Poke_id[Hand_Card].NAME, 
		Poke_id[Hand_Card].HP,
		Poke_id[Hand_Card].TYPE,
		Poke_id[Hand_Card].WEEK,
		Poke_id[Hand_Card].NOWEEK, 
		Poke_id[Hand_Card].RUN, 
		Poke_id[Hand_Card].SIDE,
		Poke_id[Hand_Card].EVO, 
		Poke_id[Hand_Card].SINKAMOTO);
	//こくば
	if (Hand_Card < 4) 
	{
		DrawGraph(SCREEN_WIDTH/2-70, 630, kokuba, TRUE);
	}
	//こくばVM
	if (Hand_Card >= 4 && Hand_Card < 8)
	{
		DrawGraph(SCREEN_WIDTH / 2 - 70, 630, kokuba_m, TRUE);
	}
	//ラルトス
	if (Hand_Card >=8 && Hand_Card <12)
	{
		DrawGraph(SCREEN_WIDTH / 2 - 70, 630, rarutosu, TRUE);
	}
	//キルリア
	if (Hand_Card >= 12 && Hand_Card < 15)
	{
		DrawGraph(SCREEN_WIDTH / 2 - 70, 630, kiruria, TRUE);
	}
	//サーナイト
	if (Hand_Card >= 15 && Hand_Card < 17)
	{
		DrawGraph(SCREEN_WIDTH / 2 - 70, 630, sa_naito, TRUE);
	}
	//ディアンシー
	if (Hand_Card ==17)
	{
		DrawGraph(SCREEN_WIDTH / 2 - 70, 630, dhianshi, TRUE);
	}
	//ゲッコウガ
	if (Hand_Card == 18)
	{
		DrawGraph(SCREEN_WIDTH / 2 - 70, 630, gekkouga, TRUE);
	}
}

//int Pokemon::Weak() const
//{
//
//}


