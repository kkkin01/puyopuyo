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
				{  80, 180, "�Q�[���X�^�[�g" }, 
				{ 100, 240, "�R���t�B�O" },
				{ 100, 300, "�X�R�A" },
				{ 100, 360, "�Q�[���I��" },
	};
	LPCSTR font_path = "popfont.otf";
	int Font01 = CreateFontToHandle("���m�xPOP v2", 50, 9, DX_FONTTYPE_NORMAL);
	int  Key[256];
	int SelectNum=0;
};