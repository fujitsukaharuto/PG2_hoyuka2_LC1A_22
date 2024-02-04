#pragma once
#include "Title.h"
#include "Game.h"
#include "Result.h"
#include "Vector2Matrix.h"

class Scene
{
public:
	Scene();
	~Scene();
	
	void Init();
	void Update(char* key);
	void Draw();

	void SceneTrance();
	void Ease();
	void SceneChange();

private:

	Title* title_;
	Game* game_;
	Result* result_;

	int tranceTime_;
	Vector2 blackPos_;

	bool isTitle_;
	bool isGame_;
	bool isResult_;
	bool isChange_;
	bool isSceneTrance_;
};