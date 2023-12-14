#include "Hand.h"
#include "DxLib.h"
#include "PadInput.h"
#include <string.h>

Hand::Hand()
{
	for (int i = 0; i < MaxHand; i++)
	{
		hand[i] = -1;

		dPosition[i] = -1;
	}

	for (int i = 0; i < 5; i++)
	{
		saveHand[i] = -1;
	}
	HandNum = 0;//7
	Push_X = 90;

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

void Hand::AddHand(int card)
{
	//��D�̐��𑝂₷
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
		hand[dPosition[i]] = -1;
		if (Push_X < 90) //�Ԋu��90�����̎�
		{
			Push_X += 5;  //��D�����������J�[�h�̊Ԋu���L����
		}
	}

	//�������炵�I������AdPosition��DecreaseNum��������
	for (int i = 0; i < DecreaseNum; i++)
	{
		dPosition[i] = -1;
	}
	DecreaseNum = 0;

	//��D�ɃJ�[�h���c���Ă��邩���ׂ�
	bool have_c = false; //true:�c���Ă��� false:�c���Ă��Ȃ�
	for (int i = 0; i < HandNum; i++)
	{
		//�J�[�h�����鎞have_c��true�ɂ���
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
		saveHand[i] = hand[i];
		hand[i] = -1;
	}
	HandNum = 0;
}