#include "Side.h"
#include "AbstractScene.h"
#include "DxLib.h"
#include"common.h"


Side::Side()
{
	BackCard = LoadGraph("");

	for (count = 1; count <= 6; ++count)
	{
		side[count];
	}
}
//メンバ変数の値を書き換えるのがアップデート関数
AbstractScene* Side::Update()
{





	return 0;
}

//描画処理のみを行う関数
void Side::Draw() const
{
	

}