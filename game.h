#pragma once
#include "player.h"
#include "basescene.h"
class game:public basescene
{
public:
	game();
	void Init();
	int Update();
	void Draw();
private:
	player PL;
};

