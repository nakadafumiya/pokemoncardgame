#pragma once
#include "AbstractScene.h"
#include"common.h"
#include "Field.h"
#include "Card_Deck.h"

class GameMainScene : public AbstractScene
{
private:
	Field field;
	Card_Deck card_deck;
public:
GameMainScene();
//�`��ȊO�̍X�V����������
virtual AbstractScene* Update();
//�`��Ɋւ��邱�����������
virtual void Draw()const;
};

