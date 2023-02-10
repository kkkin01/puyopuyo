#pragma once
#include "DxLib.h"
class puyo
{
public:
	puyo();
	int ImagePuyo[5];
	void DisplayNextPuyo();
	int tmp[3][2];// —\‘ª‚Õ‚æ’u‚«ê
private:
	enum PuyoS{red=0,blue,green,purple,wall,empty};
	enum PuyoR{ro0,ro90,ro180,ro270};
};

