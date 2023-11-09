#include "Dxlib.h"
#include "GameMainScene.h"


GameMainScene::GameMainScene()
{

}

AbstractScene* GameMainScene::Update()
{
	hand.Update();

	return this;
}

void GameMainScene::Draw() const
{
	field.Draw();
	hand.Draw();
}