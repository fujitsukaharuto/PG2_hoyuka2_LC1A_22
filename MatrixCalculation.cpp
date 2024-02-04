#include "MatrixCalculation.h"

Vector2 Multiply(const Vector2& vec, const float& num)
{
	return { vec.x * num,vec.y * num };
}

Matrix3x3 MakeAffineMat(Vector2 scale, float rotate, Vector2 translate) {
	Matrix3x3 result{};
	for (int y = 0; y < 2; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			result.m[y][x] = 0;
		}
	}

	result.m[0][0] = scale.x * cosf(rotate); result.m[0][1] = scale.x * sinf(rotate);
	result.m[1][0] = scale.y * -sinf(rotate); result.m[1][1] = scale.y * cosf(rotate);
	result.m[2][0] = translate.x; result.m[2][1] = translate.y; result.m[2][2] = 1;

	return result;
}

Matrix3x3 Multiply(Matrix3x3 matrix1, Matrix3x3 matrix2) {
	Matrix3x3 result{};

	for (int row = 0; row < 3; row++) {
		for (int column = 0; column < 3; column++) {
			for (int i = 0; i < 3; i++) {
				result.m[row][column] += matrix1.m[row][i] * matrix2.m[i][column];
			}
		}
	}

	return result;
}

Vector2 Multiply(Vector2 vector, Matrix2x2 matrix) {
	Vector2 result{};

	result.x = vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0];
	result.y = vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1];

	return result;
}

Matrix2x2 Inverse(Matrix2x2 matrix)
{
	Matrix2x2 result{};
	Matrix2x2 m{};
	m.m[0][0] = matrix.m[1][1]; m.m[0][1] = -(matrix.m[0][1]);
	m.m[1][0] = -(matrix.m[1][0]); m.m[1][1] = matrix.m[0][0];

	float number;
	number = (matrix.m[0][0] * matrix.m[1][1] - matrix.m[0][1] * matrix.m[1][0]);
	if (number != 0)
	{
		number = 1.0f / number;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				result.m[j][i] = number * m.m[j][i];
			}
		}
	}

	return result;
}

Matrix3x3 Inverse(Matrix3x3 matrix)
{
	Matrix3x3 m{};
	m.m[0][0] = matrix.m[1][1] * matrix.m[2][2] - matrix.m[1][2] * matrix.m[2][1];
	m.m[0][1] = -(matrix.m[0][1] * matrix.m[2][2] - matrix.m[0][2] * matrix.m[2][1]);
	m.m[0][2] = matrix.m[0][1] * matrix.m[1][2] - matrix.m[0][2] * matrix.m[1][1];

	m.m[1][0] = -(matrix.m[1][0] * matrix.m[2][2] - matrix.m[1][2] * matrix.m[2][0]);
	m.m[1][1] = matrix.m[0][0] * matrix.m[2][2] - matrix.m[0][2] * matrix.m[2][0];
	m.m[1][2] = -(matrix.m[0][0] * matrix.m[1][2] - matrix.m[0][2] * matrix.m[1][0]);

	m.m[2][0] = matrix.m[1][0] * matrix.m[2][1] - matrix.m[1][1] * matrix.m[2][0];
	m.m[2][1] = -(matrix.m[0][0] * matrix.m[2][1] - matrix.m[0][1] * matrix.m[2][0]);
	m.m[2][2] = matrix.m[0][0] * matrix.m[1][1] - matrix.m[0][1] * matrix.m[1][0];

	float number;
	number = matrix.m[0][0] * matrix.m[1][1] * matrix.m[2][2] + matrix.m[0][1] * matrix.m[1][2] * matrix.m[2][0] + matrix.m[0][2] * matrix.m[1][0] * matrix.m[2][1] - (matrix.m[0][2] * matrix.m[1][1] * matrix.m[2][0]) - (matrix.m[0][1] * matrix.m[1][0] * matrix.m[2][2]) - (matrix.m[0][0] * matrix.m[1][2] * matrix.m[2][1]);
	number = 1.0f / number;

	Matrix3x3 result{};

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			result.m[j][i] = number * m.m[j][i];
		}
	}

	return result;
}

Matrix3x3 MakeOrthographicMat(float left, float top, float right, float bottom) {
	Matrix3x3 result{};

	result.m[0][0] = 2.0f / (right - left);
	result.m[1][1] = 2.0f / (top - bottom);
	result.m[2][0] = (left + right) / (left - right);
	result.m[2][1] = (top + bottom) / (bottom - top);
	result.m[2][2] = 1.0f;

	return result;
}

Matrix3x3 MakeViewportMat(float left, float top, float width, float hight) {

	Matrix3x3 result{};

	result.m[0][0] = width / 2;
	result.m[1][1] = -(hight / 2);
	result.m[2][0] = left + width / 2;
	result.m[2][1] = top + hight / 2;
	result.m[2][2] = 1;

	return result;

}

Matrix3x3 MakeWvpVpMat(const Matrix3x3& world, const Matrix3x3& view, const Matrix3x3& ortho, const Matrix3x3& viewPort) {
	Matrix3x3 result{};

	result = Multiply(world, view);
	result = Multiply(result, ortho);
	result = Multiply(result, viewPort);

	return result;
}

Vector2 Transform(const Vector2& vector, const Matrix3x3& matrix) {

	Vector2 result{};
	result.x = vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0] + matrix.m[2][0];
	result.y = vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1] + matrix.m[2][1];
	float w = vector.x * matrix.m[0][2] + vector.y * matrix.m[1][2] + matrix.m[2][2];
	assert(w != 0.0f);
	result.x /= w;
	result.y /= w;

	return result;
}

