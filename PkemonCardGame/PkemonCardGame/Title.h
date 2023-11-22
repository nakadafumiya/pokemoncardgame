#pragma once
#include "AbstractScene.h"
#include "DxLib.h"
#include "common.h"
#include "PadInput.h"

class Title : public AbstractScene
{
private:

	//画像
	int Gardevoir;  //サーナイト
	int Budrex;     //コクバ
	int Arceus;     //アルセウス
	int Rayquaza;   //レックウザ

	int TitleImage; //タイトル画面
	int BackTitle;  //タイトル背景

public:
	Title();
	virtual AbstractScene* Update();
	virtual void Draw()const;
};

