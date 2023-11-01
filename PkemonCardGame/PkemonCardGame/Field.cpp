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

	Battle_X = 500 + STAGE_WIDTH_MIN;
	Battle_Y =	300;
}

void Field::Draw() const
{
	//�w�i
	DrawBoxAA((float)STAGE_WIDTH_MIN, 0.0f, (float)STAGE_WIDTH_MAX, (float)SCREEN_HEIGHT, 0x57af72, true);//0x57bf6a
	/*DrawBoxAA(0.0f, 0.0f, (float)STAGE_WIDTH_MIN, (float)SCREEN_HEIGHT, 0xf5f5f5, true);
	DrawBoxAA((float)STAGE_WIDTH_MAX, 0.0f, (float)SCREEN_WIDTH, (float)SCREEN_HEIGHT, 0xf5f5f5, true);*/

	for (int i = 0; i < 2; i++)
	{
		//�g���b�V��
		float x = static_cast<float>(Trash_X + (i * (STAGE_WIDTH_MAX * 0.63)));
		float y = static_cast<float>(Trash_Y + (i * (SCREEN_HEIGHT * 0.8)));
		DrawBoxAA(x, y, x + Size_W, y + Size_H, 0xffffff, false, Line_Tchickness);
		DrawStringF(x + 15, y + 20, "�g���b�V��", 0xffffff);

		//�f�b�L
		x = static_cast<float>(Deck_X + (i * (STAGE_WIDTH_MAX * 0.63)));
		y = static_cast<float>(Deck_Y + (i * (SCREEN_HEIGHT * 0.48)));
		DrawBoxAA(x, y, x + Size_W, y + Size_H, 0xffffff, false, Line_Tchickness);
		DrawStringF(x + 15, y + 20, "�f�b�L", 0xffffff);

		//�T�C�h
		int correction = 25;  //�␳�l
		x = static_cast<float>(Side_X + i*STAGE_WIDTH_MAX * 0.63);
		for (int h = 0; h < 3; h++)
		{
			int interval = 10 * h;
			if (i != 0) //CPU��
			{
				y = static_cast<float>(Side_Y - SCREEN_HEIGHT * 0.15 - h * Size_H);
				//���
				DrawBoxAA(x + correction, y - (correction+interval), x + Size_W + correction
					, y + Size_H - (correction+interval), 0xffffff, false, Line_Tchickness);
				//���B���p
				DrawBoxAA(x+1, y + 1-interval, x + Size_W, y + Size_H-interval, 0x57af72, true, Line_Tchickness);
				//��O
				DrawBoxAA(x, y-interval, x + Size_W, y + Size_H-interval, 0xffffff, false, Line_Tchickness);
			}
			else  //Player��
			{
				y = Side_Y + h * Size_H;
				//���
				DrawBoxAA(Side_X, y + correction+ interval, Side_X + Size_W, y + Size_H + correction+ interval, 0xffffff, false, Line_Tchickness);
				//���B���p
				DrawBoxAA(Side_X + (correction+1), y + 1 + interval, Side_X + Size_W + 2, y + Size_H + interval, 0x57af72, true, Line_Tchickness);
				//��O
				DrawBoxAA(Side_X + correction, y + interval, Side_X + Size_W + correction, y + Size_H + interval, 0xffffff, false, Line_Tchickness);
			}
		}
		DrawStringF(x + 15, static_cast<float>(Side_Y - (i * (SCREEN_HEIGHT * 0.3)) + 10), "�T�C�h", 0xffffff);

		//�x���`
		y = static_cast<float>(Bench_Y + (i * (SCREEN_HEIGHT * 0.8)));
		for (int w = 0; w < 5; w++)
		{
			x = Bench_X + w * (Size_W + 30);
			DrawBoxAA(x, y, x + Size_W, y + Size_H, 0xffffff, false, Line_Tchickness);
		}
		DrawStringF(Bench_X + 15, static_cast<float>(Bench_Y + (i * (SCREEN_HEIGHT * 0.8)) + 10), "�x���`", 0xffffff);

		//�o�g���t�B�[���h
		y = static_cast<float>(Battle_Y + (i * (SCREEN_HEIGHT * 0.3)));
		DrawBoxAA(Battle_X, y, Battle_X + Size_W, y + Size_H, 0xffffff, false, Line_Tchickness);
		DrawStringF(Battle_X + 15, y + 10, "�o�g���t�B�[���h", 0xffffff);
	}

	//�X�^�W�A��
	DrawBoxAA(Stadium_X, Stadium_Y, Stadium_X + Size_W, Stadium_Y + Size_H, 0xffffff, false, Line_Tchickness);
	DrawStringF(Stadium_X + 5, Stadium_Y + 10, "�X�^�W�A��", 0xffffff);

	//�f�b�h���C��
	/*DrawLineAA(SCREEN_WIDTH * 0.2, 0, SCREEN_WIDTH * 0.2, SCREEN_HEIGHT, 0x00ffff);
	DrawLineAA(SCREEN_WIDTH * 0.8, 0, SCREEN_WIDTH * 0.8, SCREEN_HEIGHT, 0x00ffff);*/
}