#pragma once
#include "DxLib.h"
#include "puyo.h"
#include <iostream>
class stage
{
public:
	stage();
	void Display();
	int PlacePuyo(int x,int y);

	void Log();
	void Combo();
	void InitCheckPuyo();
	void RemovePuyo();
	int GetConnect(int x, int y, int t, int c);
	void DropPuyo();
	void ShiftPuyo(int x, int y);
	void AddScore();//�Ղ��u�������̃|�C���g
	void AddScore(int n,int m);//c�R���{���̃|�C���g���Z
	void DisplayScore();
	void IntegrityCheck();
	static const auto displayx = 100, displayy = 100;
	int ceil[8] = { 0,13,13,13,13,13,13,0 };//�V��
	int scorePoint = 0; //�X�R�A
private:
	puyo Puyo;
	static const int StageWidth = 8;
	static const int StageHeight = 14;
	int countCombo = 0;
	bool checkedPuyo[StageWidth][StageHeight];
	int countChain=0;
	int imageBack;//�w�i�摜
	int black = GetColor(0, 0, 0);//��
public:
	int stagecell[StageWidth][StageHeight];
};

