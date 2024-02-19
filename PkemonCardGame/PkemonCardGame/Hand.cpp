#include "Hand.h"
#include "DxLib.h"
#include "PadInput.h"
#include <string.h>

Hand::Hand()
{
	for (int i = 0; i < MaxHand; i++)
	{
		hand[i] = -1;

		dPosition[i] = -1;
	}

	for (int i = 0; i < 5; i++)
	{
		saveHand[i] = -1;
	}
	HandNum = 0;//7
	Push_X = 90;
}

void Hand::AddHand(int card)
{
	//手札の枚数を増やす
	++HandNum;

	//手札の配列に格納する
	hand[HandNum - 1] = card;
	//hand[HandNum] = poke.GetName(card);

	//7枚より枚数が多い時間隔を詰める
	if (7 < HandNum)
	{
		Push_X -= 5;
	}
	
}

void Hand::TrashHand()
{
	//手札の配列から消す
	for (int i = 0; i < DecreaseNum; i++)
	{
		if (i < 5) //一時保存する
		{
			saveHand[i] = hand[i];
		}
		hand[dPosition[i]] = -1;
		//カードの間隔を広げる
		if (Push_X < 90)
		{
			Push_X += 5;
		}
	}

	//削除用の変数を初期化する
	for (int i = 0; i < DecreaseNum; i++)
	{
		dPosition[i] = -1;
	}
	DecreaseNum = 0;

	//手札にカードが残っているか判定
	bool have_c = false; //true:残っている false:残っていない
	for (int i = 0; i < HandNum; i++)
	{
		//カードがある時have_cをtrueにする
		if (hand[i] != -1)
		{
			have_c = true;
			break;
		}
	}


	int i = 0;
	//残っているカードを前に詰める
	if (have_c)
	{
		while (i < HandNum)
		{
			//hand[i]が-1の時後ろのカードを前に詰める
			if (hand[i] == -1)
			{
				for (int j = i; j < HandNum; j++)
				{
					hand[j] = hand[j + 1];
				}
				//最後尾を-1にして、持っている手札の数を減らす
				hand[HandNum - 1] = -1;
				--HandNum;
			}

			//hand[i]が-1じゃない時iを+1する
			if (hand[i] != -1) ++i;
		}
	}
	else
	{
		HandNum = 0;
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
		saveHand[i] = hand[i];
		hand[i] = -1;
	}
	HandNum = 0;
}