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

	//kokuba = LoadGraph("images/OriginalMaterial/Pokemon_Card_D1_Before/�����΃o�h���b�N�XV.jpg");
	kokuba = LoadGraph("images/Pokemon_Card_D1/�����΃o�h���b�N�XV.png");
	rarutosu = LoadGraph("images/Pokemon_Card_D1/Ralts.png");
	dhianshi = LoadGraph("images/Pokemon_Card_D1/�f�B�A���V�[.png");
	gekkouga = LoadGraph("images/Pokemon_Card_D1/ShiningGreninja.png");
	kokuba_m = LoadGraph("images/Pokemon_Card_D1/�����΃o�h���b�N�XVMAX.png");
	kiruria = LoadGraph("images/Pokemon_Card_D1/Kirlia.png");
	sa_naito = LoadGraph("images/Pokemon_Card_D1/�T�[�i�C�g.png");
}

void Pokemon::Update(GameMainScene* a)
{

}
void Pokemon::Draw() const
{
	DrawFormatString(0, 100, 0x000000, "%d", Hand_Card);

	DrawFormatString(0, 0, 0x000000, "%s %d %s %s %d %d %d %s", 
		Poke_id[Hand_Card].NAME, 
		Poke_id[Hand_Card].HP,
		Poke_id[Hand_Card].WEEK,
		Poke_id[Hand_Card].NOWEEK, 
		Poke_id[Hand_Card].RUN, 
		Poke_id[Hand_Card].SIDE,
		Poke_id[Hand_Card].EVO, 
		Poke_id[Hand_Card].SINKAMOTO);
	//������
	if (Hand_Card < 4) 
	{
		DrawGraph(SCREEN_WIDTH/2-70, 630, kokuba, TRUE);
	}
	//�����g�X
	if (Hand_Card >= 4 && Hand_Card < 8)
	{
		DrawGraph(SCREEN_WIDTH / 2 - 70, 630, rarutosu, TRUE);
	}
	//�f�B�A���V�[
	if (Hand_Card == 8)
	{
		DrawGraph(SCREEN_WIDTH / 2 - 70, 630, dhianshi, TRUE);
	}
	//�Q�b�R�E�K
	if (Hand_Card == 9)
	{
		DrawGraph(SCREEN_WIDTH / 2 - 70, 630, gekkouga, TRUE);
	}
	//������VM
	if (Hand_Card >= 10 && Hand_Card < 14)
	{
		DrawGraph(SCREEN_WIDTH / 2 - 70, 630, kokuba_m, TRUE);
	}
	//�L�����A
	if (Hand_Card >=14 && Hand_Card < 17)
	{
		DrawGraph(SCREEN_WIDTH / 2 - 70, 630, kiruria, TRUE);
	}
	//�T�[�i�C�g
	if (Hand_Card >= 17 && Hand_Card < 19)
	{
		DrawGraph(SCREEN_WIDTH / 2 - 70, 630, sa_naito, TRUE);
	}
}