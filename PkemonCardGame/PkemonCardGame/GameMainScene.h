#pragma once
#include "AbstractScene.h"
#include"common.h"
#include "Field.h"
#include "Card_Deck.h"
#include "Pokemon.h"
#include"Side.h"
#include "Title.h"
#include "Player.h"
#include "CPU.h"
#include"End.h"

class Card_Deck;

class GameMainScene : public AbstractScene
{
private:

	Field field;
	Player player;
	CPU cpu;
	End end;
	int Turn;
	int Cr;
	int Player;
	int CPU;
	 

	bool Battlefield;
	bool NextTurn;

	int TurnCount;
	Card_Deck card_deck;

	Side side;
	Pokemon pokemon;
	
	int Backimage;
	int helpimage1;
	int helpimage2;
	bool HelpFlag;


public:
GameMainScene();

virtual AbstractScene* Update();

virtual void Draw()const;

int GetTurn()
{
	return Turn;
}

 //void Battlepoke(int Card);
};

