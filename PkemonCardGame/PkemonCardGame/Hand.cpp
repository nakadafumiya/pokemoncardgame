#include "Hand.h"
#include "DxLib.h"
#include "PadInput.h"
#include <time.h>

Hand::Hand()
{
	for (int i = 0; i < MaxHand; i++)
	{
		if (i < 7)
		{
			hand[i] = i;
		}
		else
		{
			hand[i] = -1;
		}

		dPosition[i] = -1;
	}
	HandNum = 7;
	Cursor_X = 0;
	Push_X = 90;

	LoadImages();
}

void Hand::Update()
{
	//to do 確認用
	if (PAD_INPUT::OnClick(XINPUT_BUTTON_X))
	{
		if (HandNum < MaxHand)
		{
			srand((unsigned int)time(NULL));
			DrawCard(rand() % 22);
		}
	}
	
	//カーソル移動
	if (PAD_INPUT::OnClick(XINPUT_BUTTON_DPAD_RIGHT))
	{
		if (HandNum - 1 < ++Cursor_X)
		{
			Cursor_X = 0;
		}
	}
	if (PAD_INPUT::OnClick(XINPUT_BUTTON_DPAD_LEFT))
	{
		if (--Cursor_X < 0)
		{
			Cursor_X = HandNum - 1;
		}
	}

	//決定
	if (PAD_INPUT::OnClick(XINPUT_BUTTON_A))
	{
		SetTrashPosition(Cursor_X);
	}

	if (PAD_INPUT::OnClick(XINPUT_BUTTON_BACK))
	{
		TrashHand();
		//数を減らし終えたら、dcとcsを初期化
		for (int i = 0; i < DecreaseNum; i++)
		{
			dPosition[i] = -1;
		}
		DecreaseNum = 0;
		//カーソル位置が手札の数より大きかったら
		//最後尾に調整する
		if (HandNum < Cursor_X)
		{
			Cursor_X = HandNum - 1;
		}
	}
	//ここまで
}

void Hand::Draw() const
{
	DrawString(1100, 680, "手札", 0xffffff);
	for (int i = 0; i < HandNum; i++)
	{
		DrawFormatString(1100 + 25 * i, 700, 0xffffff, "%d", hand[i]);
	}
	DrawCircle(1105 + 28 * Cursor_X, 730, 5, 0xff0000, true);

	for (int i = 0; i < HandNum; i++)
	{
		int ph = 0;
		int pw = 0;
		//カーソル位置のカードを上に上げる
		if (Cursor_X == i)
		{
			ph = 20;
		}
		//カーソル位置以外のカードを左右にずらす
		if (i < Cursor_X)
		{
			pw = -20;
		}
		else if (Cursor_X < i)
		{
			pw = 20;
		}

		DrawGraph(1000 + i * Push_X + pw, 800 - ph, cardimg[hand[i]], TRUE);
	}

#ifndef DEBUG
#define DEBUG
	/*for (int i = 0; i < 10; i++)
	{
		DrawFormatString(900 + 25 * i, 400, 0xffffff, "%d", hand[i]);
	}*/

	DrawFormatString(1100, 600, 0xff0000, "消す枚数 %d", DecreaseNum);
	DrawString(1250, 600, "消す位置 ", 0xff0000);
	for (int i = 0; i < DecreaseNum; i++)
	{
		DrawFormatString(1380+20*i, 600, 0xff0000, "%d ", dPosition[i]);
	}

	/*DrawString(1300, 680, "カーソル移動 ←→(アナログボタン)", 0x000000);
	DrawString(1300, 700, "選択 A", 0x000000);
	DrawString(1300, 720, "消去 BACK", 0x000000);
	DrawString(1300, 740, "数字を入れる X", 0x000000);*/
#endif // !DEBUG

}

void Hand::DrawCard(int card)
{
	//手札の数を引いた分増やす
	++HandNum;
	//カードの種類を格納
	hand[HandNum - 1] = card;
	if (7 < HandNum)  //手札の数が7枚より上の時
	{
		Push_X -= 5;  //手札が増えた分カードの間隔を狭める
	}
	
}

void Hand::TrashHand()
{
	//指定した位置のカードを消す
	for (int i = 0; i < DecreaseNum; i++)
	{
		hand[dPosition[i]] = -1;
		if (Push_X < 90) //間隔が90未満の時
		{
			Push_X += 5;  //手札が減った分カードの間隔を広げる
		}
	}

	int i = 0;
	//前に詰める
	while (i < HandNum)
	{
		//今見ているのが-1なら後ろから前に詰める
		if (hand[i] == -1)
		{
			for (int j = i; j < HandNum; j++)
			{
				hand[j] = hand[j + 1];
			}
			//最後尾を-1にする・手札の数を減らす
			hand[HandNum - 1] = -1;
			--HandNum;
		}

		//hand[i]が-1じゃないならiを+1する
		if (hand[i] != -1) ++i;
	}
}

void Hand::SetTrashPosition(int position)
{
	dPosition[DecreaseNum] = position;
	++DecreaseNum;
}

void Hand::AllTrash()
{
	for (int i = 0; i < HandNum; i++)
	{ 
		hand[i] = -1;
	}
	HandNum = 0;
}

void Hand::LoadImages()
{
	const char* card[] = { "images/Pokemon_Card_D1/Calyrex_V.png","images/Pokemon_Card_D1/Calyrex_VMAX.png","images/Pokemon_Card_D1/Ralts.png"
		,"images/Pokemon_Card_D1/Kirlia.png","images/Pokemon_Card_D1/Gardevoir_ex.png","images/Pokemon_Card_D1/Diancie.png","images/Pokemon_Card_D1/かがやくゲッコウガ.png"
		,"images/Pokemon_Card_D1/超エネルギー.png","images/Pokemon_Card_D1/OldCemetery.png","images/Pokemon_Card_D1/ポケモンいれかえ.png","images/Pokemon_Card_D1/NestBall.png"
		,"images/Pokemon_Card_D1/ハイパーボール.png","images/Pokemon_Card_D1/FogCrystal.png","images/Pokemon_Card_D1/EscapeRope.png","images/Pokemon_Card_D1/げんきのハチマキ.png"
		,"images/Pokemon_Card_D1/ChoiceBelt.png","images/Pokemon_Card_D1/ふしぎなアメ.png","images/Pokemon_Card_D1/Miriam.png","images/Pokemon_Card_D1/ProfessorsResearch_Sada.png"
		,"images/Pokemon_Card_D1/BosssOrders_GCis.png","images/Pokemon_Card_D1/Serena.png","images/Pokemon_Card_D1/Arven.png"};

	for (int i = 0; i < 22; i++)
	{
		cardimg[i] = LoadGraph(card[i]);
	}
}
