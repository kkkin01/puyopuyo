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
	void AddScore();//ぷよを置いた時のポイント
	void AddScore(int n,int m);//cコンボ時のポイント加算
	void DisplayScore();
	void IntegrityCheck();
	static const auto displayx = 100, displayy = 100;
	int ceil[8] = { 0,13,13,13,13,13,13,0 };//天井
	int scorePoint = 0; //スコア
private:
	puyo Puyo;
	static const int StageWidth = 8;
	static const int StageHeight = 14;
	int countCombo = 0;
	bool checkedPuyo[StageWidth][StageHeight];
	int countChain=0;
	int imageBack;//背景画像
	int black = GetColor(0, 0, 0);//黒
public:
	int stagecell[StageWidth][StageHeight];
};

