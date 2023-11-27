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
	@9
	GardevoirCard = LoadGraph("image/GardevoirCard.png");  //�T�[�i�C�g
	BudrexCard = LoadGraph("images/Pokemon_Card_D1/Calyrex_VMAX.png");     //�R�N�o
	ArceusCard = LoadGraph("images/Pokemon_Card_D2/Arceus_VSTAR.png");     //�A���Z�E�X
	RayquazaCard = LoadGraph("images/Pokemon_Card_D2/Rayquaza_VMAX.png");   //���b�N�E�U

	TitleImage = LoadGraph("image/Title_Logo.png"); //�^�C�g�����
	BackTitle = LoadGraph("image/Title_Back.png");  //�^�C�g���w�i

	interval = 0;
	JoyPadX = 0;
	JoyPadY = 0;
	select = 0;

}

AbstractScene* Title::Update()
{

	/*if (interval < 30)interval++;
	JoyPadX = PAD_INPUT::GetPadThumbLX();
	JoyPadY = PAD_INPUT::GetPadThumbLY();

	if (JoyPadY > MARGIN && interval >= 30)
	{
		select--;
		interval = 0;
	}
	else if (JoyPadY < -MARGIN && interval >= 30)
	{
		select++;
		interval = 0;
	}

	if (JoyPadY < MARGIN && -MARGIN < JoyPadY && !PAD_INPUT::OnPressed(XINPUT_BUTTON_B))interval = 30;
	
	if (select == 0)return new GameMainScene();

*/









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
	
	//�J�[�h  �傫��*1.3

	//DrawRotaGraph(SCREEN_WIDTH / 5 + 50, SCREEN_HEIGHT / 2 + 150, 1.3, 0, GardevoirCard, TRUE);
	DrawRotaGraph(300, 300,0.5,0, GardevoirCard, TRUE);
	//DrawGraph(SCREEN_WIDTH / 5 + 100, SCREEN_HEIGHT/2 + 150, GardevoirCard, TRUE);
	//DrawGraph(100, 0, BudrexCard, TRUE);
	//DrawGraph(200, 200, RayquazaCard, TRUE);
	//DrawGraph(300, 300, ArceusCard, TRUE);




}