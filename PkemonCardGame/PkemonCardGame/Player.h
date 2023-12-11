#pragma once
#include "Hand.h"
#include "Card_Deck.h"
#include "Pokemon.h"
#include "Side.h"

class Player :public Hand,public Card_Deck,public Side
{
public:
	Player();
	Player(int dtype);
	void Update();
	void Draw()const;
	//�摜�ǂݍ���
	void LoadImages();
	//�X�e�B�b�N����
	void SticControl();
	//�J�[�\���ʒu�̒���
	void AdjustmentCursor();
	//�g���b�V���ɃJ�[�h������
	void SetTrash(int card) { Trash[tCount++] = card; }

private:
	int cardImg[27]; //�J�[�h�摜
	int CardBack;    //�J�[�h�̗�
	int Cursor_X;  //�J�[�\���ʒu
	int DeckType;  //�f�b�L�̎��
	int OldX;
	int FlgX;
	int Battle; //�o�g���t�B�[���h�ɏo���J�[�h��ID
	int Bench[5];  //�x���`�ɏo���J�[�h��ID
	int Trash[60]; //�g���b�V�����ꂽ�J�[�h��ID
	int tCount;    //�g���b�V���ɂ���J�[�h�̖���

	Data poke_data[19];
	Pokemon poke;

	//��D��`��
	void HandDraw()const;
	//�o�g���t�B�[���h�ɒu�����J�[�h��`��
	void BattleFieldDraw()const;
	//�`�悷��J�[�h�𔻕�
	int DetermineCard(int card, int dtype)const;
};

