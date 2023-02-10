#include"config.h"
config::config() {
}
int config::Update() {
	if (Key[KEY_INPUT_ESCAPE] == 1) {
		return 0;
	}
	else {
		return 5;
	}
}
void config::Draw() {
	gpUpdateKey();
	SelectKey();
	ChangeKey();
	int x = 100;
	SetFontSize(32);
	DrawFormatString(200, 20, GetColor(255, 255, 255), "設定");
	SetFontSize(16);
	for (int i = 0; i < 5; i++) {
		if (SelectNum == i) {
			x = 20;
		}
		else {
			x = 0;
		}
		DrawFormatString(100-x, 50 * i + 100, GetColor(255, 255, 255), "%s   %d",KC[i].key,KC[i].keybind);
	}
	DrawFormatString(50, 450, GetColor(255, 255, 255), "ESCでタイトルに戻る");
	DrawFormatString(500, 450, GetColor(255, 255, 255), "*未完成");
}
int config::gpUpdateKey() {
	char tmpKey[256];
	GetHitKeyStateAll(tmpKey);
	for (int i = 0; i < 256; i++) {
		if (tmpKey[i] != 0) {
			Key[i]++;
		}
		else {
			Key[i] = 0;
		}
	}
	return 0;
}
void config::SelectKey() {
		if (Key[KEY_INPUT_DOWN] == 1) {

			SelectNum = (SelectNum + 1) % 5;
		}
		else if (Key[KEY_INPUT_UP] == 1) {

			SelectNum = (SelectNum + 4) % 5;
		}

}
void config::ChangeKey() {//キー変更を受け付ける
	if (Key[KEY_INPUT_Z] == 1) {
		KC[SelectNum].keybind = SerachChangeKey();
	}
}
int config::SerachChangeKey() {//キー入力に応じて入力したキーを返したいが上手くいかない
	char tmp[256];
	bool InputedKey = false;
	GetHitKeyStateAll(tmp);
	for (int i = 0; i < 256; i++) {
		if (tmp[i] > 0 && i != KEY_INPUT_Z) {
			InputedKey = true;
			return i;
		}
	}
	return 0;
}