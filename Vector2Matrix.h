#pragma once

/// <summary>
/// 2次元ベクトル
/// </summary>
struct Vector2 final {
	float x;
	float y;
};

/// <summary>
/// 2x2Matrixベクトル
/// </summary>
struct Matrix2x2 final
{
	float m[2][2];
};

/// <summary>
/// 3x3Matrixベクトル
/// </summary>
struct Matrix3x3 final
{
	float m[3][3];
};

struct Quad final
{
	Vector2 lt;
	Vector2 rt;
	Vector2 lb;
	Vector2 rb;
};