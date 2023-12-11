#include "Dxlib.h"
#include "GameMainScene.h"
#include "Card_Deck.h"
#include "Pokemon.h"
#include "PadInput.h"
Pokemon poke;

GameMainScene::GameMainScene()
{
	NextTurn = false;
	Battlefield = true;
	Player = 0;
	Turn = START;
	Cr = GetColor(255, 255, 255);
}

int interval = 0;

AbstractScene* GameMainScene::Update()
{
	player.Update();
	cpu.Update();
	//side.Update();

	switch(Turn)
	{
	case START:
		
		//if (!NextTurn/*==false*/)
		//{
		//	Turn = MY_TURN;
		//}
		//else
		//{
		//	Turn = ENEMY_TURN;
		//}

		//最初に7枚手札に加える・サイドを入れる
		if (player.First_Draw)
		{
			//サイドに置く
			for (int i = 0; i < 6; i++)
			{
				if (player.CheckCard())
				{
					player.SetSide(player.CardDraw());
				}
			}
			//7枚手札に加える
			for (int i = 0; i < 7; i++)
			{
				player.AddHand(player.CardDraw());
			}
			//手札に[たね]があるかないか調べる
			if (600 < ++interval)
			{
				interval = 0;
				//[たね]がない場合
				if (!player.IsSeedInHand())
				{
					//手札のカードを全て山札に戻す
					for (int i = 0; i < 7; i++)
					{
						player.ReturnCard(player.GetHand(i));
					}
				}
				else
				{
					player.First_Draw = false;
				}
			}
		}
		if (cpu.First_Draw)
		{
			//6枚サイドに置く
			for (int i = 0; i < 6; i++)
			{
				if (cpu.CheckCard())
				{
					cpu.SetSide(cpu.CardDraw());
				}
			}
			//7枚手札に加える
			for (int i = 0; i < 7; i++)
			{
				cpu.AddHand(cpu.CardDraw());
			}
			cpu.First_Draw = false;
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



	card_deck.Update(this);
	pokemon.Update(this);
	return this;
}

void GameMainScene::Draw() const
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

void GameMainScene::Battlepoke(int Card)
{
	if (Battlefield = true && Card < 10)
	{
		Battlefield = false;
	}
}
