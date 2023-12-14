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

	bool EndFirstDraw;//�Q�[���J�n����7���������� true�F�I����� false�F�I����Ă��Ȃ�
	bool EndStartDraw;//�^�[���J�n����1���������� true�F�I����� false�F�I����Ă��Ȃ�
	bool EndSet;//�J�[�h��u���I������� true�F�I����� false�F�I����Ă��Ȃ�
private:
	int cardImg[27]; //�J�[�h�摜
	int CardBack;    //�J�[�h�̗�
	int Cursor_X;  //�J�[�\���ʒu X���W
	int Cursor_Y;  //�J�[�\���ʒu Y���W
	int DeckType;  //�f�b�L�̎��
	int OldX;
	int OldY;
	int FlgX;
	int FlgY;
	int Battle; //�o�g���t�B�[���h�ɏo���J�[�h��ID
	int Bench[5];  //�x���`�ɏo���J�[�h��ID
	int Trash[60]; //�g���b�V�����ꂽ�J�[�h��ID
	int tCount;    //�g���b�V���ɂ���J�[�h�̖���
	const int X[3] = { 950,980,700 };
	const int Y[3] = { 700,800,910 };

	Data poke_data[19];
	Pokemon poke;

	//��D��`��
	void HandDraw()const;
	//�o�g���t�B�[���h�ɒu�����J�[�h��`��
	void BattleFieldDraw()const;
	//�`�悷��J�[�h�𔻕�
	int DetermineCard(int card_id, int dtype)const;
};

