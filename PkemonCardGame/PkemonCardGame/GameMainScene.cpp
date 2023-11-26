#include "Dxlib.h"
#include "GameMainScene.h"
#include "Card_Deck.h"
#include "Pokemon.h"
Pokemon poke;

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



	card_deck.Update();
	pokemon.Update();
	return this;
}

void GameMainScene::Draw() const
{
	
	field.Draw();
	hand.Draw();
	//card_deck.Draw();
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
}