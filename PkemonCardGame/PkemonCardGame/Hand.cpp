#include "Hand.h"
#include "DxLib.h"
#include "PadInput.h"
#include <time.h>

Hand::Hand()
{
	for (int i = 0; i < 10; i++)
	{
		if (i < 7)
		{
			hand[i] = i;
		}
		else
		{
			hand[i] = -1;
		}

		cs[i] = -1;
	}
	hand_num = 7;
	cursor_x = 0;
}

void Hand::Update()
{
	//to do 確認用
	//if (PAD_INPUT::OnClick(XINPUT_BUTTON_X))
	//{
	//	srand((unsigned int)time(NULL));
	//	DrawCard(rand() % 10+1);
	//}
	//
	////カーソル移動
	//if (PAD_INPUT::OnClick(XINPUT_BUTTON_DPAD_RIGHT))
	//{
	//	if (hand_num - 1 < ++cursor_x)
	//	{
	//		cursor_x = 0;
	//	}
	//}
	//if (PAD_INPUT::OnClick(XINPUT_BUTTON_DPAD_LEFT))
	//{
	//	if (--cursor_x < 0)
	//	{
	//		cursor_x = hand_num - 1;
	//	}
	//}

	////決定
	//if (PAD_INPUT::OnClick(XINPUT_BUTTON_A))
	//{
	//	SetTrashPosition(cursor_x);
	//}

	//if (PAD_INPUT::OnClick(XINPUT_BUTTON_BACK))
	//{
	//	TrashHand(0);
	//	//数を減らし終えたら、dcとcsを初期化
	//	dc = 0;
	//	for (int i = 0; i < 10; i++)
	//	{
	//		cs[i] = -1;
	//	}
	//}
	//ここまで
}

void Hand::Draw() const
{
	DrawString(1100, 680, "手札", 0xffffff);
	for (int i = 0; i < hand_num; i++)
	{
		DrawFormatString(1100 + 25 * i, 700, 0xffffff, "%d", hand[i]);
	}
	DrawCircle(1105 + 28 * cursor_x, 730, 5, 0xff0000, true);

	DrawString(1300, 680, "カーソル移動 ←→(アナログボタン)", 0x000000);
	DrawString(1300, 700, "選択 A", 0x000000);
	DrawString(1300, 720, "消去 BACK", 0x000000);
	DrawString(1300, 740, "数字を入れる X", 0x000000);

#ifndef DEBUG
#define DEBUG
	/*for (int i = 0; i < 10; i++)
	{
		DrawFormatString(900 + 25 * i, 400, 0xffffff, "%d", hand[i]);
	}*/

	DrawFormatString(1100, 600, 0xff0000, "消す枚数 %d", dc);
	DrawString(1250, 600, "消す位置 ", 0xff0000);
	for (int i = 0; i < dc; i++)
	{
		DrawFormatString(1380+20*i, 600, 0xff0000, "%d ", cs[i]);
	}
#endif // !DEBUG

}

void Hand::DrawCard(int card)
{
	//手札の数を引いた分増やす
	++hand_num;
	//カードの種類を格納
	hand[hand_num - 1] = card;
}

void Hand::TrashHand(int start)
{
	//指定した位置のカードを消す
	for (int i = 0; i < dc; i++)
	{
		hand[cs[i]] = -1;
	}

	int i = 0;
	//前に詰める
	while (i < hand_num)
	{
		//今見ているのが-1なら後ろを前に詰める
		if (hand[i] == -1)
		{
			for (int j = i; j < hand_num; j++)
			{
				hand[j] = hand[j + 1];
			}
			//最後尾を-1にする・手札の数を減らす
			hand[hand_num - 1] = -1;
			--hand_num;
		}

		//hand[i]が-1じゃないならiを+1する
		if (hand[i] != -1) ++i;
	}
}

void Hand::AllTrash()
{
	for (int i = 0; i < hand_num; i++)
	{ 
		hand[i] = -1;
	}
	hand_num = 0;
}
