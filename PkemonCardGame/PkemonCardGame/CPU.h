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

private:
	int DeckType;  //�f�b�L�̎��
	int CardBack;    //�J�[�h�̗���
	int BattleField; //�o�g���t�B�[���h�ɏo���J�[�h��ID
	int Trash[60]; //�g���b�V�����ꂽ�J�[�h
	int tCount;    //�g���b�V���ɂ���J�[�h�̖���
	Data poke_data[20];
	Pokemon poke;
};

