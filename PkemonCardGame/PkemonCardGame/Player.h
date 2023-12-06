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

private:
	int cardImg[27]; //�J�[�h�摜
	int Cursor_X;  //�J�[�\���ʒu
	int DeckType;  //�f�b�L�̎��
	int OldX;
	int FlgX;

	Data poke_data[19];
	Pokemon poke;
};

