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
				{  "�E��]", KEY_INPUT_X },
				{ "����]", KEY_INPUT_Z },
				{ "�E�ړ�", KEY_INPUT_RIGHT},
				{ "���ړ�", KEY_INPUT_LEFT},
				{ "���ړ�", KEY_INPUT_DOWN},
	};
};

