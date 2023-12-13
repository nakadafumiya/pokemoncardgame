#include "GameOver.h"
#include "Card_Deck.h"
#include "Title.h"
#include "common.h"
#include "PadInput.h"

GameOver::GameOver()
{
	GO_image = LoadGraph("images/GameOver.png");
}

AbstractScene* GameOver::Update()
{
	if (card_deck.CheckCard() == false)
	{
		if (PAD_INPUT::OnClick(XINPUT_BUTTON_A))
		{
			return new Title();
		}
	}
}

void GameOver::Draw() const
{
	DrawGraph(SCREEN_HEIGHT, SCREEN_WIDTH, GO_image, TRUE);
}