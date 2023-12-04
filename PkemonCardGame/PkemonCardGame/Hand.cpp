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

void Hand::DrawCard(int card)
{
	//手札の数を引いた分増やす
	++HandNum;

	//カードの種類を格納
	hand[HandNum - 1] = card;
	//hand[HandNum] = poke.GetName(card);

	//手札の数が7枚より上の時間隔を狭める
	if (7 < HandNum)
	{
		Push_X -= 5;  //手札が増えた分カードの間隔を狭める
	}
	
}

void Hand::TrashHand()
{
	//指定した位置のカードを消す
	for (int i = 0; i < DecreaseNum; i++)
	{
		if (i < 5) //一時保存
		{
			saveHand[i] = hand[i];
		}
		//hand[dPosition[i]] = NULL;
		hand[dPosition[i]] = -1;
		if (Push_X < 90) //間隔が90未満の時
		{
			Push_X += 5;  //手札が減った分カードの間隔を広げる
		}
	}

	//数を減らし終えたら、dPositionとDecreaseNumを初期化
	for (int i = 0; i < DecreaseNum; i++)
	{
		dPosition[i] = -1;
	}
	DecreaseNum = 0;

	//手札にカードが残っているか調べる
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
	//残っているカードがある時前に詰める
	if (have_c)
	{
		while (i < HandNum)
		{
			//今見ているのがNULLなら後ろから前に詰める
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
		hand[i] = -1;
		//hand[i] = NULL;
	}
	HandNum = 0;
}

int Hand::DetermineCard(int i,int dtype) const
{
	//デッキタイプが0の時
	if (dtype == 0)
	{
		/*ポケモン*/
		if (hand[i] <= 3)
		{
			return 0;
		}
		if (hand[i] <= 7)
		{
			return 1;
		}
		if (hand[i] <= 11)
		{
			return 2;
		}
		if (hand[i] <= 14)
		{
			return 3;
		}
		if (hand[i] <= 16)
		{
			return 4;
		}
		if (hand[i] == 17)
		{
			return 5;
		}
		if (hand[i] == 18)
		{
			return 6;
		}
		/*道具*/

		/*トレーナーズ*/

	}
	else
	{

	}
	return -1;
}
