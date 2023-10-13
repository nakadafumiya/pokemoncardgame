#pragma once
class Field
{
private:
	int Side_X, Side_Y;
	int Deck_X, Deck_Y;
	int Trash_X, Trash_Y;
	int Bench_X, Bench_Y;
	int Stadium_X, Stadium_Y;
	const int Size_H = 130;
	const int Size_W = 100;

public:
	Field();
	void Draw()const;
};