#pragma once
#include "DxLib.h"
#include "puyo.h"
#include "stage.h"
class stage;
class player
{
public:
	player();
	void FallCheck();//ΥζͺnΚΙΏ½©»θ ίθlboolΰ ι
	void Genrerate(); //ΥζπZbg΅ΔAtmpΙβ[
	void Move();
	void Rotate();
	void SetPuyo();
	void UpdatateKey();//keyόΝ
	void DisplayRotate(int x, double y, int r, int c1, int c2);//eό«ΜΥζ`ζ
	void PlayPuyo();
	int FinishCheck();//IΉ»θ
	int FinishCheck(bool b);

private:
	puyo P;
	stage S;
	int key[256]={};
	const int initpuyoX = 3;//ΥζΜo»Κu(ρ)
	const double initpuyoY = S.displayy-16;//ΥζΜo»Κu(ΐW)
	const int initpuyoR = 0;//ΥζΜpx 0Ε0,1Ε90,2Ε180,3Ε270
	double puyoS = 0.5;//ΥζΜ¬x
	int puyoX,puyoR,puyoC1,puyoC2;//Υζξρ
	double puyoY;
	bool canMove = false;
	bool endGame = false;
};