#include "Hand.h"
#include "DxLib.h"
#include "PadInput.h"
#include <time.h>

Hand::Hand()
{
	for (int i = 0; i < 10; i++)
	{
		if (i < 7)
		{
			hand[i] = i;
		}
		else
		{
			hand[i] = -1;
		}

		cs[i] = -1;
	}
	hand_num = 7;
	cursor_x = 0;
}

void Hand::Update()
{
	//to do �m�F�p
	//if (PAD_INPUT::OnClick(XINPUT_BUTTON_X))
	//{
	//	srand((unsigned int)time(NULL));
	//	DrawCard(rand() % 10+1);
	//}
	//
	////�J�[�\���ړ�
	//if (PAD_INPUT::OnClick(XINPUT_BUTTON_DPAD_RIGHT))
	//{
	//	if (hand_num - 1 < ++cursor_x)
	//	{
	//		cursor_x = 0;
	//	}
	//}
	//if (PAD_INPUT::OnClick(XINPUT_BUTTON_DPAD_LEFT))
	//{
	//	if (--cursor_x < 0)
	//	{
	//		cursor_x = hand_num - 1;
	//	}
	//}

	////����
	//if (PAD_INPUT::OnClick(XINPUT_BUTTON_A))
	//{
	//	SetTrashPosition(cursor_x);
	//}

	//if (PAD_INPUT::OnClick(XINPUT_BUTTON_BACK))
	//{
	//	TrashHand(0);
	//	//�������炵�I������Adc��cs��������
	//	dc = 0;
	//	for (int i = 0; i < 10; i++)
	//	{
	//		cs[i] = -1;
	//	}
	//}
	//�����܂�
}

void Hand::Draw() const
{
	DrawString(1100, 680, "��D", 0xffffff);
	for (int i = 0; i < hand_num; i++)
	{
		DrawFormatString(1100 + 25 * i, 700, 0xffffff, "%d", hand[i]);
	}
	DrawCircle(1105 + 28 * cursor_x, 730, 5, 0xff0000, true);

	DrawString(1300, 680, "�J�[�\���ړ� ����(�A�i���O�{�^��)", 0x000000);
	DrawString(1300, 700, "�I�� A", 0x000000);
	DrawString(1300, 720, "���� BACK", 0x000000);
	DrawString(1300, 740, "���������� X", 0x000000);

#ifndef DEBUG
#define DEBUG
	/*for (int i = 0; i < 10; i++)
	{
		DrawFormatString(900 + 25 * i, 400, 0xffffff, "%d", hand[i]);
	}*/

	DrawFormatString(1100, 600, 0xff0000, "�������� %d", dc);
	DrawString(1250, 600, "�����ʒu ", 0xff0000);
	for (int i = 0; i < dc; i++)
	{
		DrawFormatString(1380+20*i, 600, 0xff0000, "%d ", cs[i]);
	}
#endif // !DEBUG

}

void Hand::DrawCard(int card)
{
	//��D�̐��������������₷
	++hand_num;
	//�J�[�h�̎�ނ��i�[
	hand[hand_num - 1] = card;
}

void Hand::TrashHand(int start)
{
	//�w�肵���ʒu�̃J�[�h������
	for (int i = 0; i < dc; i++)
	{
		hand[cs[i]] = -1;
	}

	int i = 0;
	//�O�ɋl�߂�
	while (i < hand_num)
	{
		//�����Ă���̂�-1�Ȃ����O�ɋl�߂�
		if (hand[i] == -1)
		{
			for (int j = i; j < hand_num; j++)
			{
				hand[j] = hand[j + 1];
			}
			//�Ō����-1�ɂ���E��D�̐������炷
			hand[hand_num - 1] = -1;
			--hand_num;
		}

		//hand[i]��-1����Ȃ��Ȃ�i��+1����
		if (hand[i] != -1) ++i;
	}
}

void Hand::AllTrash()
{
	for (int i = 0; i < hand_num; i++)
	{ 
		hand[i] = -1;
	}
	hand_num = 0;
}
