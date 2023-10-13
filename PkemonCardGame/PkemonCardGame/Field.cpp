#include "Field.h"
#include "DxLib.h"
#include "common.h"

Field::Field()
{
	Trash_X = 50;
	Trash_Y = 30; 
	Deck_X = 50;
	Deck_Y = Trash_Y + Size_H + 10;
	Side_X = 40;
	Side_Y = Deck_Y + Size_H + 10;
	Bench_X = 350;
	Bench_Y = 15;
	Stadium_X = 230;
	Stadium_Y = 280;
}

void Field::Draw() const
{
	for (int i = 0; i < 2; i++)
	{
		//�g���b�V��
		int x = Trash_X + (i * (SCREEN_WIDTH * 0.85));
		int y = Trash_Y + (i * (SCREEN_HEIGHT * 0.75));
		DrawBox(x, y, x + Size_W, y + Size_H, 0xffffff, false);
		DrawString(x + 15, y + 20, "�g���b�V��", 0xffffff);

		//�f�b�L
		x = Deck_X + (i * (SCREEN_WIDTH * 0.85));
		y = Deck_Y + (i * (SCREEN_HEIGHT * 0.36));
		DrawBox(x, y, x + Size_W, y + Size_H, 0xffffff, false);
		DrawString(x + 15, y + 20, "�f�b�L", 0xffffff);

		//�T�C�h
		for (int h = 0; h < 3; h++)
		{
			if (i != 0) //Player��
			{
				x = Side_X + SCREEN_WIDTH * 0.85;
				y = Side_Y - SCREEN_HEIGHT * 0.05 - h * Size_H;
				DrawBox(x + 20, y - 10, x + Size_W + 20, y + Size_H - 10, 0xffffff, false);
				//���B���p
				DrawBox(x + 20, y + 1, x + Size_W, y + Size_H, 0x000000, true);
				DrawBox(x, y, x + Size_W, y + Size_H, 0xffffff, false);
			}
			else  //CPU��
			{
				y = Side_Y + h * Size_H;
				DrawBox(Side_X, y + 10, Side_X + Size_W, y + Size_H + 10, 0xffffff, false);
				//���B���p
				DrawBox(Side_X + 21, y + 1, Side_X + Size_W+2, y + Size_H, 0x000000, true);
				DrawBox(Side_X + 20, y, Side_X + Size_W + 20, y + Size_H, 0xffffff, false);
			}
		}
		DrawString(Side_X + (i * (SCREEN_WIDTH * 0.85)) + 15, Side_Y - (i * (SCREEN_HEIGHT * 0.3))+10, "�T�C�h", 0xffffff);

		//�x���`
		for (int w = 0; w < 5; w++)
		{
			x = Bench_X + w * (Size_W + 30);
			y = Bench_Y + (i * (SCREEN_HEIGHT * 0.75));
			DrawBox(x, y, x + Size_W, y + Size_H, 0xffffff, false);
		}
		DrawString(Bench_X + 15, Bench_Y + (i * (SCREEN_HEIGHT * 0.75)) + 10, "�x���`", 0xffffff);
	}

	//�X�^�W�A��
	DrawBox(Stadium_X, Stadium_Y, Stadium_X + Size_W, Stadium_Y + Size_H, 0xffffff, false);
	DrawString(Stadium_X + 5, Stadium_Y + 10, "�X�^�W�A��", 0xffffff);
}