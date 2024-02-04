#include <Novice.h>
#include "Game.h"

Game::Game()
{
	Init();
}

Game::~Game()
{
	delete camera_;
	delete player_;
	delete enemyManager_;
	delete collition_;
}

void Game::Init()
{
	camera_ = new Camera();
	player_ = new Player();
	enemyManager_ = new EnemyManager();
	collition_ = new Collition(player_, enemyManager_);
	GH = Novice::LoadTexture("./Resource/sea2.png");
	GH2= Novice::LoadTexture("./Resource/UI_EnemyKill.png");
	GH3= Novice::LoadTexture("./Resource/UI_Kill.png");
	GH4 = Novice::LoadTexture("./Resource/UI_number3.png");
}

void Game::Update(char* key)
{
	player_->Update(key);
	enemyManager_->Update();
	collition_->Update();

	ResultChange();

	player_->MakeScrMat(camera_->GetViewMat(), camera_->GetOrthoMat(), camera_->GetViewportMat());
	for (int i = 0; i < enemyManager_->GetEnemyNum(); i++)
	{
		enemyManager_->GetEnemy()[i]->MakeScrMat(camera_->GetViewMat(), camera_->GetOrthoMat(), camera_->GetViewportMat());

		for (int j = 0; j < enemyManager_->GetEnemy()[i]->GetEnemyGun()->GetBulletNum(); j++)
		{
			enemyManager_->GetEnemy()[i]->GetEnemyGun()->GetBullet()[j]->MakeScrMat(camera_->GetViewMat(), camera_->GetOrthoMat(), camera_->GetViewportMat());
		}
	}
	for (int i = 0; i < player_->GetGun()->GetBulletNum(); i++)
	{
		player_->GetGun()->GetBullet()[i]->MakeScrMat(camera_->GetViewMat(), camera_->GetOrthoMat(), camera_->GetViewportMat());
	}
}

void Game::Draw()
{
	Novice::DrawQuad(0, 0, 1280, 0, 0, 720, 1280, 720, 0, 0, 1280, 720, GH, WHITE);
	player_->Draw();
	enemyManager_->Draw();
	if (enemyManager_->GetEnemyKillNum() == 0)
	{
		Novice::DrawSprite(556, 250, GH3, 1, 1, 0.0f, WHITE);
	}
	else
	{
		Novice::DrawSprite(1062, 662, GH2, 1, 1, 0.0f, WHITE);
		if (enemyManager_->GetEnemyKillNum() != 10)
		{
			Novice::DrawSpriteRect(1146, 660, 288 - (32 * enemyManager_->GetEnemyKillNum()), 0, 32, 46, GH4, 0.1f, 1, 0.0f, WHITE);
		}
		else
		{
			Novice::DrawSpriteRect(1146, 660, 288, 0, 32, 46, GH4, 0.1f, 1, 0.0f, WHITE);
		}
	}
}

void Game::ResultChange()
{
	if (enemyManager_->GetEnemyKillNum() >= 10)
	{
		isClear_ = true;
		isResultChange_ = true;
	}
	if (player_->GetHP() <= 0)
	{
		isClear_ = false;
		isResultChange_ = true;
	}
}

void Game::Restart()
{
	player_->Restart();
	enemyManager_->Restart();
}

bool Game::GetIsResultChange()
{
	return isResultChange_;
}

bool Game::GetIsClear()
{
	return isClear_;
}
