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

	int GardevoirCard;  //サーナイトカード
	int BudrexCard;     //コクバカード
	int ArceusCard;     //アルセウスカード
	int RayquazaCard;   //レックウザカード

	int TitleImage; //タイトル画面
	int BackTitle;  //タイトル背景

	int interval;
	int JoyPadX;
	int JoyPadY;
	int select;

public:
	Title();
	virtual AbstractScene* Update();
	virtual void Draw()const;
};

