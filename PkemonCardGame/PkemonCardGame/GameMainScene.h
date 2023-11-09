#pragma once
#include "AbstractScene.h"
#include"common.h"
#include "Field.h"
#include "Card_Deck.h"
#include"Side.h"

class GameMainScene : public AbstractScene
{
private:

	Field field;
	int Turn;
	int Cr;
	int Player;
	int CPU;
	 
	bool NextTurn;
	Card_Deck card_deck;
	Side side;

public:
GameMainScene();
//�`��ȊO�̍X�V����������
virtual AbstractScene* Update();
//�`��Ɋւ��邱�����������
virtual void Draw()const;
};

