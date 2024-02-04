#pragma once
#include <Novice.h>

#include "Camera.h"
#include "Player.h"
#include "EnemyManager.h"
#include "Collition.h"

class Game
{
public:
	Game();
	~Game();

	void Init();
	void Update(char* key);
	void Draw();

	void ResultChange();
	void Restart();

	bool GetIsResultChange();
	bool GetIsClear();

	void SetIsResultChange(const bool& ok) { isResultChange_ = ok; }
	void SetIsClear(const bool& ok) { isClear_ = ok; }

private:

	Camera* camera_;
	Player* player_;
	EnemyManager* enemyManager_;
	Collition* collition_;

	bool isResultChange_;
	bool isClear_;

	int GH;
	int GH2;
	int GH3;
	int GH4;

};