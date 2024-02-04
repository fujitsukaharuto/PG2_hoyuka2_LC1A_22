#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <assert.h>

#include "Vector2Matrix.h"


/// <summary>
/// 2次元ベクトルのスカラー倍を求める
/// </summary>
Vector2 Multiply(const Vector2& vec, const float& num);

/// <summary>
/// アフィン行列
/// </summary>
Matrix3x3 MakeAffineMat(Vector2 scale, float rotate, Vector2 translate);

/// <summary>
/// 3x3行列の積
/// </summary>
Matrix3x3 Multiply(Matrix3x3 matrix1, Matrix3x3 matrix2);

/// <summary>
/// ベクトルと2x2行列の積
/// </summary>
Vector2 Multiply(Vector2 vector, Matrix2x2 matrix);

/// <summary>
/// 2x2行列の逆行列
/// </summary>
Matrix2x2 Inverse(Matrix2x2 matrix);

/// <summary>
/// 3x3行列の逆行列
/// </summary>
Matrix3x3 Inverse(Matrix3x3 matrix);

/// <summary>
/// 正射影行列
/// </summary>
Matrix3x3 MakeOrthographicMat(float left, float top, float right, float bottom);

/// <summary>
/// ビューポート行列
/// </summary>
Matrix3x3 MakeViewportMat(float left, float top, float width, float hight);

/// <summary>
/// レンダリング
/// </summary>
Matrix3x3 MakeWvpVpMat(const Matrix3x3& world, const Matrix3x3& view, const Matrix3x3& ortho, const Matrix3x3& viewPort);

/// <summary>
/// ワールド座標に変える
/// </summary>
Vector2 Transform(const Vector2& vector, const Matrix3x3& matrix);

