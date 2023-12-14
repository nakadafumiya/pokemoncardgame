#pragma once
#include "AbstractScene.h"
class End :public AbstractScene
{
private:
	//画像
	int Gardevoir;  //サーナイト
	int Budrex;     //コクバ
	int Arceus;     //アルセウス
	int Rayquaza;   //レックウザ

	int EndBack;    //背景

	int count;

public:
	End();
	virtual AbstractScene* Update();
	virtual void Draw()const;

};