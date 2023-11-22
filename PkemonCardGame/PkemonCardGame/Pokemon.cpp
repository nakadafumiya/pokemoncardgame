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

	////�t�@�C���ǂݍ���
	//FILE* fp;
	//fopen_s(&fp, "data/pokemon.csv", "r");

	//if (fp != NULL)
	//{
	//	for (int i = 0; i < 7; i++)
	//	{
	//		fscanf_s(fp, "%[^,],%d,%[^,],%[^,],%d,%[^,],%d,%d", pData[i].NAME,30, &pData[i].HP, pData[i].WEAK,10, pData[i].RESIST,10
	//			, &pData[i].EVO, pData[i].B_EVO,30, &pData[i].RETREAT, &pData[i].SIDE);
	//	}
	//	fclose(fp);
	//}
	//else //�t�@�C�����J���Ȃ�������Q�[�����I������
	//{
	//	DxLib_End();
	//}

	//�t�@�C���ǂݍ���
	std::ifstream ifs("data/pokemon.csv");
	//�t�@�C�����J���Ȃ�������Q�[�����I������
	if (ifs.fail())
	{
		DxLib_End();
	}
	char buff[1000];
	int i = 0;
	while (ifs.getline(buff,1000))
	{
		sscanf_s(buff, "%[^,],%d,%[^,],%[^,],%d,%[^,],%d,%d", pData[i].NAME, sizeof(pData[i].NAME), &pData[i].HP, pData[i].WEAK, sizeof(pData[i].WEAK), pData[i].RESIST, sizeof(pData[i].RESIST)
			, &pData[i].EVO, pData[i].B_EVO, sizeof(pData[i].B_EVO), &pData[i].RETREAT, &pData[i].SIDE);
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
}