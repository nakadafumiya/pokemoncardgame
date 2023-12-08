#pragma once
#include "AbstractScene.h"
#include "Card_Deck.h"


class GameOver : public Card_Deck
{
protected:
	int image;w

public:
	GameOver();
	virtual void Update(class GameMainScene* a) override;
	virtual void Draw()const override;

};

