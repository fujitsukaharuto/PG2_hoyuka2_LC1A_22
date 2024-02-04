#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <assert.h>

#include "Vector2Matrix.h"

/// <summary>
/// 2次元ベクトルの2点の距離
/// </summary>
Vector2 LengthDis(const Vector2& endVec, const Vector2& startVec);

/// <summary>
/// 2次元ベクトルの2点の距離(当たり判定用)
/// </summary>
float Length(const Vector2& one, const Vector2& two);

/// <summary>
/// 正規化
/// </summary>
void Normalize(Vector2& vec);

/// <summary>
/// 円との当たり判定
/// </summary>
bool IsCircleHit(const Vector2& one, const Vector2& two,const float& radius1, const float& radius2);

/// <summary>
/// 線形補間(float)
/// </summary>
float Lerp(float start, float end, float t);

/// <summary>
/// 線形補間(Vector2)
/// </summary>
Vector2 Lerp(Vector2 start, Vector2 end, float t);

/// <summary>
/// Quadの４頂点求める
/// </summary>
Quad QuadPos(const Vector2& pos, const float& radius);