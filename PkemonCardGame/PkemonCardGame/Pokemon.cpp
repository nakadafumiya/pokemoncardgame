#include <fstream>
#include <iostream>
#include "Pokemon.h"
#include "DxLib.h"

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
	//		fscanf_s(fp, "%[^,],%d,%[^,],%[^,],%d,%[^,],%d,%d", pData[i].NAME,30, &pData[i].HP, pData[i].WEAK,10, pData[i].RESIST,10
	//			, &pData[i].EVO, pData[i].B_EVO,30, &pData[i].RETREAT, &pData[i].SIDE);
	//	}
	//	fclose(fp);
	//}
	//else //ファイルが開けなかったらゲームを終了する
	//{
	//	DxLib_End();
	//}

	//ファイル読み込み
	std::ifstream ifs("data/pokemon.csv");
	//ファイルが開けなかったらゲームを終了する
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

	
}

void Pokemon::Draw() const
{
}