#pragma once
#include "DxLib.h"
#include "puyo.h"
#include "stage.h"
class stage;
class player
{
public:
	player();
	void FallCheck();//�Ղ悪�n�ʂɗ����������� �߂�lbool������
	void Genrerate(); //�Ղ���Z�b�g���āAtmp�ɕ�[
	void Move();
	void Rotate();
	void SetPuyo();
	void UpdatateKey();//key����
	void DisplayRotate(int x, double y, int r, int c1, int c2);//�e�����̂Ղ�`��
	void PlayPuyo();
	int FinishCheck();

private:
	puyo P;
	stage S;
	int key[256]={};
	const int initpuyoX = 3;//�Ղ�̏o���ʒu(��)
	const double initpuyoY = S.displayy-16;//�Ղ�̏o���ʒu(���W)
	const int initpuyoR = 0;//�Ղ�̊p�x 0��0��,1��90��,2��180��,3��270��
	double puyoS = 0.5;//�Ղ�̑��x
	int puyoX,puyoR,puyoC1,puyoC2;//�Ղ���
	double puyoY;
	bool canMove = false;
	bool endGame = false;
};