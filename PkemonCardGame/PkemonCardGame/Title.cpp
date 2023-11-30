#include "AbstractScene.h"
#include "DxLib.h"
#include "common.h"
#include "Title.h"
#include "PadInput.h"
#include "GameMainScene.h"

#define PI    3.1415926535897932384626433832795f

Title::Title()
{
	Gardevoir = LoadGraph("image/Title_Gardevoir.png");  //�T�[�i�C�g
	Budrex = LoadGraph("image/Title_Budrex.png");     //�R�N�o
	Arceus = LoadGraph("image/Title_Arceus.png");     //�A���Z�E�X
	Rayquaza = LoadGraph("image/Title_Rayquaza.png");   //���b�N�E�U
	
	GardevoirCard = LoadGraph("image/GardevoirCard1.png");  //�T�[�i�C�g
	BudrexCard = LoadGraph("image/BudrexCard.png");     //�R�N�o
	ArceusCard = LoadGraph("image/ArceusCard.png");     //�A���Z�E�X
	RayquazaCard = LoadGraph("image/RayquazaCard.png");   //���b�N�E�U

	TitleImage = LoadGraph("image/Title_Logo.png"); //�^�C�g�����
	BackTitle = LoadGraph("image/Title_Back.png");  //�^�C�g���w�i

	Carsol = LoadGraph("image/select.png"); 


	interval = 0;
	flg = false;
	JoyPadX = 0;
	JoyPadY = 0;
	selectX = 0;
	selectY = 0;
	
}

AbstractScene* Title::Update()
{
	if (flg == false)
	{
		if (interval < 30)interval++;
		JoyPadY = PAD_INPUT::GetPadThumbLY();

		if (JoyPadY > MARGIN && interval >= 30)
		{
			selectY--;
			interval = 0;
		}
		else if (JoyPadY < -MARGIN && interval >= 30)
		{
			selectY++;
			interval = 0;
		}

	

		if (selectY == 0 && PAD_INPUT::OnClick(XINPUT_BUTTON_B))
		{
			flg = true;
		}
		else if (selectY == 1 && PAD_INPUT::OnClick(XINPUT_BUTTON_B))
		{
			//return new GameMainScene();
		}

		if (selectY < 0)selectY = 1;
		if (selectY > 1)selectY = 0;
		if (JoyPadY < MARGIN && -MARGIN < JoyPadY && !PAD_INPUT::OnPressed(XINPUT_BUTTON_B))interval = 30;
	}
	

	if (flg == true)
	{
		if (interval < 30)interval++;
		JoyPadX = PAD_INPUT::GetPadThumbLX();
		if (JoyPadX > MARGIN && interval >= 30)
		{
			selectX--;
			interval = 0;
		}
		else if (JoyPadX < -MARGIN && interval >= 30)
		{
			selectX++;
			interval = 0;
		}
		if (selectX < 0)selectX = 1;
		if (selectX > 1)selectX = 0;
		if (JoyPadX < MARGIN && -MARGIN < JoyPadX && !PAD_INPUT::OnPressed(XINPUT_BUTTON_B))interval = 30;
	}


	
	
	return this;
}

void Title::Draw()const
{
	//�w�i�E�^�C�g��
	DrawGraph(0, 0, BackTitle, TRUE);
	DrawRotaGraph(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 4, 0.8, 0, TitleImage, TRUE);


	//�|�P����
	DrawRotaGraph(SCREEN_WIDTH / 6 - 100, SCREEN_HEIGHT / 4 + 100, 0.6, 0, Gardevoir, TRUE);
	DrawRotaGraph(SCREEN_WIDTH / 8 - 100, SCREEN_HEIGHT / 2 + 250, 1, 0, Budrex, TRUE);//2.6

	DrawRotaGraph(SCREEN_WIDTH - 220, SCREEN_HEIGHT / 4, 0.7, 0, Rayquaza, TRUE);
	DrawRotaGraph(SCREEN_WIDTH - 100, SCREEN_HEIGHT / 2 + 250, 1.7, 0, Arceus, TRUE);


	if (flg == false)
	{
		//�{�^�� �w���v �G���h
		SetFontSize(50);
		DrawString(SCREEN_WIDTH / 2 - 75, 750, "�V�ѕ�", 0xffffff);
		DrawString(SCREEN_WIDTH / 2 - 75, 850, "�G���h", 0xffffff);

		DrawGraph(SCREEN_WIDTH / 2 - 150, 720 + selectY * 100, Carsol, TRUE);
	}

	if (flg == true)
	{
		SetFontSize(50);
		//DrawString(SCREEN_WIDTH / 2 - 75, 550, "�f�b�L��I�����Ă�������", 0xffffff);

		//�J�[�h
		DrawRotaGraph(SCREEN_WIDTH / 5 + 260, SCREEN_HEIGHT / 2 + 220, 1, 0, GardevoirCard, TRUE);
		DrawRotaGraph(SCREEN_WIDTH / 5 + 410, SCREEN_HEIGHT / 2 + 220, 1, 0, BudrexCard, TRUE);

		DrawRotaGraph(SCREEN_WIDTH - 644, SCREEN_HEIGHT / 2 + 220, 1, 0, RayquazaCard, TRUE);
		DrawRotaGraph(SCREEN_WIDTH - 794, SCREEN_HEIGHT / 2 + 220, 1, 0, ArceusCard, TRUE);

		//DrawBox()
		//DrawRotaGraph(SCREEN_WIDTH / 2 - selectX * 150, 600,1,PI/2, Carsol, TRUE);
	}


	
	

	
	



}