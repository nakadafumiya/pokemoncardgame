#include "Dxlib.h"
#include "GameMainScene.h"
#include "Card_Deck.h"

GameMainScene::GameMainScene()
{
	NextTurn = false;
	Player = 0;
	Turn = START;
	Cr = GetColor(255, 255, 255);

}

AbstractScene* GameMainScene::Update()
{
	hand.Update();
	side.Update();

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
			
			Cr = GetColor(255, 255, 255);

			
			if (GetJoypadInputState(PAD_INPUT_X) == 1)
			{
				//手札
				return this;
			}
			if (GetJoypadInputState(PAD_INPUT_Y) == 1)
			{
				//カードの使用・召喚
			}
			if (GetJoypadInputState(PAD_INPUT_B) == 1)
			{
				//カードの詳細表示(横のスペース)
			}
			if (GetJoypadInputState(PAD_INPUT_A) == 1)
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
	   
		Cr = GetColor(255, 255, 255);
		
	  
		DrawString(960, 540, "ENEMY TURN", Cr);
		NextTurn = false;
	}



	card_deck.Update();
	pokemon.Update();
	return this;
}

void GameMainScene::Draw() const
{
	field.Draw();
	hand.Draw();
	pokemon.Draw();

	switch (Turn)
	{
	case START:
		DrawString(960, 540, "Battle Start", GetColor(255, 0, 0));
		break;

	case MY_TURN:
		if (Player == 0)
		{

			
			DrawString(960, 540, "YOUR TURN", Cr);
			DrawString(50, 100, "X:手札　 Y:カードの使用 B:カードの詳細　 A:戻る 　START:ターンエンド　", Cr);

			if (GetJoypadInputState(PAD_INPUT_X) == 1)
			{
				//手札
			}
			if (GetJoypadInputState(PAD_INPUT_Y) == 1)
			{
				//カードの使用・召喚
			}
			if (GetJoypadInputState(PAD_INPUT_B) == 1)
			{
				//カードの詳細表示(横のスペース)
			}
			if (GetJoypadInputState(PAD_INPUT_A) == 1)
			{
				//戻る
			}
			if (GetJoypadInputState(PAD_INPUT_START) == 1)
			{
				DrawString(960, 540, "TURN END", Cr);
				break;
			}
		}
		break;
	case ENEMY_TURN:

		
		DrawString(960, 540, "ENEMY TURN", Cr);
	}
	side.Draw();
}