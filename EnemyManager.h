#pragma once
#include "Enemy.h"

class EnemyManager
{
public:
	EnemyManager();
	~EnemyManager();

	void Init();
	void Update();
	void Draw();

	void CreatEnemy();
	void MoveCreatPos();
	void EnemyKillAdd();

	void Restart();

	int GetEnemyKillNum();
	int GetEnemyNum();
	Enemy** GetEnemy();

private:
	static const int enemyNum_ = 6;
	int coolTime_;
	Vector2 creatPos_;
	int enemyKillNum_;

	Enemy* enemy_[enemyNum_];
	int GH_;

};
