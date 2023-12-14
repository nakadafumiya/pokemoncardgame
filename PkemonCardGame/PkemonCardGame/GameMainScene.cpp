#include "Dxlib.h"
#include "GameMainScene.h"
#include "Card_Deck.h"
#include "PadInput.h"

GameMainScene::GameMainScene()
{
	TurnCount = 0;
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
		
			Turn = MY_TURN;
		
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
			if (PAD_INPUT::OnClick(PAD_INPUT_START)|| CheckHitKey(KEY_INPUT_SPACE))
			{
				int A = 0;
				if (KEY_INPUT_SPACE) { A++; }
				else { A = 0; } //Ａボタンが離されたら
				TurnCount++;
				//一瞬だけ反応させたい
				if (A == 1) 
				{
					Turn = ENEMY_TURN; 
				}
				break;
			}	
		}
		break;
	case ENEMY_TURN:
	   
		Cr = GetColor(255, 255, 255);
		
		if (PAD_INPUT::OnClick(PAD_INPUT_START) || CheckHitKey(KEY_INPUT_G))
		{
			TurnCount++;
			Turn = MY_TURN;
		}

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
			DrawBoxAA(950, 500, 1200, 600, 0x57AF72, true);
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
			if (GetJoypadInputState(PAD_INPUT_START) == 1)
			{
				//戻る
			}
			if (PAD_INPUT::OnClick(PAD_INPUT_A) || CheckHitKey(KEY_INPUT_SPACE))
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