#include "AbstractScene.h"
#include "DxLib.h"
#include "common.h"
#include "Title.h"
#include "PadInput.h"
#include "GameMainScene.h"
Title::Title()
{
	Gardevoir = LoadGraph("image/Title_Gardevoir.png");  //�T�[�i�C�g
	Budrex = LoadGraph("image/Title_Budrex.png");     //�R�N�o
	Arceus = LoadGraph("image/Title_Arceus.png");     //�A���Z�E�X
	Rayquaza = LoadGraph("image/Title_Rayquaza.png");   //���b�N�E�U

	TitleImage = LoadGraph("image/Title_Logo.png"); //�^�C�g�����
	BackTitle = LoadGraph("image/Title_Back.png");  //�^�C�g���w�i

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