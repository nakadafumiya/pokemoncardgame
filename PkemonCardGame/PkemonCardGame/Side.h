#pragma once
#include "AbstractScene.h"
#include "DxLib.h"
class Side
{
private:

	
	int count; 
	int side[6];

	int BackCard;
public:

	Side();
	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update();
	//�`��Ɋւ��邱�����������
	virtual void Draw()const;
}; 

