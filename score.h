#pragma once
#include <stdio.h>
#include "basescene.h"
#include"DxLib.h"
class score :public basescene
{
public:
	score(int sp);
	void Init();
	int  Update();
	void Draw();
	void Sort();
	void Output();
	void Input();
private:
	int  SB[10];
	int point;
	int score::gpUpdateKey();
	int Key[256];
};