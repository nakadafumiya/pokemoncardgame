#pragma once
#include "AbstractScene.h"
class Help :public AbstractScene
{
private:
	int Backimage;
	int image;
	int image2;

public:
	Help();
	virtual AbstractScene* Update();
	virtual void Draw()const;
};

