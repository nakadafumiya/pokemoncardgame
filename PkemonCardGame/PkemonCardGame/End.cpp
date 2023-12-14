#include "End.h"
#include"DxLib.h"
#include"common.h"

End::End()
{
	Gardevoir = LoadGraph("image/Title_Gardevoir.png");  //�T�[�i�C�g
	Budrex = LoadGraph("image/Title_Budrex.png");     //�R�N�o
	Arceus = LoadGraph("image/Title_Arceus.png");     //�A���Z�E�X
	Rayquaza = LoadGraph("image/Title_Rayquaza.png");   //���b�N�E�U
	EndBack = LoadGraph("image/Title_Back.png");  //�w�i

	count = 0;
}

AbstractScene* End::Update()
{
	count++;
	if (100 <= count)
	{
		return nullptr;

	}
	return this;

}

void End::Draw()const
{
	SetFontSize(60);

	

	//�w�i�E�^�C�g��
	DrawGraph(0, 0, EndBack, TRUE);

	DrawString(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 3, "thank you for playing", 0x000000);
	//�|�P����
	DrawRotaGraph(SCREEN_WIDTH / 6 - 100, SCREEN_HEIGHT / 4 + 100, 0.6, 0, Gardevoir, TRUE);
	DrawRotaGraph(SCREEN_WIDTH / 8 - 100, SCREEN_HEIGHT / 2 + 250, 1, 0, Budrex, TRUE);//2.6

	DrawRotaGraph(SCREEN_WIDTH - 220, SCREEN_HEIGHT / 4, 0.7, 0, Rayquaza, TRUE);
	DrawRotaGraph(SCREEN_WIDTH - 100, SCREEN_HEIGHT / 2 + 250, 1.7, 0, Arceus, TRUE);
}