#include "basescene.h"
#include"DxLib.h"
#include"keyconfig.h"

class config :public basescene,public keyconfig
{
public:
	config();
	void Init() {}
	int  Update();
	void Draw();
	int gpUpdateKey();
	void ChangeKey();
	int SerachChangeKey();
	void SelectKey();
private:
	int SelectNum = 0;
	int Key[256];
	bool ChangeKeyTime = false;
};