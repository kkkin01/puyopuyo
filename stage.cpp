#include <iostream>
#include "DxLib.h"
#include "puyo.h"
#include "stage.h"


using namespace std;

stage::stage() {
	imageBack = LoadGraph("nc77891.jpg");
	scorePoint = 0;
	int ceil[8] = { 0,13,13,13,13,13,13,0 };
	for (int i = 0; i < StageWidth; ++i) {
		for (int j = 0; j < StageHeight; ++j) {
			stagecell[i][j] = 5;
			checkedPuyo[i][j] = false;
		}
	}
	for (int y = 0; y < StageHeight; ++y) {
		stagecell[0][y]=4;
		stagecell[StageWidth-1][y]=4;
	}
	for (int x = 0; x < StageWidth; ++x) {
		stagecell[x][StageHeight-1]=4;
	}
}
void stage::Display() {
	DrawExtendGraph(0, 0, 640, 480, imageBack, false);
	DrawBox(PlacePuyo(0, displayx), PlacePuyo(1, displayx), PlacePuyo(8, displayx), PlacePuyo(14, displayy),black, true);
	for (int i = 0; i < StageWidth; ++i) {
		for (int j = 1; j < StageHeight; ++j) {
			if (stagecell[i][j]!=5) {
				DrawGraph(PlacePuyo(i, displayx), PlacePuyo(j, displayx), Puyo.ImagePuyo[stagecell[i][j]],TRUE);
			}
		}
	}
	DisplayScore();
	//Puyo.DisplayNextPuyo();
}
int stage::PlacePuyo(int x,int y) {
	int n;
	n = x * 16 + y;
	return n;

}
void stage::Log() {
	for (int i = 0; i < StageWidth; i++) {
		for (int j = 0; j < StageHeight; j++) {
			cout << stagecell[i][j];
		}
		cout << endl;
	}
}
void stage::Combo() {
	bool appCombo = false;
	int comboC = 0;//コンボ数
	int removeC = 0;
	do {
		appCombo = false;//コンボするか否か
		removeC = 0; //消すぷよの数
		for (int i = 1; i < StageWidth-1; i++) {
			for (int j = 0; j < StageHeight-1; j++) {
				int countChain = 0;
				InitCheckPuyo();
				if (stagecell[i][j] != 4 && stagecell[i][j] != 5) {//ぷよだった場合
					countChain = GetConnect(i, j, 0, stagecell[i][j]);
					if (countChain >= 4) {//4つ以上つながっていた場合
						RemovePuyo();
						appCombo = true;
						removeC += countChain;
					}
				}
			}
		}
		if (appCombo==true) {
			AddScore(++comboC,removeC);
			WaitTimer(1000);
			ClearDrawScreen();
			DropPuyo();
			Display();
			Puyo.DisplayNextPuyo();
			ScreenFlip();
			WaitTimer(1000);

		}
	} while (appCombo==true);
}
int stage::GetConnect(int x, int y, int count, int color) {//x座標、y座標、chain数、ぷよ色
	if (checkedPuyo[x][y] == true || stagecell[x][y] != color) {
		return count;
	}
	++count;
	checkedPuyo[x][y] = true;
	
	count = GetConnect(x+1, y, count, color);
	count = GetConnect(x, y+1, count, color);
	count = GetConnect(x-1, y, count, color);
	return count;
}
void stage::RemovePuyo() {
	for (int i = 1; i < StageWidth-1; i++) {
		for (int j = 0; j < StageHeight-1;j++) {
			if (checkedPuyo[i][j] == true) {
				stagecell[i][j] = 5;
				++ceil[i];
			}
		}
	}
}
void stage::DropPuyo() {
	for (int i = 1; i < StageWidth-1; i++) {
		for (int j = 0; j < StageHeight-1; j++) {
			if (stagecell[i][j] != 4 && stagecell[i][j] != 5) {//ぷよがある時
				if (stagecell[i][j + 1] == 5) {//下が空いているとき
					ShiftPuyo(i, j);
					DropPuyo();
				}
			}
		}
	}
}
void stage::ShiftPuyo(int x,int y) {
	do {
		stagecell[x][y + 1] = stagecell[x][y];
		--y;
	} while ((stagecell[x][y] != 4 && stagecell[x][y] != 5) && y >= 0);
	stagecell[x][y + 1] = 5;

}
void stage::InitCheckPuyo() {
	for (int i = 0; i < StageWidth; i++) {
		for (int j = 0; j < StageHeight;j++) {
			checkedPuyo[i][j] = false;
		}
	}
}
void stage::AddScore() {
	scorePoint += 20;
}
void stage::AddScore(int n,int m) {
	scorePoint += n * n * 100+n*n*m;

}
void stage::DisplayScore() {
	DrawFormatString(200, 350, GetColor(255, 255, 255), "%d", scorePoint);
}
void stage::IntegrityCheck() {
	for (int i; i < StageWidth; i++) {
		if (ceil[i] > 13) {
			ceil[i] = 13;
		}
	}

}