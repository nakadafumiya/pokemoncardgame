#pragma once
#include "AbstractScene.h"
class Side : AbstractScene
{
private:
	int count; //ƒTƒCƒh–‡”

public:
	virtual AbstractScene* Update();
	virtual void Draw()const;
};

