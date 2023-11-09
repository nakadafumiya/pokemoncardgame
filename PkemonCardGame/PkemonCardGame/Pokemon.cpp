#include "Pokemon.h"
#include "DxLib.h"

Pokemon::Pokemon()
{
	FILE* fp;
	char fname[] = "Pokemon.xlsx";
	fp = fopen(fname, "r");

	fclose(fp); // ƒtƒ@ƒCƒ‹‚ð•Â‚¶‚é
	Action = false;
}

AbstractScene* Pokemon::Update()
{

	return ;
}

void Pokemon::Draw() const
{

}