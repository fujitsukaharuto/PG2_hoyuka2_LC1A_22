#include "EnemyGun.h"
#include <Novice.h>

EnemyGun::EnemyGun()
{
	Init();
}

EnemyGun::~EnemyGun()
{
	for (int i = 0; i < bulletNum_; i++)
	{
		delete bullet_[i];
	}
}


void EnemyGun::Init()
{
	for (int i = 0; i < bulletNum_; i++)
	{
		bullet_[i] = new Bullet();
	}
	coolTime_ = 50;
	GH_ = Novice::LoadTexture("./Resource/enemy__bullet.png");
}


void EnemyGun::Update()
{
	for (int i = 0; i < bulletNum_; i++)
	{
		bullet_[i]->Update();
	}
	if (coolTime_ > 0)
	{
		coolTime_--;
	}
}


void EnemyGun::Draw()
{
	for (int i = 0; i < bulletNum_; i++)
	{
		bullet_[i]->Draw(GH_);
	}
}


void EnemyGun::Shot(const Vector2& pos)
{
	if (coolTime_ <= 0)
	{
		for (int i = 0; i < bulletNum_; i++)
		{
			if (!bullet_[i]->GetIsLive())
			{
				bullet_[i]->SetIsLive(true);
				bullet_[i]->SetEnemyMode(true);
				bullet_[i]->SetPos(pos);
				bullet_[i]->SetRadius(5);
				bullet_[i]->SetSpeed(4);
				coolTime_ = 30;
				break;
			}
		}
	}
}

void EnemyGun::Restart()
{
	for (int i = 0; i < bulletNum_; i++)
	{
		bullet_[i]->Restart();
	}
	coolTime_ = 50;
}


int EnemyGun::GetBulletNum()
{
	return bulletNum_;
}
Bullet** EnemyGun::GetBullet()
{
	return bullet_;
}
