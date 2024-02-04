#pragma once
#include "Player.h"
#include "EnemyManager.h"

class Collition
{
public:
	Collition(Player* player, EnemyManager* enemymanager);
	~Collition();

	void Init(Player* player, EnemyManager* enemymanager);
	void Update();

	void Hit();
	void HitBullet();
	void HitEnemyBullet();

	bool IsHit(const Vector2& one, const Vector2& two, const float& radius1, const float& radius2);

private:

	Player* player_;
	EnemyManager* enemymanager_;

};