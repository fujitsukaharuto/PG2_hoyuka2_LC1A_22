#pragma once
#include "Vector2Matrix.h"

class Base_Entity
{
protected:
	Vector2 worPos_;
	Vector2 scrPos_;

	Quad ver_;
	Quad worVer_;
	Quad scrVer_;

	Matrix3x3 worMat_;
	Matrix3x3 scrMat_;

	float speed_;
	Vector2 scale_;
	float rotate_;
	float radius_;
	int hp_;
	bool isLive_;
	int GH_;

public:
	Base_Entity() = default;
	~Base_Entity() = default;

};