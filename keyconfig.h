#pragma once
#include"DxLib.h"
typedef struct {
	char key[20];
	int keybind;
} Keyconfig;
class keyconfig
{
public:
	Keyconfig KC[5] = {
				{  "‰E‰ñ“]", KEY_INPUT_X },
				{ "¶‰ñ“]", KEY_INPUT_Z },
				{ "‰EˆÚ“®", KEY_INPUT_RIGHT},
				{ "¶ˆÚ“®", KEY_INPUT_LEFT},
				{ "‰ºˆÚ“®", KEY_INPUT_DOWN},
	};
};

