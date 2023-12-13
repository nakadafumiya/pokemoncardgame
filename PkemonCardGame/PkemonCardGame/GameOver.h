#pragma once
#include "AbstractScene.h"
#include "Card_Deck.h"


class GameOver : public AbstractScene
{
protected:
	int GO_image;

	Card_Deck card_deck;

public:
	GameOver();
	virtual AbstractScene* Update();
	virtual void Draw()const override;
};

