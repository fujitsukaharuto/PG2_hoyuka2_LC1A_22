#pragma once
#include "Base_Entity.h"
#include "Gun.h"

class Player
	:public Base_Entity {
public:
	Player();
	~Player();

	void Init();
	void Update(char* key);
	void Draw();

	void Move(char* keys);
	void Moving();

	void Shot(char* key);
	void HpDec();

	void MakeWorMat();
	void MakeScrMat(const Matrix3x3& view, const Matrix3x3& ortho, const Matrix3x3& viewPort);

	void Restart();

	Vector2 GetPos();
	float GetRadius();
	int GetHP();
	Gun* GetGun();

private:
	Vector2 moveDir_;
	bool isMove_;

	Gun* gun;
	int HPGH_;
};
