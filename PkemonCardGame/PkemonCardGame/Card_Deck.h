#pragma once
#include <iostream>
#include <random>

#define DECK 60
#define INITIAL_DECK 7
#define MIN_DECK 1
//#define MAX_DECK 

//カード排出クラス
class Card_Deck
{
private:
	int deck_num; //デッキ数
	int card_num; //カード枚数
	int* deck;	  //格納配列
	int* p_deck;  //配列先頭ポインタ
	int image;

public:
	//コンストラクタ：引数はデッキ数
	Card_Deck(int input_deck_num = MIN_DECK)
	{
		//デッキ数の決定
		if (input_deck_num < MIN_DECK)
		{
			deck_num = MIN_DECK; //最小値
		}
		else {
			deck_num = input_deck_num; //入力値
		}
		//else if (input_deck_num > MAX_DECK)
		//{
		//	deck_num = MAX_DECK; //最大値
		//}

		card_num = deck_num * DECK;

		deck = new int[card_num]; //メモリ確保
		p_deck = &deck[0]; //先頭ポインタの設定

		//配列の初期化
		for (int i = 0; i < card_num; i++)
		{
			deck[i] = -1;
		}

		std::random_device rnd;	//乱数生成器

		//挿入するカードを順に変える
		for (int i = 0; i < card_num; i++)
		{
			//挿入位置にカードを挿入するまでループ
			while (true)
			{
				int place = rnd() % (card_num); //挿入位置の決定
				if (deck[place] == -1)
				{
					//カードの格納
					deck[place] = i % DECK;
					break; //ループを抜ける
				}
			}
		}
	}
	//デストラクタ
	~Card_Deck()
	{
		delete[] deck; //メモリ解放
	}

	//カードの排出
	int hand_card()
	{
		int hand = p_deck[0]; //排出するカードの数値を確定
		//配列処理
		p_deck++; //先頭ポインタをずらす
		card_num--; //カード枚数を減らす
		return hand; //排出するカードの数値を渡す
	}
public:
	Card_Deck();
	void Draw();
};