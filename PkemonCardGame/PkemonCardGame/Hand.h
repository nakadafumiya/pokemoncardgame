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
	void TrashHand(int start);
	//消すカードを設定する
	void SetTrashPosition(int position)
	{
		cs[dc] = position;
		++dc;
	}
	//手札全部消す
	void AllTrash();

private:
	int hand[10];
	int hand_num;  //持っている手札の数
	int cursor_x;  //カーソル位置
	int dc = 0;    //減らす数
	int cs[10]; //減らす位置
};