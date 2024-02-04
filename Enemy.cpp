#include "Enemy.h"
#include <Novice.h>

#include "MatrixCalculation.h"

Enemy::Enemy()
{
	Init();
}

Enemy::~Enemy()
{
	delete enemyGun_;
}

void Enemy::Init()
{
	worPos_ = { 1320,360 };
	scrPos_ = { 0,0 };

	ver_.lt = { -20,20 };
	ver_.rt = { 20,20 };
	ver_.lb = { -20,-20 };
	ver_.rb = { 20,-20 };
	worVer_ = ver_;
	scrVer_ = ver_;

	speed_ = 1;
	scale_ = { 1,1 };
	rotate_ = 0.0f;
	radius_ = 20;
	hp_ = 4;

	amplitude = 60;
	theta = 0;

	isLive_ = false;

	enemyGun_ = new EnemyGun();

	MakeWorMat();
	scrMat_ = worMat_;
}


void Enemy::Update()
{
	if (isLive_)
	{
		Move();
		Shot();
	}

	enemyGun_->Update();
	MakeWorMat();
}


void Enemy::Draw()
{
	enemyGun_->Draw();
	if (isLive_)
	{
		Novice::DrawQuad(int(scrVer_.lt.x), int(scrVer_.lt.y),
			int(scrVer_.rt.x), int(scrVer_.rt.y),
			int(scrVer_.lb.x), int(scrVer_.lb.y),
			int(scrVer_.rb.x), int(scrVer_.rb.y), 0, 0, 64, 64, GH_, WHITE);
	}
}


void Enemy::Move()
{
	worPos_.x -= speed_;
	worPos_.y = originPosY_ + sinf(theta) * amplitude + 60;
	theta += float(M_PI) / 90.0f;
	if (worPos_.x<-30)
	{
		isLive_ = false;
	}
}


void Enemy::Moving()
{

}


void Enemy::Shot()
{
	enemyGun_->Shot(worPos_);
}


void Enemy::SetGH(const int& GH)
{
	GH_ = GH;
}
void Enemy::SetPos(const Vector2& pos)
{
	worPos_ = pos;
	originPosY_ = pos.y;
}
void Enemy::SetIsLive(const bool& ok)
{
	isLive_ = ok;
}


Vector2 Enemy::GetPos()
{
	return worPos_;
}
float Enemy::GetRadius()
{
	return radius_;
}
bool Enemy::GetIsLive()
{
	return isLive_;
}


void Enemy::MakeWorMat()
{
	if (!isLive_)
	{
		return;
	}
	worMat_ = MakeAffineMat(scale_, rotate_, worPos_);
	worVer_.lt = Transform(ver_.lt, worMat_);
	worVer_.rt = Transform(ver_.rt, worMat_);
	worVer_.lb = Transform(ver_.lb, worMat_);
	worVer_.rb = Transform(ver_.rb, worMat_);
}


void Enemy::MakeScrMat(const Matrix3x3& view, const Matrix3x3& ortho, const Matrix3x3& viewPort)
{
	if (!isLive_)
	{
		return;
	}
	MakeWorMat();
	scrMat_ = MakeWvpVpMat(worMat_, view, ortho, viewPort);
	scrVer_.lt = Transform(ver_.lt, scrMat_);
	scrVer_.rt = Transform(ver_.rt, scrMat_);
	scrVer_.lb = Transform(ver_.lb, scrMat_);
	scrVer_.rb = Transform(ver_.rb, scrMat_);
}

void Enemy::Restart()
{
	worPos_ = { 1320,360 };
	scrPos_ = { 0,0 };

	ver_.lt = { -20,20 };
	ver_.rt = { 20,20 };
	ver_.lb = { -20,-20 };
	ver_.rb = { 20,-20 };
	worVer_ = ver_;
	scrVer_ = ver_;

	speed_ = 1;
	scale_ = { 1,1 };
	rotate_ = 0.0f;
	radius_ = 20;
	hp_ = 4;

	amplitude = 60;
	theta = 0;

	isLive_ = false;

	enemyGun_->Restart();

	MakeWorMat();
	scrMat_ = worMat_;
}


EnemyGun* Enemy::GetEnemyGun()
{
	return enemyGun_;
}
