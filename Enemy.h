#pragma once
#include "Base_Entity.h"
#include "EnemyGun.h"

class Enemy
	:public Base_Entity {
public:
	Enemy();
	~Enemy();

	void Init();
	void Update();
	void Draw();

	void Move();
	void Moving();

	void Shot();

	void SetGH(const int& GH);
	void SetPos(const Vector2& pos);
	void SetIsLive(const bool& ok);

	Vector2 GetPos();
	float GetRadius();
	bool GetIsLive();

	void MakeWorMat();
	void MakeScrMat(const Matrix3x3& view, const Matrix3x3& ortho, const Matrix3x3& viewPort);

	void Restart();

	EnemyGun* GetEnemyGun();

private:

	float originPosY_;
	float amplitude;
	float theta;

	EnemyGun* enemyGun_;

};
