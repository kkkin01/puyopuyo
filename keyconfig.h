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
				{  "右回転", KEY_INPUT_X },
				{ "左回転", KEY_INPUT_Z },
				{ "右移動", KEY_INPUT_RIGHT},
				{ "左移動", KEY_INPUT_LEFT},
				{ "下移動", KEY_INPUT_DOWN},
	};
};

