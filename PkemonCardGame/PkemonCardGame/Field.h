#pragma once
class Field
{
private:
	float Side_X, Side_Y;
	float Deck_X, Deck_Y;
	float Trash_X, Trash_Y;
	float Bench_X, Bench_Y;
	float Stadium_X, Stadium_Y;
	float Battle_X, Battle_Y;
	const int Size_H = 150;
	const int Size_W = 110;
	const float Line_Tchickness = 3.0;

public:
	Field();
	void Draw()const;
};