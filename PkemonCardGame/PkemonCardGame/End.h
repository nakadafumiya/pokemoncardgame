#pragma once
#include "AbstractScene.h"
class End :public AbstractScene
{
private:
	//�摜
	int Gardevoir;  //�T�[�i�C�g
	int Budrex;     //�R�N�o
	int Arceus;     //�A���Z�E�X
	int Rayquaza;   //���b�N�E�U

	int EndBack;    //�w�i

	int count;

public:
	End();
	virtual AbstractScene* Update();
	virtual void Draw()const;

};