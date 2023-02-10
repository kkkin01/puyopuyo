#pragma once
#include "scenechange.h"
typedef enum {
	sceneMenu,
	sceneGame,
	sceneConfig,
	sceneScore,
	sceneNone
}Scene;
class scenechange
{
public:
	virtual void SceneChange(Scene Nscene)=0;

};

