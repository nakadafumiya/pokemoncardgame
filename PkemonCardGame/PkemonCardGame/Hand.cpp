#include "Hand.h"
#include "DxLib.h"
#include "PadInput.h"
#include <string.h>

Hand::Hand()
{
	for (int i = 0; i < MaxHand; i++)
	{
		hand[i] = -1;
		//hand[i] = NULL;

		dPosition[i] = -1;
	}
	for (int i = 0; i < 5; i++)
	{
		/*saveHand[i] = NULL;*/
		saveHand[i] = -1;
	}
	HandNum = 0;//7
	Cursor_X = 0;
	Push_X = 90;

	LoadImages();
}

void Hand::Update()
{
	//to do �m�F�p	
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
		if (HandNum < Cursor_X + 1)
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
		//DrawFormatString(900 + 100 * i, 700, 0x000000, "%s", hand[i]);
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

		//if (hand[i] != NULL)
		//{
		//	switch (DetermineCard(i))
		//	{
		//	case 0:  //������
		//		DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardimg[0], TRUE);
		//		break;
		//	case 1:  //������VMAX
		//		DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardimg[1], TRUE);
		//		break;
		//	case 2:  //�����g�X
		//		DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardimg[2], TRUE);
		//		break;
		//	case 3:  //�L�����A
		//		DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardimg[3], TRUE);
		//		break;
		//	case 4:  //�T�[�i�C�g
		//		DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardimg[4], TRUE);
		//		break;
		//	case 5:  //�f�B�A���V�[
		//		DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardimg[5], TRUE);
		//		break;
		//	case 6:  //�Q�b�R�E�K
		//		DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardimg[6], TRUE);
		//		break;
		//	}

		if (hand[i] != -1)
		{
			switch (DetermineCard(i))
			{
			case 0:  //������
				DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardimg[0], TRUE);
				break;
			case 1:  //������VMAX
				DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardimg[1], TRUE);
				break;
			case 2:  //�����g�X
				DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardimg[2], TRUE);
				break;
			case 3:  //�L�����A
				DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardimg[3], TRUE);
				break;
			case 4:  //�T�[�i�C�g
				DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardimg[4], TRUE);
				break;
			case 5:  //�f�B�A���V�[
				DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardimg[5], TRUE);
				break;
			case 6:  //�Q�b�R�E�K
				DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardimg[6], TRUE);
				break;
			}
		}
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
	//hand[HandNum] = poke.GetName(card);

	//��D�̐���7������̎��Ԋu�����߂�
	if (7 < HandNum)
	{
		Push_X -= 5;  //��D�����������J�[�h�̊Ԋu�����߂�
	}
	
}

void Hand::TrashHand()
{
	//�w�肵���ʒu�̃J�[�h������
	for (int i = 0; i < DecreaseNum; i++)
	{
		if (i < 5) //�ꎞ�ۑ�
		{
			saveHand[i] = hand[i];
		}
		//hand[dPosition[i]] = NULL;
		hand[dPosition[i]] = -1;
		if (Push_X < 90) //�Ԋu��90�����̎�
		{
			Push_X += 5;  //��D�����������J�[�h�̊Ԋu���L����
		}
	}

	//��D�ɃJ�[�h���c���Ă��邩���ׂ�
	bool have_c = false; //true:�c���Ă��� false:�c���Ă��Ȃ�
	for (int i = 0; i < HandNum; i++)
	{
		//�J�[�h�����鎞have_c��true�ɂ���
		/*if (hand[i] != NULL)
		{
			have_c = true;
			break;
		}*/
		if (hand[i] != -1)
		{
			have_c = true;
			break;
		}
	}


	int i = 0;
	//�c���Ă���J�[�h�����鎞�O�ɋl�߂�
	if (have_c)
	{
		while (i < HandNum)
		{
			////�����Ă���̂�NULL�Ȃ��납��O�ɋl�߂�
			//if (hand[i] == NULL)//hand[i] == -1
			//{
			//	for (int j = i; j < HandNum; j++)
			//	{
			//		//hand[j] = hand[j + 1];
			//		hand[j] = hand[j + 1];
			//	}
			//	//�Ō����-1�ɂ���E��D�̐������炷
			//	//hand[HandNum - 1] = -1;
			//	hand[HandNum - 1] = NULL;
			//	--HandNum;
			//}

			////hand[i]��-1����Ȃ��Ȃ�i��+1����
			////if (hand[i] != -1) ++i;
			////hand_s[i]��NULL����Ȃ��Ȃ�i��+1����
			//if (hand[i] != NULL) ++i;

			//�����Ă���̂�NULL�Ȃ��납��O�ɋl�߂�
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
	else
	{
		HandNum = 0;
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
		//hand[i] = NULL;
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

int Hand::DetermineCard(int i) const
{
	/*if (strcmp(hand[i], "kokuba") == 0
		|| strcmp(hand[i], "\nkokuba") == 0)
	{
		return 0;
	}
	if (strcmp(hand[i], "\nkokuba_m") == 0)
	{
		return 1;
	}
	if (strcmp(hand[i], "\nrarutosu") == 0)
	{
		return 2;
	}
	if (strcmp(hand[i], "\nkiruria") == 0)
	{
		return 3;
	}
	if (strcmp(hand[i], "\nsa-naito") == 0)
	{
		return 4;
	}
	if (strcmp(hand[i], "\ndhianshi") == 0)
	{
		return 5;
	}
	if (strcmp(hand[i], "\ngekkouga") == 0)
	{
		return 6;
	}*/

	/*�|�P����*/
	if (hand[i] <= 3)
	{
		return 0;
	}
	if (hand[i] <= 7)
	{
		return 1;
	}
	if (hand[i] <= 11)
	{
		return 2;
	}
	if (hand[i] <= 14)
	{
		return 3;
	}
	if (hand[i] <= 16)
	{
		return 4;
	}
	if (hand[i] == 17)
	{
		return 5;
	}
	if (hand[i] == 18)
	{
		return 6;
	}
	/*����*/
	
	/*�g���[�i�[�Y*/

	return -1;
}
