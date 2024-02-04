#include "Bullet.h"
#include <Novice.h>

#include "MatrixCalculation.h"

Bullet::Bullet()
{
	Init();
}

void Bullet::Init()
{
	pos_ = { 0,0 };
	speed_ = 8;
	radius_ = 10;

	ver_.lt = { -10,10 };
	ver_.rt = { 10,10 };
	ver_.lb = { -10,-10 };
	ver_.rb = { 10,-10 };
	worVer_ = ver_;
	scrVer_ = ver_;

	scale_ = { 1,1 };
	rotate_ = 0;

	MakeWorMat();
	scrMat_ = worMat_;

	isLive_ = false;
	isEnemyMode_ = false;
}


void Bullet::Update()
{
	if (isLive_)
	{
		if (!isEnemyMode_)
		{
			Move();
		}
		if (isEnemyMode_)
		{
			EneMove();
		}
		MakeWorMat();
	}
}


void Bullet::Draw(const int& GH)
{
	if (isLive_)
	{
		Novice::DrawQuad(int(scrVer_.lt.x), int(scrVer_.lt.y),
			int(scrVer_.rt.x), int(scrVer_.rt.y),
			int(scrVer_.lb.x), int(scrVer_.lb.y),
			int(scrVer_.rb.x), int(scrVer_.rb.y), 0, 0, 32, 32, GH, WHITE);
	}
}


void Bullet::Move()
{
	pos_.x += speed_;
	if (pos_.x > 1300 || pos_.x < -30 || pos_.y>750 || pos_.y < -30)
	{
		isLive_ = false;
	}
}


void Bullet::EneMove()
{
	pos_.x -= speed_;
	if (pos_.x > 1300 || pos_.x < -30 || pos_.y>750 || pos_.y < -30)
	{
		isLive_ = false;
	}
}


void Bullet::SetPos(const Vector2& pos)
{
	pos_ = pos;
}
void Bullet::SetIsLive(const bool& live)
{
	isLive_ = live;
}
void Bullet::SetSpeed(const float& speed)
{
	speed_ = speed;
}
void Bullet::SetRadius(const float& radius)
{
	radius_ = radius;
}
void Bullet::SetEnemyMode(const bool& ok)
{
	isEnemyMode_ = ok;
}


Vector2 Bullet::GetPos()
{
	return pos_;
}
float Bullet::GetRadius()
{
	return radius_;
}
bool Bullet::GetIsLive()
{
	return isLive_;
}

void Bullet::Restart()
{
	pos_ = { 0,0 };
	speed_ = 8;
	radius_ = 10;

	ver_.lt = { -10,10 };
	ver_.rt = { 10,10 };
	ver_.lb = { -10,-10 };
	ver_.rb = { 10,-10 };
	worVer_ = ver_;
	scrVer_ = ver_;

	scale_ = { 1,1 };
	rotate_ = 0;

	MakeWorMat();
	scrMat_ = worMat_;

	isLive_ = false;
	isEnemyMode_ = false;
}


void Bullet::MakeWorMat()
{
	if (!isLive_)
	{
		return;
	}
	worMat_ = MakeAffineMat(scale_, rotate_, pos_);
	worVer_.lt = Transform(ver_.lt, worMat_);
	worVer_.rt = Transform(ver_.rt, worMat_);
	worVer_.lb = Transform(ver_.lb, worMat_);
	worVer_.rb = Transform(ver_.rb, worMat_);
}


void Bullet::MakeScrMat(const Matrix3x3& view, const Matrix3x3& ortho, const Matrix3x3& viewPort)
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


