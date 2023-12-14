#pragma once
#include "Card_Deck.h"
#include "Pokemon.h"

class Hand
{
public:
	Hand();
	//��D�𑝂₷
	void AddHand(int card);
	//��D�����炷
	void TrashHand();
	//�����J�[�h��ݒ肷��
	void SetTrashPosition(int position);
	//��D�S������
	void AllTrash();
	int SendCardID(int i) { return saveHand[i]; }
	//�ꎞ�ۑ����Ă����J�[�h������
	void InitSaveHand()
	{
		for (int i = 0; i < 5; i++)
		{
			if (saveHand[i] == -1) break;
			saveHand[i] = -1;
		}
	}
	//��D�Ɂu���ˁv�����݂��邩
	bool IsSeedInHand()
	{
		for (int i = 0; i < HandNum; i++)
		{
			if (hand[i] <= 9) //���F18 ID��18�ȉ��̂Ƃ�[����]�����݂���
			{
				return true;
			}
		}

		return false;
	}
	int GetHand(int i) { return hand[i]; }
	void DecreaseHandNum() { --HandNum; }

protected:
	int hand[10]; //��D
	//char* hand[10]; //char�^��D
	//char* saveHand[5]; //�ꎞ�ۑ��p
	int saveHand[5];
	int HandNum;  //�����Ă����D�̐�
	int DecreaseNum = 0;    //���炷��
	int dPosition[10]; //���炷�ʒu
	int Push_X;  //��D�������邽�тɉ��ɋl�߂�
	const int MaxHand = 10;  //�ő�Ŏ��Ă��D�̐�

private:
	Card_Deck deck;
	Pokemon poke;
};