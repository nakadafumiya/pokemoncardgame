#include "Field.h"
#include "DxLib.h"
#include "common.h"

#define STAGE_WIDTH_MIN SCREEN_WIDTH * 0.2
#define STAGE_WIDTH_MAX SCREEN_WIDTH * 0.8

Field::Field()
{
	Trash_X = 40 + STAGE_WIDTH_MIN;
	Trash_Y = 30;

	Deck_X = 40 + STAGE_WIDTH_MIN;
	Deck_Y = Trash_Y + Size_H + 20;

	Side_X = 30 + STAGE_WIDTH_MIN;
	Side_Y = SCREEN_HEIGHT * 0.5;

	Bench_X = 250 + STAGE_WIDTH_MIN;
	Bench_Y = 15;

	Stadium_X = 200 + STAGE_WIDTH_MIN;
	Stadium_Y = 400;
}

void Field::Draw() const
{
	for (int i = 0; i < 2; i++)
	{
		//�g���b�V��
		int x = Trash_X + (i * (STAGE_WIDTH_MAX * 0.63));
		int y = Trash_Y + (i * (SCREEN_HEIGHT * 0.8));
		DrawBox(x, y, x + Size_W, y + Size_H, 0xffffff, false);
		DrawString(x + 15, y + 20, "�g���b�V��", 0xffffff);

		//�f�b�L
		x = Deck_X + (i * (STAGE_WIDTH_MAX * 0.63));
		y = Deck_Y + (i * (SCREEN_HEIGHT * 0.48));
		DrawBox(x, y, x + Size_W, y + Size_H, 0xffffff, false);
		DrawString(x + 15, y + 20, "�f�b�L", 0xffffff);

		//�T�C�h
		int correction = 25;  //�␳�l
		x = Side_X + STAGE_WIDTH_MAX * 0.63;
		for (int h = 0; h < 3; h++)
		{
			int interval = 10 * h;
			if (i != 0) //CPU��
			{
				y = Side_Y - SCREEN_HEIGHT * 0.15 - h * Size_H;
				//���
				DrawBox(x + correction, y - (correction+interval), x + Size_W + correction, y + Size_H - (correction+interval), 0xffffff, false);
				//���B���p
				DrawBox(x + correction, y + 1-interval, x + Size_W, y + Size_H-interval, 0x000000, true);
				//��O
				DrawBox(x, y-interval, x + Size_W, y + Size_H-interval, 0xffffff, false);
			}
			else  //Player��
			{
				y = Side_Y + h * Size_H;
				//���
				DrawBox(Side_X, y + correction+ interval, Side_X + Size_W, y + Size_H + correction+ interval, 0xffffff, false);
				//���B���p
				DrawBox(Side_X + (correction+1), y + 1 + interval, Side_X + Size_W + 2, y + Size_H + interval, 0x000000, true);
				//��O
				DrawBox(Side_X + correction, y + interval, Side_X + Size_W + correction, y + Size_H + interval, 0xffffff, false);
			}
		}
		DrawString(Side_X + (i * (STAGE_WIDTH_MAX * 0.63)) + 15, Side_Y - (i * (SCREEN_HEIGHT * 0.3))+10, "�T�C�h", 0xffffff);

		//�x���`
		y = Bench_Y + (i * (SCREEN_HEIGHT * 0.8));
		for (int w = 0; w < 5; w++)
		{
			x = Bench_X + w * (Size_W + 30);
			DrawBox(x, y, x + Size_W, y + Size_H, 0xffffff, false);
		}
		DrawString(Bench_X + 15, Bench_Y + (i * (SCREEN_HEIGHT * 0.8)) + 10, "�x���`", 0xffffff);
	}

	//�X�^�W�A��
	DrawBox(Stadium_X, Stadium_Y, Stadium_X + Size_W, Stadium_Y + Size_H, 0xffffff, false);
	DrawString(Stadium_X + 5, Stadium_Y + 10, "�X�^�W�A��", 0xffffff);

	//�f�b�h���C��
	DrawLine(SCREEN_WIDTH * 0.2, 0, SCREEN_WIDTH * 0.2, SCREEN_HEIGHT, 0x0000ff);
	DrawLine(SCREEN_WIDTH * 0.8, 0, SCREEN_WIDTH * 0.8, SCREEN_HEIGHT, 0x0000ff);

}