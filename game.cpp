#include "game.h"

game::game() {

}
void game::Init() {
}
int game::Update() {
	int score = PL.FinishCheck();
	if (score==0) {
		return 0;
	}
	else {
		return score;
	}
}
void game::Draw() {
	PL.PlayPuyo();
}
