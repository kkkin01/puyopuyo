#include "puyo.h"
#include <ctime>        // time
#include <cstdlib>      // srand,rand
puyo::puyo() {
	ImagePuyo[0] = LoadGraph("puyoimage/img/r.png");
	ImagePuyo[1] = LoadGraph("puyoimage/img/b.png");
	ImagePuyo[2] = LoadGraph("puyoimage/img/g.png");
	ImagePuyo[3] = LoadGraph("puyoimage/img/p.png");
	ImagePuyo[4] = LoadGraph("puyoimage/img/w.png");
	srand(time(NULL));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			tmp[i][j] = rand() % 4;

		}
	}
}
void puyo::DisplayNextPuyo() {
	for (int i = 0; i < 2; i++) {
		DrawGraph(250 + i * 10, 126 + i * 48, ImagePuyo[tmp[i][0]], TRUE);
		DrawGraph(250 + i * 10, 110 + i * 48, ImagePuyo[tmp[i][1]], TRUE);
	}

}
