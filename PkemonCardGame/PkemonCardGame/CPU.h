#pragma once
#include "Hand.h"
#include "Card_Deck.h"
#include "Pokemon.h"
#include "Side.h"

class CPU :public Hand,public Card_Deck,public Side
{
public:
	CPU();
	void Update();
	void Draw()const;
	void LoadImages();
	//�o�g���t�B�[���h�ɃJ�[�h��u��
	void SetBattleField();
	//�x���`�ɃJ�[�h��u��
	void SetBench();

	bool EndFirstDraw;//�Q�[���J�n����7���������� true�F�I����� false�F�I����Ă��Ȃ�
	bool EndSet;//�J�[�h��u���I������� true�F�I����� false�F�I����Ă��Ȃ�

private:
	int DeckType;  //�f�b�L�̎��
	int CardBack;    //�J�[�h�̗���
	int cardImg[27]; //�J�[�h�摜
	int Battle; //�o�g���t�B�[���h�ɏo���J�[�h��ID
	int Bench[5];  //�x���`�ɏo���J�[�h��ID
	int Trash[60]; //�g���b�V�����ꂽ�J�[�h��ID
	int tCount;    //�g���b�V���ɂ���J�[�h�̖���
	Data poke_data[20];
	Pokemon poke;

	//�o�g���t�B�[���h�ɒu�����J�[�h��`��
	void BattleFieldDraw()const;
	//�`�悷��J�[�h�𔻕�
	int DetermineCard(int card_id, int dtype)const;
};

