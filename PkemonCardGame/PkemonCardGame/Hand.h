#pragma once
#include "Card_Deck.h"
#include "Pokemon.h"

class Hand
{
public:
	Hand();
	//手札を増やす
	void AddHand(int card);
	//手札を減らす
	void TrashHand();
	//消すカードを設定する
	void SetTrashPosition(int position);
	//手札全部消す
	void AllTrash();
	int SendCardID(int i) { return saveHand[i]; }
	//一時保存していたカードを消す
	void InitSaveHand()
	{
		for (int i = 0; i < 5; i++)
		{
			if (saveHand[i] == -1) break;
			saveHand[i] = -1;
		}
	}
	//手札に「たね」が存在するか
	bool IsSeedInHand()
	{
		for (int i = 0; i < HandNum; i++)
		{
			if (hand[i] <= 9) //元：18 IDが18以下のとき[たね]が存在する
			{
				return true;
			}
		}

		return false;
	}
	int GetHand(int i) { return hand[i]; }
	void DecreaseHandNum() { --HandNum; }

protected:
	int hand[10]; //手札
	//char* hand[10]; //char型手札
	//char* saveHand[5]; //一時保存用
	int saveHand[5];
	int HandNum;  //持っている手札の数
	int DecreaseNum = 0;    //減らす数
	int dPosition[10]; //減らす位置
	int Push_X;  //手札が増えるたびに横に詰める
	const int MaxHand = 10;  //最大で持てる手札の数

private:
	Card_Deck deck;
	Pokemon poke;
};