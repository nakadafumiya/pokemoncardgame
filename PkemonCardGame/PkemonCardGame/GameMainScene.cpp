#include "Dxlib.h"
#include "GameMainScene.h"
#include "Card_Deck.h"

GameMainScene::GameMainScene()
{
	
}

AbstractScene* GameMainScene::Update()
{

	card_deck.Update();
	return this;
}

void GameMainScene::Draw() const
{
	field.Draw();
	side.Draw();

}