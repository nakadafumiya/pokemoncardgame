#include "Pokemon.h"
#include "DxLib.h"

Pokemon::Pokemon()
{
	FILE* fp;
	char fname[] = "Pokemon.xlsx";
	fp = fopen(fname, "r");

	fclose(fp); // ファイルを閉じる
	Action = false;
}

AbstractScene* Pokemon::Update()
{

	return ;
}

void Pokemon::Draw() const
{

}