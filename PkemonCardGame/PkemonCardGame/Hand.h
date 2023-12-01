#pragma once
#include "Card_Deck.h"
#include "Pokemon.h"

class Hand
{
public:
	Hand();
	void Update();
	void Draw()const;
	//��D�𑝂₷
	void DrawCard(int card);
	//��D�����炷
	void TrashHand();
	//�����J�[�h��ݒ肷��
	void SetTrashPosition(int position);
	//��D�S������
	void AllTrash();
	//char* SendCardName(int i) { return saveHand[i]; }
	int SendCardName(int i) { return saveHand[i]; }
	void InitSaveHand()
	{
		/*for (int i = 0; i < 5; i++)
		{
			if (saveHand[i] == NULL) break;
			saveHand[i] = NULL;
		}*/

		for (int i = 0; i < 5; i++)
		{
			if (saveHand[i] == -1) break;
			saveHand[i] = -1;
		}
	}
	void LoadImages();
	//�`�悷��J�[�h�𔻕�
	int DetermineCard(int i)const;

protected:
	int cardimg[22]; //�J�[�h�摜
	int hand[10]; //��D
	//char* hand[10]; //char�^��D
	//char* saveHand[5]; //�ꎞ�ۑ��p
	int saveHand[5];
	int HandNum;  //�����Ă����D�̐�
	int Cursor_X;  //�J�[�\���ʒu
	int DecreaseNum = 0;    //���炷��
	int dPosition[10]; //���炷�ʒu
	int Push_X;  //��D�������邽�тɉ��ɋl�߂�

	const int MaxHand = 10;  //�ő�Ŏ��Ă��D�̐�

private:
	Card_Deck deck;
	Pokemon poke;
};