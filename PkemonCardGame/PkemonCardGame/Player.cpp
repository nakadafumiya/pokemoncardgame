#include "Player.h"
#include "DxLib.h"
#include "PadInput.h"

Player::Player()
{
	Cursor_X = 0;
	OldX = -1;
	DeckType = 0;

	for (int i = 0; i < 27; i++)
	{
		cardImg[i] = -1;
	}

	for (int i = 0; i < 19; i++)
	{
		poke_data[i] = poke.GetPokeID(i);
	}

	for (int i = 0; i < 6; i++)
	{
		if (CheckCard())
		{
			SetSide(CardDraw());
		}
	}

	LoadImages();
}

//Player::Player(int dtype)
//{
//	DeckType = dtype;
//	LoadImages();
//
//	//�f�b�L�^�C�v��0�̎�(������)
//	if (DeckType == 0)
//	{
//		for (int i = 0; i < 19; i++)
//		{
//			poke_data[i] = poke.GetPokeID(i);
//		}
//	}
//	else //�f�b�L�^�C�v��1�̎�()
//	{
//
//	}
//}

void Player::Update()
{
	SticControl();

	//to do �m�F�p	
	//�f�b�L����J�[�h������
	if (PAD_INPUT::OnClick(XINPUT_BUTTON_X))
	{
		//������J�[�h�����鎞��������
		if (CheckCard())
		{
			AddHand(CardDraw());
		}
	}

	//�폜�J�n
	if (PAD_INPUT::OnClick(XINPUT_BUTTON_BACK))
	{
		TrashHand();
		AdjustmentCursor();
	}
	//�����܂�

	//�J�[�\���ړ�
	//�E
	if (MARGIN < PAD_INPUT::GetPadThumbLX() && FlgX == 0)
	{
		if (HandNum - 1 < ++Cursor_X)
		{
			Cursor_X = 0;
		}
	}
	//��
	if (PAD_INPUT::GetPadThumbLX() < -MARGIN && FlgX == 0)
	{
		if (--Cursor_X < 0)
		{
			Cursor_X = HandNum - 1;
		}
	}

	//����
	if (PAD_INPUT::OnClick(XINPUT_BUTTON_A))
	{
		SetTrashPosition(Cursor_X);
	}
}

void Player::Draw() const
{
	DrawString(1100, 680, "��D", 0xffffff);
	for (int i = 0; i < 6; i++)//HandNum
	{
		DrawFormatString(1100 + 25 * i, 700, 0xffffff, "%d", GetSide(i)); //hand[i]
	}
	DrawCircle(910 + 110 * Cursor_X, 800, 5, 0xff0000, true);

	for (int i = 0; i < HandNum; i++)
	{
		int ph = 0;
		int pw = 0;
		//�J�[�\���ʒu�̃J�[�h����ɏグ��
		if (Cursor_X == i)
		{
			ph = 20;
		}
		//�J�[�\���ʒu�ȊO�̃J�[�h�����E�ɂ��炷
		if (i < Cursor_X)
		{
			pw = -20;
		}
		else if (Cursor_X < i)
		{
			pw = 20;
		}

		if (hand[i] != -1)
		{
			switch (DetermineCard(i,DeckType))
			{
			case 0:  //������
				DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardImg[0], TRUE);
				break;
			case 1:  //������VMAX
				DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardImg[1], TRUE);
				break;
			case 2:  //�����g�X
				DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardImg[2], TRUE);
				break;
			case 3:  //�L�����A
				DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardImg[3], TRUE);
				break;
			case 4:  //�T�[�i�C�g
				DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardImg[4], TRUE);
				break;
			case 5:  //�f�B�A���V�[
				DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardImg[5], TRUE);
				break;
			case 6:  //�Q�b�R�E�K
				DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardImg[6], TRUE);
				break;
			}
		}
	}

	Side::Draw();

#ifndef DEBUG
#define DEBUG
	/*for (int i = 0; i < 10; i++)
	{
		DrawFormatString(900 + 25 * i, 400, 0xffffff, "%d", hand[i]);
	}*/

	DrawFormatString(1100, 600, 0xff0000, "�������� %d", DecreaseNum);
	DrawString(1250, 600, "�����ʒu ", 0xff0000);
	for (int i = 0; i < DecreaseNum; i++)
	{
		DrawFormatString(1380 + 20 * i, 600, 0xff0000, "%d ", dPosition[i]);
	}

	/*DrawString(1300, 680, "�J�[�\���ړ� ����(�X�e�B�b�N)", 0x000000);
	DrawString(1300, 700, "�I�� A", 0x000000);
	DrawString(1300, 720, "���� BACK", 0x000000);
	DrawString(1300, 740, "���������� X", 0x000000);*/
#endif // !DEBUG

}

void Player::LoadImages()
{
	//�f�b�L�^�C�v��0�̎�
	if (DeckType == 0)
	{
		const char* card[] = { "images/Pokemon_Card_D1/Calyrex_V.png","images/Pokemon_Card_D1/Calyrex_VMAX.png","images/Pokemon_Card_D1/Ralts.png"
		,"images/Pokemon_Card_D1/Kirlia.png","images/Pokemon_Card_D1/Gardevoir_ex.png","images/Pokemon_Card_D1/Diancie.png","images/Pokemon_Card_D1/�����₭�Q�b�R�E�K.png"
		,"images/Pokemon_Card_D1/���G�l���M�[.png","images/Pokemon_Card_D1/OldCemetery.png","images/Pokemon_Card_D1/�|�P�������ꂩ��.png","images/Pokemon_Card_D1/NestBall.png"
		,"images/Pokemon_Card_D1/�n�C�p�[�{�[��.png","images/Pokemon_Card_D1/FogCrystal.png","images/Pokemon_Card_D1/EscapeRope.png","images/Pokemon_Card_D1/���񂫂̃n�`�}�L.png"
		,"images/Pokemon_Card_D1/ChoiceBelt.png","images/Pokemon_Card_D1/�ӂ����ȃA��.png","images/Pokemon_Card_D1/Miriam.png","images/Pokemon_Card_D1/ProfessorsResearch_Sada.png"
		,"images/Pokemon_Card_D1/BosssOrders_GCis.png","images/Pokemon_Card_D1/Serena.png","images/Pokemon_Card_D1/Arven.png" };

		for (int i = 0; i < 22; i++)
		{
			cardImg[i] = LoadGraph(card[i]);
		}
	}
	else //�f�b�L�^�C�v��1�̎�
	{
		const char* card[] = { "images/Pokemon_Card_D2/Arceus_VSTAR.png","images/Pokemon_Card_D2/Arceus_VSTAR.png","images/Pokemon_Card_D2/Arceus_V.png","images/Pokemon_Card_D2/Rayquaza_VMAX.png"
			,"images/Pokemon_Card_D2/Rayquaza_V.png","images/Pokemon_Card_D2/Delphox_V.png","images/Pokemon_Card_D2/Lumineon_V.png","images/Pokemon_Card_D2/Charcadet.png","images/Pokemon_Card_D2/Armarouge.png"
			,"images/Pokemon_Card_D2/Pumpkaboo.png","images/Pokemon_Card_D2/Skwovet.png","images/Pokemon_Card_D2/ShiningHeatran.png","images/Pokemon_Card_D2/FireEnergy .png","images/Pokemon_Card_D2/LightningEnergy.png"
			,"images/Pokemon_Card_D2/DoubleTurboEnergy.png","images/Pokemon_Card_D2/MagmaBasin.png","images/Pokemon_Card_D2/NestBall.png","images/Pokemon_Card_D2/UltraBall.png","images/Pokemon_Card_D2/CaptureAroma.png"
			,"images/Pokemon_Card_D2/BattleVIPPath.png","images/Pokemon_Card_D2/Switch.png","images/Pokemon_Card_D2/PalPad.png","images/Pokemon_Card_D2/ChoiceBelt.png","images/Pokemon_Card_D2/ProfessorsResearch_Sada.png"
			,"images/Pokemon_Card_D2/BosssOrders_GCis.png","images/Pokemon_Card_D2/Serena.png","images/Pokemon_Card_D2/Raihan.png","images/Pokemon_Card_D2/Judge.png" };

		for (int i = 0; i < 27; i++)
		{
			cardImg[i] = LoadGraph(card[i]);
		}
	}
}

void Player::SticControl()
{
	if (MARGIN < OldX && MARGIN < PAD_INPUT::GetPadThumbLX())
	{
		FlgX = 1;
	}
	else if (OldX < -MARGIN && PAD_INPUT::GetPadThumbLX() < -MARGIN)
	{
		FlgX = 1;
	}
	else
	{
		FlgX = 0;
	}

	OldX = PAD_INPUT::GetPadThumbLX();
}

void Player::AdjustmentCursor()
{
	//�J�[�\���ʒu����D�̐����傫��������
	//�Ō���ɒ�������
	if (HandNum < Cursor_X + 1)
	{
		Cursor_X = HandNum - 1;
	}
}
