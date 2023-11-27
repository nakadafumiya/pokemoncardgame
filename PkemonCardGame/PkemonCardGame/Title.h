#pragma once
#include "AbstractScene.h"
#include "DxLib.h"
#include "common.h"
#include "PadInput.h"

class Title : public AbstractScene
{
private:

	//�摜
	int Gardevoir;  //�T�[�i�C�g
	int Budrex;     //�R�N�o
	int Arceus;     //�A���Z�E�X
	int Rayquaza;   //���b�N�E�U

	int GardevoirCard;  //�T�[�i�C�g�J�[�h
	int BudrexCard;     //�R�N�o�J�[�h
	int ArceusCard;     //�A���Z�E�X�J�[�h
	int RayquazaCard;   //���b�N�E�U�J�[�h

	int TitleImage; //�^�C�g�����
	int BackTitle;  //�^�C�g���w�i

	int interval;
	int JoyPadX;
	int JoyPadY;
	int select;

public:
	Title();
	virtual AbstractScene* Update();
	virtual void Draw()const;
};

