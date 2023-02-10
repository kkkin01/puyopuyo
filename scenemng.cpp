#include "scenemng.h"
void scenemng::Init() {
	basescene* SceneMng = (basescene*)new menu();
	NextScene = sceneMenu;
}
void scenemng::Update() {
	if (NextScene != sceneNone) {
		delete SceneMng;
		switch (NextScene) {
		case sceneGame:
			SceneMng =(basescene*)new game();
			CurrentScene = sceneGame;
			break;
		case sceneMenu:
			SceneMng = (basescene*)new menu();
			CurrentScene = sceneMenu;
			break;
		case sceneScore:
			SceneMng = (basescene*)new score(scorepoint);
			CurrentScene = sceneMenu;
			break;
		case sceneConfig:
			SceneMng = (basescene*)new config();
			CurrentScene = sceneConfig;
		}
		NextScene = sceneNone;
	}
	SceneChangeCheck();
}
void scenemng::Draw(){
	SceneMng->Draw();
}
void scenemng::SceneChange(Scene Nscene) {
	NextScene = Nscene;
}
void scenemng::SceneChangeCheck() {
	if (CurrentScene == sceneGame) {  //�Q�[����ʂ̂Ƃ�
		scorepoint = SceneMng->Update();
		if (scorepoint != 0) {
			NextScene = sceneScore;
		}
	}
	else {
		switch (SceneMng->Update()) {//�Q�[����ʈȊO�̂Ƃ�
		case 0:
			NextScene = sceneMenu;
			break;
		case 1:
			NextScene = sceneGame;
			break;
		case 2:
			NextScene = sceneConfig;
			break;
		case 3:
			NextScene = sceneScore;
			break;
		case 4:
			DxLib_End();
			break;
		case 5:
			break;


		}
	}
}