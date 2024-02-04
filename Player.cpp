#include "Player.h"
#include <Novice.h>

#include "MatrixCalculation.h"
#include "MathCalculation.h"

Player::Player()
{
	Init();
}

Player::~Player()
{
	delete gun;
}


void Player::Init()
{
	worPos_ = { 100,360 };
	scrPos_ = { 0,0 };

	ver_.lt = { -30,30 };
	ver_.rt = { 30,30 };
	ver_.lb = { -30,-30 };
	ver_.rb = { 30,-30 };
	worVer_ = ver_;
	scrVer_ = ver_;

	speed_ = 6;
	scale_ = { 1,1 };
	rotate_ = 0.0f;
	radius_ = 30;
	hp_ = 4;

	isLive_ = true;
	GH_ = Novice::LoadTexture("./Resource/sakana__.png");

	moveDir_ = { 0,0 };
	isMove_ = false;

	gun = new Gun();

	MakeWorMat();
	scrMat_ = worMat_;
	HPGH_ = Novice::LoadTexture("./Resource/sea_HP.png");
}


void Player::Update(char* key)
{
	Move(key);
	Moving();

	Shot(key);
	gun->Update();


	MakeWorMat();
}


void Player::Draw()
{
	gun->Draw();
	Novice::DrawQuad(int(scrVer_.lt.x), int(scrVer_.lt.y),
		int(scrVer_.rt.x), int(scrVer_.rt.y),
		int(scrVer_.lb.x), int(scrVer_.lb.y),
		int(scrVer_.rb.x), int(scrVer_.rb.y), 0, 0, 64, 64, GH_, WHITE);
	for (int i = 0; i < hp_; i++)
	{
		Novice::DrawSprite(20 + (45 * i), 30, HPGH_, 1, 1, 0.0f, WHITE);
	}
}


void Player::Move(char* key)
{
	isMove_ = false;
	moveDir_ = { 0,0 };
	if (key[DIK_A])
	{
		isMove_ = true;
		moveDir_.x = -speed_;
	}
	if (key[DIK_D])
	{
		isMove_ = true;
		moveDir_.x = speed_;
	}
	if (key[DIK_W])
	{
		isMove_ = true;
		moveDir_.y = speed_;
	}
	if (key[DIK_S])
	{
		isMove_ = true;
		moveDir_.y = -speed_;
	}

	if (isMove_)
	{
		Normalize(moveDir_);
		moveDir_.x *= speed_;
		moveDir_.y *= speed_;
	}
}


void Player::Moving()
{
	if (isMove_)
	{
		worPos_.x += moveDir_.x;
		worPos_.y += moveDir_.y;
	}
}


void Player::Shot(char* key)
{
	if (key[DIK_SPACE])
	{
		gun->Shot(worPos_);
	}
}

void Player::HpDec()
{
	hp_--;
}


void Player::MakeWorMat()
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


void Player::MakeScrMat(const Matrix3x3& view, const Matrix3x3& ortho, const Matrix3x3& viewPort)
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

void Player::Restart()
{
	worPos_ = { 100,360 };
	scrPos_ = { 0,0 };

	ver_.lt = { -30,30 };
	ver_.rt = { 30,30 };
	ver_.lb = { -30,-30 };
	ver_.rb = { 30,-30 };
	worVer_ = ver_;
	scrVer_ = ver_;

	speed_ = 6;
	scale_ = { 1,1 };
	rotate_ = 0.0f;
	radius_ = 30;
	hp_ = 4;

	isLive_ = true;

	moveDir_ = { 0,0 };
	isMove_ = false;

	gun->Restart();

	MakeWorMat();
	scrMat_ = worMat_;
}


Vector2 Player::GetPos()
{
	return worPos_;
}

float Player::GetRadius()
{
	return radius_;
}

int Player::GetHP()
{
	return hp_;
}

Gun* Player::GetGun()
{
	return gun;
}
