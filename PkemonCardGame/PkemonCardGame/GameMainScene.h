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
//•`‰æˆÈŠO‚ÌXV‚ğÀ‘•‚·‚é
virtual AbstractScene* Update();
//•`‰æ‚ÉŠÖ‚·‚é‚±‚ë‚ğÀ‘•‚·‚é
virtual void Draw()const;
};

