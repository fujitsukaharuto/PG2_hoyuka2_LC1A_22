#pragma once
#include "Vector2Matrix.h"

class Bullet
{
public:
	Bullet();
	~Bullet() = default;

	void Init();
	void Update();
	void Draw(const int& GH);

	void Move();
	void EneMove();

	void SetPos(const Vector2& pos);
	void SetIsLive(const bool& live);
	void SetSpeed(const float& speed);
	void SetRadius(const float& radius);
	void SetEnemyMode(const bool& ok);

	Vector2 GetPos();
	float GetRadius();
	bool GetIsLive();

	void Restart();

	void MakeWorMat();
	void MakeScrMat(const Matrix3x3& view, const Matrix3x3& ortho, const Matrix3x3& viewPort);

private:

	Vector2 pos_;
	float speed_;
	float radius_;

	Matrix3x3 worMat_;
	Matrix3x3 scrMat_;

	Quad ver_;
	Quad worVer_;
	Quad scrVer_;

	Vector2 scale_;
	float rotate_;

	bool isLive_;
	bool isEnemyMode_;
	//何種類か弾撃ちたいならspeedやradiusセットできるように
};
