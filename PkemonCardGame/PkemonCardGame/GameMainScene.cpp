#include "Dxlib.h"
#include "GameMainScene.h"


GameMainScene::GameMainScene()
{
	NextTurn = false;
	Player = 0;
	Turn = START;
	Cr = GetColor(255, 255, 255);
}

AbstractScene* GameMainScene::Update()
{
	switch(Turn)
	{
	case START:
		
		if (!NextTurn/*==false*/)
		{
			Turn = MY_TURN;
		}
		else
		{
			Turn = ENEMY_TURN;
		}
		break;
	
	case MY_TURN:
		if (Player == 0)
		{
			//白色の値を取得
			Cr = GetColor(255, 255, 255);

			
			if (GetJoypadInputState(PAD_INPUT_1) == 1)
			{
				//手札見る
				return this;
			}
			if (GetJoypadInputState(PAD_INPUT_3) == 1)
			{
				//カードの詳細(横の画面にアップ)
			}
			if (GetJoypadInputState(PAD_INPUT_2) == 1)
			{
				//カードの使用(召喚)
			}
			if (GetJoypadInputState(PAD_INPUT_4) == 1)
			{
				//戻る
			}
			if (GetJoypadInputState(PAD_INPUT_START) == 1)
			{
				NextTurn = true;	
				break;
			}	
		}
		break;
	case ENEMY_TURN:
	   //白色の値を取得
		Cr = GetColor(255, 255, 255);
		
	  //文字の描画
		DrawString(960, 540, "敵のターン！", Cr);
		NextTurn = false;
	}
	return this;
}

void GameMainScene::Draw() const
{
	field.Draw();

	switch (Turn)
	{
	case START:
		DrawString(960, 540, "Battle Start", GetColor(255, 0, 0));
		break;

	case MY_TURN:
		if (Player == 0)
		{

			//文字列の描画
			DrawString(960, 540, "自分のターン！", Cr);
			DrawString(50, 100, "B:手札 Y:カードの詳細 X:使用(召喚) A:戻る START:ターンエンド", Cr);

			if (GetJoypadInputState(PAD_INPUT_1) == 1)
			{
				//手札見る
			}
			if (GetJoypadInputState(PAD_INPUT_3) == 1)
			{
				//カードの詳細(横の画面にアップ)
			}
			if (GetJoypadInputState(PAD_INPUT_2) == 1)
			{
				//カードの使用(召喚)
			}
			if (GetJoypadInputState(PAD_INPUT_4) == 1)
			{
				//戻る
			}
			if (GetJoypadInputState(PAD_INPUT_START) == 1)
			{
				DrawString(960, 540, "ターンエンド", Cr);
				break;
			}
		}
		break;
	case ENEMY_TURN:

		//文字の描画
		DrawString(960, 540, "敵のターン！", Cr);
	}
}