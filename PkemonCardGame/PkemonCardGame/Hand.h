#pragma once
#include "Card_Deck.h"
#include "Pokemon.h"

class Hand
{
public:
	Hand();
	//手札を増やす
	void DrawCard(int card);
	//手札を減らす
	void TrashHand();
	//消すカードを設定する
	void SetTrashPosition(int position);
	//手札全部消す
	void AllTrash();
	//char* SendCardName(int i) { return saveHand[i]; }
	int SendCardName(int i) { return saveHand[i]; }
	void InitSaveHand()
	{
		/*for (int i = 0; i < 5; i++)
		{
			if (saveHand[i] == NULL) break;
			saveHand[i] = NULL;
		}*/

		for (int i = 0; i < 5; i++)
		{
			if (saveHand[i] == -1) break;
			saveHand[i] = -1;
		}
	}
	//描画するカードを判別
	int DetermineCard(int i ,int dtype)const;

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