#include "AbstractScene.h"
#include "DxLib.h"
#include "common.h"
#include "Title.h"
#include "PadInput.h"
#include "GameMainScene.h"
Title::Title()
{
	Gardevoir = LoadGraph("image/Title_Gardevoir.png");  //サーナイト
	Budrex = LoadGraph("image/Title_Budrex.png");     //コクバ
	Arceus = LoadGraph("image/Title_Arceus.png");     //アルセウス
	Rayquaza = LoadGraph("image/Title_Rayquaza.png");   //レックウザ

	TitleImage = LoadGraph("image/Title_Logo.png"); //タイトル画面
	BackTitle = LoadGraph("image/Title_Back.png");  //タイトル背景

}

AbstractScene* Title::Update()
{

	if (PAD_INPUT::OnClick(XINPUT_BUTTON_A))
	{
		return new GameMainScene();
	}
	return this;
}

void Title::Draw()const
{
	DrawGraph(0, 0, BackTitle, TRUE);
	DrawRotaGraph(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 4, 0.8, 0, TitleImage, TRUE);


	DrawRotaGraph(SCREEN_WIDTH / 6, SCREEN_HEIGHT / 4 + 100, 0.6, 0, Gardevoir, TRUE);
	DrawRotaGraph(SCREEN_WIDTH / 8 - 100, SCREEN_HEIGHT / 2 + 250, 2.6, 0, Budrex, TRUE);


	DrawRotaGraph(SCREEN_WIDTH - 220, SCREEN_HEIGHT / 4 , 0.7, 0, Rayquaza, TRUE);
	DrawRotaGraph(SCREEN_WIDTH - 100, SCREEN_HEIGHT / 2 + 250, 1.7, 0, Arceus, TRUE);
	
}