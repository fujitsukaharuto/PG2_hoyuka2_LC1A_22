#pragma once
#include "Bullet.h"

class EnemyGun
{
public:
	EnemyGun();
	~EnemyGun();

	void Init();
	void Update();
	void Draw();

	void Shot(const Vector2& pos);

	void Restart();

	int GetBulletNum();
	Bullet** GetBullet();

private:
	static const int bulletNum_ = 3;
	int coolTime_;
	int GH_;

	Bullet* bullet_[bulletNum_];

};