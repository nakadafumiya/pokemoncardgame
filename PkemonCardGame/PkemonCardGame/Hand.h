#pragma once

class Hand
{
public:
	Hand();
	void Update();
	void Draw()const;
	//手札を増やす
	void DrawCard(int card);
	//手札を減らす
	void TrashHand();
	//消すカードを設定する
	void SetTrashPosition(int position);
	//手札全部消す
	void AllTrash();
	void LoadImages();

private:
	int cardimg[22]; //カード画像
	int hand[10]; //手札
	int HandNum;  //持っている手札の数
	int Cursor_X;  //カーソル位置
	int DecreaseNum = 0;    //減らす数
	int dPosition[10]; //減らす位置
	int Push_X;  //手札が増えるたびに横に詰める

	const int MaxHand = 10;  //最大で持てる手札の数
};