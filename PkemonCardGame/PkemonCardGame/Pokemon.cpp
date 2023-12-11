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
	//デッキ１のファイル読み込み
	errno_t err = fopen_s(&fp, "data/Pokemon1.txt", "r");

	//エラーが出た時にチェックしやすいよう
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

	//デッキ２のファイル読み込み
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

	//デッキ１画像
	kokuba = LoadGraph("images/Pokemon_Card_D1/こくばバドレックスV.png");
	rarutosu = LoadGraph("images/Pokemon_Card_D1/Ralts.png");
	dhianshi = LoadGraph("images/Pokemon_Card_D1/ディアンシー.png");
	gekkouga = LoadGraph("images/Pokemon_Card_D1/ShiningGreninja.png");
	//デッキ２画像
	aruseusu = LoadGraph("images/Pokemon_Card_D2/アルセウスV.png");
	rekkuza = LoadGraph("images/Pokemon_Card_D2/レックウザV.png");
	mafokushi = LoadGraph("images/Pokemon_Card_D2/マフォクシーV.png");
	neoranto = LoadGraph("images/Pokemon_Card_D2ネオラントV.png");
	karubou = LoadGraph("images/Pokemon_Card_D2/カルボウ.png");
	bakettya = LoadGraph("images/Pokemon_Card_D2/バケッチャ.png");
	hoshigarisu = LoadGraph("images/Pokemon_Card_D2/ホシガリス.png");
	hi_doran = LoadGraph("images/Pokemon_Card_D2/かがやくヒードラン.png");

}

void Pokemon::Update(GameMainScene* a)
{
	
}
//ポケモンカードの表示
void Pokemon::Draw() const
{
	DrawFormatString(0, 100, 0x000000, "%d", Hand_Card);

	DrawFormatString(0, 0, 0x000000, "%s %d %d ", 
		Poke_id2[Hand_Card].NAME, 
		Poke_id2[Hand_Card].HP,
		Poke_id2[Hand_Card].SIDE);
	// //こくば
	// if (Hand_Card < 4) 
	// {
	// 	DrawGraph(SCREEN_WIDTH/2-70, 630, kokuba, TRUE);
	// }
	// //ラルトス
	// if (Hand_Card >= 4 && Hand_Card < 8)
	// {
	// 	DrawGraph(SCREEN_WIDTH / 2 - 70, 630, rarutosu, TRUE);
	// }
	// //ディアンシー
	// if (Hand_Card == 8)
	// {
	// 	DrawGraph(SCREEN_WIDTH / 2 - 70, 630, dhianshi, TRUE);
	// }
	// //ゲッコウガ
	// if (Hand_Card == 9)
	// {
	// 	DrawGraph(SCREEN_WIDTH / 2 - 70, 630, gekkouga, TRUE);
	// }
}

//デッキ１ポケモンの技条件
int Pokemon::Battle1(int id)
{
	//こくば
	if (id < 4)
	{
		if (ENE <= 1)
		{
			return 10;
		}
	}
	//ラルトス
	if (id >= 4 && id < 8)
	{
		if (ENE <= 1)
		{
			return 10;
		}
	}
	//ディアンシー
	if (id == 8)
	{
		if (ENE <= 1)
		{
			return 20;
		}
	}
	//ゲッコウガ
	if (id == 9)
	{
		if (ENE <= 3)
		{
			ENE = -2;
			return 90;
		}
	}
}
//デッキ２のポケモンの技条件
int Pokemon::Battle2(int id)
{
	//アルセウス
	if (id < 3)
	{
		if (ENE <= 3)
		{
			return 130;
		}
	}
	//レックウザ
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
	//マフォクシー
	if (id >= 5 && id < 7)
	{
		if (F_ENE <= 3 || F_ENE <= 2 && E_ENE <= 1)
		{
			return 120;
		}
	
	}
	//ネオラント
	if (id == 7)
	{
		
	}
	//カルボウ
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
	//バケッチャ
	if (id == 10)
	{
		if (F_ENE <= 2 || E_ENE <= 2)
		{
			return 20;
		}
	}
	//ホシガリス
	if (id == 11)
	{
		if (F_ENE <= 2 || E_ENE <= 2)
		{
			return 20;
		}
	}
	//ヒードラン
	if (id == 12)
	{
		if (F_ENE <= 3 || F_ENE <= 2 && E_ENE <= 1 || F_ENE <= 1 && E_ENE <= 2)
		{
			return 70;
		}
	}
}



