#pragma once
#include "DxLib.h"
#include "puyo.h"
#include "stage.h"
class stage;
class player
{
public:
	player();
	void FallCheck();//ぷよが地面に落ちたか判定 戻り値bool説ある
	void Genrerate(); //ぷよをセットして、tmpに補充
	void Move();
	void Rotate();
	void SetPuyo();
	void UpdatateKey();//key入力
	void DisplayRotate(int x, double y, int r, int c1, int c2);//各向きのぷよ描画
	void PlayPuyo();
	int FinishCheck();

private:
	puyo P;
	stage S;
	int key[256]={};
	const int initpuyoX = 3;//ぷよの出現位置(列)
	const double initpuyoY = S.displayy-16;//ぷよの出現位置(座標)
	const int initpuyoR = 0;//ぷよの角度 0で0°,1で90°,2で180°,3で270°
	double puyoS = 0.5;//ぷよの速度
	int puyoX,puyoR,puyoC1,puyoC2;//ぷよ情報
	double puyoY;
	bool canMove = false;
	bool endGame = false;
};