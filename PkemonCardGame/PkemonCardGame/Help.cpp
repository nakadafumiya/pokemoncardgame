#include "Help.h"
#include"DxLib.h"
#include"GameMainScene.h"
#include"PadInput.h"


Help::Help()
{
	image = LoadGraph("image/rule (2).png");
	image2 = LoadGraph("image/rule2 (2).png");
	Backimage = LoadGraph("image/Title_Back.png");
}

AbstractScene* Help::Update()
{
	if (PAD_INPUT::OnClick(XINPUT_BUTTON_A))
	{
		
	}
	return this;
}

void Help::Draw()const
{
	//背景・タイトル
	
}
