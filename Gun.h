#pragma once
#include "Bullet.h"

class Gun
{
public:
	Gun();
	~Gun();

	void Init();
	void Update();
	void Draw();

	void Shot(const Vector2& pos);

	void Restart();

	int GetBulletNum();
	Bullet** GetBullet();

private:

	static const int bulletNum_ = 6;

	Bullet* bullet[bulletNum_];
	int coolTime_;

	int GH_;
};
