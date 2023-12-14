#include "AbstractScene.h"
#include "DxLib.h"
#include "common.h"
#include "Title.h"
#include "PadInput.h"
#include "GameMainScene.h"
#include"End.h"


#define PI    3.1415926535897932384626433832795f

Title::Title()
{
	Gardevoir = LoadGraph("image/Title_Gardevoir.png");  //サーナイト
	Budrex = LoadGraph("image/Title_Budrex.png");     //コクバ
	Arceus = LoadGraph("image/Title_Arceus.png");     //アルセウス
	Rayquaza = LoadGraph("image/Title_Rayquaza.png");   //レックウザ
	
	GardevoirCard = LoadGraph("image/GardevoirCard1.png");  //サーナイト
	BudrexCard = LoadGraph("image/BudrexCard.png");     //コクバ
	ArceusCard = LoadGraph("image/ArceusCard.png");     //アルセウス
	RayquazaCard = LoadGraph("image/RayquazaCard.png");   //レックウザ

	TitleImage = LoadGraph("image/Title_Logo.png"); //タイトル画面
	BackTitle = LoadGraph("image/Title_Back.png");  //タイトル背景

	Carsol = LoadGraph("image/select.png"); 


	interval = 0;
	flg = 0;
	deckflg = 0;
	JoyPadX = 0;
	JoyPadY = 0;
	selectX = 0;
	selectY = 0;
	count = 0;
	ruleimage1 = LoadGraph("image/rule (2).png");
	ruleimage2 = LoadGraph("image/rule2 (2).png");
	
}

AbstractScene* Title::Update()
{
	//タイトル
	if (flg == 0)
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
			flg = 1;
			//return new GameMainScene();	
		}
		else if (selectY == 1 && PAD_INPUT::OnClick(XINPUT_BUTTON_B))
		{
			flg = 2;
		}
		if (selectY == 2 && PAD_INPUT::OnClick(XINPUT_BUTTON_B))
		{
			return new End();
		}

		if (selectY < 0)selectY = 2;
		if (selectY > 2)selectY = 0;
		if (JoyPadY < MARGIN && -MARGIN < JoyPadY && !PAD_INPUT::OnPressed(XINPUT_BUTTON_B))interval = 30;
	}
	
	//デッキ選択
	if (flg == 1)
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
		
		count++;

		if(selectX == 0 && PAD_INPUT::OnClick(XINPUT_BUTTON_B)&& 1<count)
		{
			
			return new GameMainScene();	
			count = 0;
		}
		else if (selectX == 1 && PAD_INPUT::OnClick(XINPUT_BUTTON_B) &&1< count)
		{
			return new GameMainScene();
			count = 0;
		}
		else if (PAD_INPUT::OnClick(XINPUT_BUTTON_A) && 1 < count)
		{
			flg = 0;
			count = 0;
		}
		if (selectX < 0)selectX = 1;
		if (selectX > 1)selectX = 0;
		if (JoyPadX < MARGIN && -MARGIN < JoyPadX && !PAD_INPUT::OnPressed(XINPUT_BUTTON_B))interval = 30;
	}

	if (flg == 2)
	{
		if (PAD_INPUT::OnClick(XINPUT_BUTTON_A) && 1<count)
		{
			flg = 0;
		}
		count++;
	}
	
	
	return this;
}

void Title::Draw()const
{
	//背景・タイトル
	DrawGraph(0, 0, BackTitle, TRUE);


	if (flg == 0)
	{
		DrawRotaGraph(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 4, 0.8, 0, TitleImage, TRUE);


		//ポケモン
		DrawRotaGraph(SCREEN_WIDTH / 6 - 100, SCREEN_HEIGHT / 4 + 100, 0.6, 0, Gardevoir, TRUE);
		DrawRotaGraph(SCREEN_WIDTH / 8 - 100, SCREEN_HEIGHT / 2 + 250, 1, 0, Budrex, TRUE);//2.6

		DrawRotaGraph(SCREEN_WIDTH - 220, SCREEN_HEIGHT / 4, 0.7, 0, Rayquaza, TRUE);
		DrawRotaGraph(SCREEN_WIDTH - 100, SCREEN_HEIGHT / 2 + 250, 1.7, 0, Arceus, TRUE);

		//ボタン ヘルプ エンド
		SetFontSize(50);
		DrawString(SCREEN_WIDTH / 2 - 75, 650, "スタート", 0xffffff);
		DrawString(SCREEN_WIDTH / 2 - 75, 750, "遊び方", 0xffffff);
		DrawString(SCREEN_WIDTH / 2 - 75, 850, "エンド", 0xffffff);

		DrawGraph(SCREEN_WIDTH / 2 - 150, 620 + selectY * 100, Carsol, TRUE);
	}

	if (flg == 1)
	{
		DrawRotaGraph(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 4, 0.8, 0, TitleImage, TRUE);


		//ポケモン
		DrawRotaGraph(SCREEN_WIDTH / 6 - 100, SCREEN_HEIGHT / 4 + 100, 0.6, 0, Gardevoir, TRUE);
		DrawRotaGraph(SCREEN_WIDTH / 8 - 100, SCREEN_HEIGHT / 2 + 250, 1, 0, Budrex, TRUE);//2.6

		DrawRotaGraph(SCREEN_WIDTH - 220, SCREEN_HEIGHT / 4, 0.7, 0, Rayquaza, TRUE);
		DrawRotaGraph(SCREEN_WIDTH - 100, SCREEN_HEIGHT / 2 + 250, 1.7, 0, Arceus, TRUE);


		SetFontSize(50);
		//DrawString(SCREEN_WIDTH / 2 - 75, 550, "デッキを選択してください", 0xffffff);
	
		//カード
		DrawRotaGraph(SCREEN_WIDTH / 5 + 260, SCREEN_HEIGHT / 2 + 220, 1, 0, GardevoirCard, TRUE);
		DrawRotaGraph(SCREEN_WIDTH / 5 + 410, SCREEN_HEIGHT / 2 + 220, 1, 0, BudrexCard, TRUE);

		DrawRotaGraph(SCREEN_WIDTH - 644, SCREEN_HEIGHT / 2 + 220, 1, 0, RayquazaCard, TRUE);
		DrawRotaGraph(SCREEN_WIDTH - 794, SCREEN_HEIGHT / 2 + 220, 1, 0, ArceusCard, TRUE);

		
		DrawRotaGraph(SCREEN_WIDTH / 2+265- selectX * 500, 600,1,PI/2, Carsol, TRUE);
	}

	if (flg == 2)
	{
		SetFontSize(50);
		DrawString(SCREEN_WIDTH / 5-100, 250, "自分の番にすること", 0x00000);
		DrawString(SCREEN_WIDTH / 2 + 200, 250, "ターンの流れ", 0x00000);
		SetFontSize(100);
		DrawString(SCREEN_WIDTH/2-200,100, "遊び方",0x000000);
		DrawRotaGraph(SCREEN_WIDTH/4, SCREEN_HEIGHT/2, 1, 0, ruleimage1, TRUE);
		DrawRotaGraph(SCREEN_WIDTH / 2+400, SCREEN_HEIGHT / 2, 1, 0, ruleimage2, TRUE);
	}
	
	SetFontSize(16);

	
	



}