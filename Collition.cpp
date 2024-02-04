#include "Collition.h"
#include "MathCalculation.h"

Collition::Collition(Player* player, EnemyManager* enemymanager)
{
	Init(player, enemymanager);
}

Collition::~Collition()
{
}

void Collition::Init(Player* player, EnemyManager* enemymanager)
{
	player_ = player;
	enemymanager_ = enemymanager;
}

void Collition::Update()
{
	Hit();
	HitBullet();
	HitEnemyBullet();
}

void Collition::Hit()
{
	for (int i = 0; i < enemymanager_->GetEnemyNum(); i++)
	{
		if (enemymanager_->GetEnemy()[i]->GetIsLive())
		{
			if (IsHit(player_->GetPos(),
				enemymanager_->GetEnemy()[i]->GetPos(),
				player_->GetRadius(),
				enemymanager_->GetEnemy()[i]->GetRadius()))
			{
				player_->HpDec();
				enemymanager_->GetEnemy()[i]->SetIsLive(false);
			}
		}
	}
}

void Collition::HitBullet()
{
	for (int i = 0; i < enemymanager_->GetEnemyNum(); i++)
	{
		if (enemymanager_->GetEnemy()[i]->GetIsLive())
		{
			for (int j = 0; j < player_->GetGun()->GetBulletNum(); j++)
			{
				if (player_->GetGun()->GetBullet()[j]->GetIsLive())
				{
					if (IsHit(player_->GetGun()->GetBullet()[j]->GetPos(),
						enemymanager_->GetEnemy()[i]->GetPos(),
						player_->GetGun()->GetBullet()[j]->GetRadius(),
						enemymanager_->GetEnemy()[i]->GetRadius()))
					{
						player_->GetGun()->GetBullet()[j]->SetIsLive(false);
						enemymanager_->GetEnemy()[i]->SetIsLive(false);
						enemymanager_->EnemyKillAdd();
					}
				}
			}
		}
	}
}

void Collition::HitEnemyBullet()
{
	for (int i = 0; i < enemymanager_->GetEnemyNum(); i++)
	{
		for (int j = 0; j < enemymanager_->GetEnemy()[i]->GetEnemyGun()->GetBulletNum(); j++)
		{
			if (enemymanager_->GetEnemy()[i]->GetEnemyGun()->GetBullet()[j]->GetIsLive())
			{
				if (IsHit(player_->GetPos(),
					enemymanager_->GetEnemy()[i]->GetEnemyGun()->GetBullet()[j]->GetPos(),
					player_->GetRadius(),
					enemymanager_->GetEnemy()[i]->GetEnemyGun()->GetBullet()[j]->GetRadius()))
				{
					player_->HpDec();
					enemymanager_->GetEnemy()[i]->GetEnemyGun()->GetBullet()[j]->SetIsLive(false);
				}
			}
		}
	}
}

bool Collition::IsHit(const Vector2& one, const Vector2& two, const float& radius1, const float& radius2)
{
	return IsCircleHit(one, two, radius1, radius2);
}
