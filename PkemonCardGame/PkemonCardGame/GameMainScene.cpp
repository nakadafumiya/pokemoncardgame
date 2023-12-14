#include "Dxlib.h"
#include "GameMainScene.h"
#include "Card_Deck.h"
#include "Pokemon.h"
#include "PadInput.h"
#include"Help.h"

Pokemon poke;

GameMainScene::GameMainScene()
{
	NextTurn = false;
	Battlefield = true;
	Player = 0;
	Turn = START;
	Cr = GetColor(255, 255, 255);

	helpimage1 = LoadGraph("image/rule (2).png");
	helpimage2 = LoadGraph("image/rule2 (2).png");
	Backimage = LoadGraph("image/Title_Back.png");

	HelpFlag = false;
}

AbstractScene* GameMainScene::Update()
{
	player.Update();
	cpu.Update();
	side.Update();
	end.Update();

	if (PAD_INPUT::OnClick(XINPUT_BUTTON_START))
	{
		HelpFlag=true;
	}

	if (HelpFlag == false)
	{
		switch (Turn)
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
				//���F�̒l���擾
				Cr = GetColor(255, 255, 255);


				if (GetJoypadInputState(PAD_INPUT_1) == 1)
				{
					//��D����
					return this;
				}
				if (GetJoypadInputState(PAD_INPUT_3) == 1)
				{
					//�J�[�h�̏ڍ�(���̉�ʂɃA�b�v)
				}
				if (GetJoypadInputState(PAD_INPUT_2) == 1)
				{
					//�J�[�h�̎g�p(����)
				}
				if (GetJoypadInputState(PAD_INPUT_4) == 1)
				{
					//�߂�
				}
				if (GetJoypadInputState(PAD_INPUT_START) == 1)
				{
					NextTurn = true;
					break;
				}
			}
			break;
		case ENEMY_TURN:
			//���F�̒l���擾
			Cr = GetColor(255, 255, 255);

			//�����̕`��
			  //DrawString(960, 540, "�G�̃^�[���I", Cr);
			NextTurn = false;
		}
	}
	if (HelpFlag == true)
	{
		if (PAD_INPUT::OnClick(XINPUT_BUTTON_A))
		{
			HelpFlag = false;
		}
	}



	card_deck.Update(this);
	pokemon.Update(this);
	return this;
}

void GameMainScene::Draw() const
{
	
	
	
	if (HelpFlag == false)
	{
		field.Draw();
		card_deck.Draw();
		pokemon.Draw();

		switch (Turn)
		{
		case START:
			//DrawString(960, 540, "Battle Start", GetColor(255, 0, 0));
			break;

		case MY_TURN:
			if (Player == 0)
			{

				//������̕`��
				//DrawString(960, 540, "�����̃^�[���I", Cr);
				//DrawString(50, 100, "B:��D Y:�J�[�h�̏ڍ� X:�g�p(����) A:�߂� START:�^�[���G���h", Cr);

				if (GetJoypadInputState(PAD_INPUT_1) == 1)
				{
					//��D����
				}
				if (GetJoypadInputState(PAD_INPUT_3) == 1)
				{
					//�J�[�h�̏ڍ�(���̉�ʂɃA�b�v)
				}
				if (GetJoypadInputState(PAD_INPUT_2) == 1)
				{
					//�J�[�h�̎g�p(����)
				}
				if (GetJoypadInputState(PAD_INPUT_4) == 1)
				{
					//�߂�
				}
				if (GetJoypadInputState(PAD_INPUT_START) == 1)
				{
					//DrawString(960, 540, "�^�[���G���h", Cr);
					break;
				}
			}
			break;
		case ENEMY_TURN:

			//�����̕`��
			DrawString(960, 540, "ENEMY TURN", Cr);
		}
		side.Draw();
		player.Draw();
		cpu.Draw();
	}

	if (HelpFlag == true)
	{
		DrawGraph(0, 0, Backimage, TRUE);

		SetFontSize(50);
		DrawString(SCREEN_WIDTH / 5 - 100, 250, "自分の番にすること", 0x00000);
		DrawString(SCREEN_WIDTH / 2 + 200, 250, "ターンの流れ", 0x00000);
		SetFontSize(100);
		DrawString(SCREEN_WIDTH / 2 - 200, 100, "遊び方", 0x000000);
		DrawRotaGraph(SCREEN_WIDTH / 4, SCREEN_HEIGHT / 2, 1, 0, helpimage1, TRUE);
		DrawRotaGraph(SCREEN_WIDTH / 2 + 400, SCREEN_HEIGHT / 2, 1, 0, helpimage2, TRUE);

		SetFontSize(30);
		DrawString(0, 1000, "Aボタンで戻る", 0x000000);
	}
	
	
}
//ポケモンをバトルフィールドに置く条件
void GameMainScene::Battlepoke(int Card)
{
	if (Battlefield = true && Card < 10)
	{
		Battlefield = false;
	}
}
