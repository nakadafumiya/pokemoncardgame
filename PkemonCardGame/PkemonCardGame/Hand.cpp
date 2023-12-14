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
		hand[i] = -1;
		//hand[i] = NULL;
	}
	HandNum = 0;
}

int Hand::DetermineCard(int i,int dtype) const
{
	//�f�b�L�^�C�v��0�̎�
	if (dtype == 0)
	{
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

	}
	else
	{

	}
	return -1;
}
