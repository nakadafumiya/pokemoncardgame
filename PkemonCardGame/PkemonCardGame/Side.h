#pragma once
#include "AbstractScene.h"
class Side : AbstractScene
{
private:
	int count; //�T�C�h����

public:
	virtual AbstractScene* Update();
	virtual void Draw()const;
};

