#include "EnemyManager.h"
#include <Novice.h>

EnemyManager::EnemyManager()
{
	Init();
}

EnemyManager::~EnemyManager()
{
	for (int i = 0; i < enemyNum_; i++)
	{
		delete enemy_[i];
	}
}


void EnemyManager::Init()
{
	enemyKillNum_ = 0;
	GH_ = Novice::LoadTexture("./Resource/enemy__.png");
	coolTime_ = 50;
	creatPos_ = { 1320,80 };
	for (int i = 0; i < enemyNum_; i++)
	{
		enemy_[i] = new Enemy();
		enemy_[i]->SetGH(GH_);
	}
}


void EnemyManager::Update()
{
	CreatEnemy();
	MoveCreatPos();
	for (int i = 0; i < enemyNum_; i++)
	{
		enemy_[i]->Update();
	}
}


void EnemyManager::Draw()
{
	for (int i = 0; i < enemyNum_; i++)
	{
		enemy_[i]->Draw();
	}
}


void EnemyManager::CreatEnemy()
{
	if (coolTime_<=0)
	{
		for (int i = 0; i < enemyNum_; i++)
		{
			if (!enemy_[i]->GetIsLive())
			{
				enemy_[i]->SetIsLive(true);
				enemy_[i]->SetPos(creatPos_);
				coolTime_ = 270;
				break;
			}
		}
	}
	else if (coolTime_>0)
	{
		coolTime_--;
	}
}


void EnemyManager::MoveCreatPos()
{
	creatPos_.y += 57;
	if (creatPos_.y>640)
	{
		creatPos_.y = 50;
	}
}

void EnemyManager::EnemyKillAdd()
{
	enemyKillNum_++;
}

void EnemyManager::Restart()
{
	enemyKillNum_ = 0;
	coolTime_ = 50;
	creatPos_ = { 1320,80 };
	for (int i = 0; i < enemyNum_; i++)
	{
		enemy_[i]->Restart();
	}
}


int EnemyManager::GetEnemyKillNum()
{
	return enemyKillNum_;
}

int EnemyManager::GetEnemyNum()
{
	return enemyNum_;
}
Enemy** EnemyManager::GetEnemy()
{
	return enemy_;
}
