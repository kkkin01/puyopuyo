#pragma once
#include "basescene.h"
#include"DxLib.h"
typedef struct {
	int x, y;
	char name[128]; 
} MenuElement;
class menu :public basescene
{
public:
	menu() { SelectNum = 0; }
	void Init() { SelectNum = 0; }
	int  Update();
	void Draw();
	int gpUpdateKey();
private:
	MenuElement Menu[4] = {
				{  80, 180, "ゲームスタート" }, 
				{ 100, 240, "コンフィグ" },
				{ 100, 300, "スコア" },
				{ 100, 360, "ゲーム終了" },
	};
	LPCSTR font_path = "popfont.otf";
	int Font01 = CreateFontToHandle("ラノベPOP v2", 50, 9, DX_FONTTYPE_NORMAL);
	int  Key[256];
	int SelectNum=0;
};