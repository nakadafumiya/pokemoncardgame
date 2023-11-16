#include "Hand.h"
#include "DxLib.h"
#include "PadInput.h"
#include <time.h>

Hand::Hand()
{
	for (int i = 0; i < MaxHand; i++)
	{
		if (i < 7)
		{
			hand[i] = i;
		}
		else
		{
			hand[i] = -1;
		}

		dPosition[i] = -1;
	}
	HandNum = 7;
	Cursor_X = 0;
	Push_X = 90;

	LoadImages();
}

void Hand::Update()
{
	//to do �m�F�p
	if (PAD_INPUT::OnClick(XINPUT_BUTTON_X))
	{
		if (HandNum < MaxHand)
		{
			srand((unsigned int)time(NULL));
			DrawCard(rand() % 22);
		}
	}
	
	//�J�[�\���ړ�
	if (PAD_INPUT::OnClick(XINPUT_BUTTON_DPAD_RIGHT))
	{
		if (HandNum - 1 < ++Cursor_X)
		{
			Cursor_X = 0;
		}
	}
	if (PAD_INPUT::OnClick(XINPUT_BUTTON_DPAD_LEFT))
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

	if (PAD_INPUT::OnClick(XINPUT_BUTTON_BACK))
	{
		TrashHand();
		//�������炵�I������Adc��cs��������
		for (int i = 0; i < DecreaseNum; i++)
		{
			dPosition[i] = -1;
		}
		DecreaseNum = 0;
		//�J�[�\���ʒu����D�̐����傫��������
		//�Ō���ɒ�������
		if (HandNum < Cursor_X)
		{
			Cursor_X = HandNum - 1;
		}
	}
	//�����܂�
}

void Hand::Draw() const
{
	DrawString(1100, 680, "��D", 0xffffff);
	for (int i = 0; i < HandNum; i++)
	{
		DrawFormatString(1100 + 25 * i, 700, 0xffffff, "%d", hand[i]);
	}
	DrawCircle(1105 + 28 * Cursor_X, 730, 5, 0xff0000, true);

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

		DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardimg[hand[i]], TRUE);
	}

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
		DrawFormatString(1380+20*i, 600, 0xff0000, "%d ", dPosition[i]);
	}

	/*DrawString(1300, 680, "�J�[�\���ړ� ����(�A�i���O�{�^��)", 0x000000);
	DrawString(1300, 700, "�I�� A", 0x000000);
	DrawString(1300, 720, "���� BACK", 0x000000);
	DrawString(1300, 740, "���������� X", 0x000000);*/
#endif // !DEBUG

}

void Hand::DrawCard(int card)
{
	//��D�̐��������������₷
	++HandNum;
	//�J�[�h�̎�ނ��i�[
	hand[HandNum - 1] = card;
	if (7 < HandNum)  //��D�̐���7������̎�
	{
		Push_X -= 5;  //��D�����������J�[�h�̊Ԋu�����߂�
	}
	
}

void Hand::TrashHand()
{
	//�w�肵���ʒu�̃J�[�h������
	for (int i = 0; i < DecreaseNum; i++)
	{
		hand[dPosition[i]] = -1;
		if (Push_X < 90) //�Ԋu��90�����̎�
		{
			Push_X += 5;  //��D�����������J�[�h�̊Ԋu���L����
		}
	}

	int i = 0;
	//�O�ɋl�߂�
	while (i < HandNum)
	{
		//�����Ă���̂�-1�Ȃ��납��O�ɋl�߂�
		if (hand[i] == -1)
		{
			for (int j = i; j < HandNum; j++)
			{
				hand[j] = hand[j + 1];
			}
			//�Ō����-1�ɂ���E��D�̐������炷
			hand[HandNum - 1] = -1;
			--HandNum;
		}

		//hand[i]��-1����Ȃ��Ȃ�i��+1����
		if (hand[i] != -1) ++i;
	}
}

void Hand::SetTrashPosition(int position)
{
	dPosition[DecreaseNum] = position;
	++DecreaseNum;
}

void Hand::AllTrash()
{
	for (int i = 0; i < HandNum; i++)
	{ 
		hand[i] = -1;
	}
	HandNum = 0;
}

void Hand::LoadImages()
{
	const char* card[] = { "images/Pokemon_Card_D1/Calyrex_V.png","images/Pokemon_Card_D1/Calyrex_VMAX.png","images/Pokemon_Card_D1/Ralts.png"
		,"images/Pokemon_Card_D1/Kirlia.png","images/Pokemon_Card_D1/Gardevoir_ex.png","images/Pokemon_Card_D1/Diancie.png","images/Pokemon_Card_D1/�����₭�Q�b�R�E�K.png"
		,"images/Pokemon_Card_D1/���G�l���M�[.png","images/Pokemon_Card_D1/OldCemetery.png","images/Pokemon_Card_D1/�|�P�������ꂩ��.png","images/Pokemon_Card_D1/NestBall.png"
		,"images/Pokemon_Card_D1/�n�C�p�[�{�[��.png","images/Pokemon_Card_D1/FogCrystal.png","images/Pokemon_Card_D1/EscapeRope.png","images/Pokemon_Card_D1/���񂫂̃n�`�}�L.png"
		,"images/Pokemon_Card_D1/ChoiceBelt.png","images/Pokemon_Card_D1/�ӂ����ȃA��.png","images/Pokemon_Card_D1/Miriam.png","images/Pokemon_Card_D1/ProfessorsResearch_Sada.png"
		,"images/Pokemon_Card_D1/BosssOrders_GCis.png","images/Pokemon_Card_D1/Serena.png","images/Pokemon_Card_D1/Arven.png"};

	for (int i = 0; i < 22; i++)
	{
		cardimg[i] = LoadGraph(card[i]);
	}
}
