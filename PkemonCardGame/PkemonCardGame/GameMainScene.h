#pragma once
#include "AbstractScene.h"
#include"common.h"
#include "Field.h"
#include "Hand.h"
#include "Card_Deck.h"
#include "Pokemon.h"
#include"Side.h"

class GameMainScene : public AbstractScene
{
private:

	Field field;
	Hand hand;
	int Turn;
	int Cr;
	int Player;
	int CPU;
	 
	bool NextTurn;
	Card_Deck card_deck;
	Side side;
	Pokemon pokemon;


public:
GameMainScene();
//�`��ȊO�̍X�V����������
virtual AbstractScene* Update();
//�`��Ɋւ��邱�����������
virtual void Draw()const;
};

