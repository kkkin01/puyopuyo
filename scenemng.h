#pragma once
#include "scenechange.h"
#include "game.h"
#include"menu.h"
#include"score.h"
#include"config.h"

class scenemng:public scenechange
{
public:
	void Init();
	void Draw();
	void Update();
	void SceneChangeCheck();
	void CurrentSceneChange(Scene Cscene);
	void SceneChange(Scene Nscene);
	basescene* SceneMng= (basescene*)new menu();
	Scene NextScene=sceneMenu;
	Scene CurrentScene = sceneMenu;
private:
	int scorepoint=0;
};

