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

	int TitleImage; //�^�C�g�����
	int BackTitle;  //�^�C�g���w�i

public:
	Title();
	virtual AbstractScene* Update();
	virtual void Draw()const;
};

