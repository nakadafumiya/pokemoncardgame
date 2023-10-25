#pragma once
#include <iostream>
#include <random>

#define DECK 60
#define INITIAL_DECK 7
#define MIN_DECK 1
//#define MAX_DECK 

//�J�[�h�r�o�N���X
class Card_Deck
{
private:
	int deck_num; //�f�b�L��
	int card_num; //�J�[�h����
	int* deck;	  //�i�[�z��
	int* p_deck;  //�z��擪�|�C���^
	int image;

public:
	//�R���X�g���N�^�F�����̓f�b�L��
	Card_Deck(int input_deck_num = MIN_DECK)
	{
		//�f�b�L���̌���
		if (input_deck_num < MIN_DECK)
		{
			deck_num = MIN_DECK; //�ŏ��l
		}
		else {
			deck_num = input_deck_num; //���͒l
		}
		//else if (input_deck_num > MAX_DECK)
		//{
		//	deck_num = MAX_DECK; //�ő�l
		//}

		card_num = deck_num * DECK;

		deck = new int[card_num]; //�������m��
		p_deck = &deck[0]; //�擪�|�C���^�̐ݒ�

		//�z��̏�����
		for (int i = 0; i < card_num; i++)
		{
			deck[i] = -1;
		}

		std::random_device rnd;	//����������

		//�}������J�[�h�����ɕς���
		for (int i = 0; i < card_num; i++)
		{
			//�}���ʒu�ɃJ�[�h��}������܂Ń��[�v
			while (true)
			{
				int place = rnd() % (card_num); //�}���ʒu�̌���
				if (deck[place] == -1)
				{
					//�J�[�h�̊i�[
					deck[place] = i % DECK;
					break; //���[�v�𔲂���
				}
			}
		}
	}
	//�f�X�g���N�^
	~Card_Deck()
	{
		delete[] deck; //���������
	}

	//�J�[�h�̔r�o
	int hand_card()
	{
		int hand = p_deck[0]; //�r�o����J�[�h�̐��l���m��
		//�z�񏈗�
		p_deck++; //�擪�|�C���^�����炷
		card_num--; //�J�[�h���������炷
		return hand; //�r�o����J�[�h�̐��l��n��
	}
public:
	Card_Deck();
	void Draw();
};