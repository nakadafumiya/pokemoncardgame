#include "Side.h"
#include "AbstractScene.h"
#include "DxLib.h"
#include"common.h"
#include"PadInput.h"

#define PI    3.1415926535897932384626433832795f

Side::Side()
{
	BackCard = LoadGraph("images/Pokemon_Card_D1/CardBack.png");


	for (count = 0; count <= 5; ++count)
	{
		side[count];
	}
}
//メンバ変数の値を書き換えるのがアップデート関数
AbstractScene* Side::Update()
{
	if (PAD_INPUT::OnClick(XINPUT_BUTTON_Y))
	{
		count--;
	}
	return 0;
}

//描画処理のみを行う関数
void Side::Draw() const
{
	//player サイド

	DrawFormatString(0,0,0x000000,"%d",count);
	
	if (0 < count)
	{
		DrawRotaGraph(470, 959, 1, 0, BackCard, FALSE);//奥下
	}
	if (1 < count)
	{
		DrawRotaGraph(470, 799, 1, 0, BackCard, FALSE);//奥中
	}
	if (2 < count)
	{
		DrawRotaGraph(470, 639, 1, 0, BackCard, FALSE);//奥上
	}
	if (3 < count)
	{
		DrawRotaGraph(495, 935, 1, 0, BackCard, FALSE);//手前下
	}
	if (4 < count) 
	{
		DrawRotaGraph(495, 775, 1, 0, BackCard, FALSE);//手前中
	}
	if (5 < count) 
	{
		DrawRotaGraph(495, 615, 1, 0, BackCard, FALSE);//手前上
	}
	

	//敵　サイド
	DrawRotaGraph(1460, 420, 1, PI, BackCard, FALSE);//奥上
	DrawRotaGraph(1460, 260, 1, PI, BackCard, FALSE);//奥中
	DrawRotaGraph(1460, 100, 1, PI, BackCard, FALSE);//奥下

	DrawRotaGraph(1435, 453, 1, PI, BackCard, FALSE);//手前上
	DrawRotaGraph(1435, 293, 1, PI, BackCard, FALSE);//手前中
	DrawRotaGraph(1435, 133, 1, PI, BackCard, FALSE);//手前下
}