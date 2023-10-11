#include "Field.h"
#include "DxLib.h"
#include "common.h"

Field::Field()
{
	Trash_X = 50;
	Trash_Y = 30; 
	Deck_X = 50;
	Deck_Y = Trash_Y + BoxSize_H + 10;
}

void Field::Draw() const
{
	for (int i = 0; i < 2; i++)
	{
		//トラッシュ
		DrawBox(Trash_X + (i * (SCREEN_WIDTH * 0.85)), Trash_Y + (i * (SCREEN_HEIGHT * 0.7)), Trash_X + BoxSize_W + (i * (SCREEN_WIDTH * 0.85)), Trash_Y + BoxSize_H + (i * (SCREEN_HEIGHT * 0.7)), 0xffffff, false);
		DrawString(Trash_X + (i * (SCREEN_WIDTH * 0.85)) + 15, Trash_Y + (i * (SCREEN_HEIGHT * 0.7)) + 20, "トラッシュ", 0xffffff);

		//デッキ
		DrawBox(Deck_X + (i * (SCREEN_WIDTH * 0.85)), Deck_Y + (i * (SCREEN_HEIGHT * 0.25)), Deck_X + BoxSize_W + (i * (SCREEN_WIDTH * 0.85)), Deck_Y + BoxSize_H + (i * (SCREEN_HEIGHT * 0.25)), 0xffffff, false);
		DrawString(Deck_X + (i * (SCREEN_WIDTH * 0.85)) + 15, Deck_Y + (i * (SCREEN_HEIGHT * 0.25)) + 20, "デッキ", 0xffffff);
	}
}