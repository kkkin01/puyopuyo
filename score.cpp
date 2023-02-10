#include "score.h"
score::score(int sp) {
	for (int i = 0; i < 10; i++) {
		SB[i] = 0;
	}
	Input();
	point = sp;
	Sort();
	Output();
}
void score::Init() {
}
int score::Update() {
	gpUpdateKey();
	if (Key[KEY_INPUT_ESCAPE] == 1) {
		return 0;
	}
	else {
		return 5;
	}
}
void score::Draw() {
	SetFontSize(32);
	//DrawFormatString(300, 20, GetColor(255, 255, 255), "%d",point);
	DrawFormatString(200,20, GetColor(255, 255, 255), "スコアボード");
	SetFontSize(16);
	for (int i = 0; i < 10; i++) {
		DrawFormatString(50, 30 * i + 100-32*(i/10), GetColor(255, 255, 255), "%d位 %d ポイント", i + 1, SB[i]);
	}
	DrawFormatString(50, 450, GetColor(255, 255, 255), "ESCでタイトルに戻る");
}
void score::Sort() {//スコアに乗るスコアなら並び替え
	int a;
	for (int i = 9; i >=0;i--) {
		if (point > SB[i]) {
			a = i;
		}
	}
	for (int i = 9; i > a; i--) {
		SB[i] = SB[i - 1];
	}
	SB[a] = point;
}
void score::Input() {//スコア保存ファイルからの読み取り
	FILE* fp=NULL;
	if (fopen_s(&fp, "savedata.dat", "rb") != 0) {
		printf("File not open");
	}
	else {
		fread(SB, sizeof(int), sizeof(SB) / sizeof(SB[0]), fp);
		fclose(fp);
	}

}
void score::Output() {//スコア保存ファイルへの書き込み
	FILE* fp;
	if (fopen_s(&fp, "savedata.dat", "wb") != 0) {
		printf("File not open");
	}
	else {
		fwrite(SB, sizeof(int), sizeof(SB) / sizeof(SB[0]), fp);
		fclose(fp);
	}
}
int score::gpUpdateKey() {
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