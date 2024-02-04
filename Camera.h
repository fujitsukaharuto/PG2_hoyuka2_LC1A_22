#pragma once
#include "Vector2Matrix.h"
#include "MatrixCalculation.h"

class Camera
{
public:
	Camera();
	~Camera();

	void Init();

	Matrix3x3 GetViewMat() { return viewMat; }
	Matrix3x3 GetOrthoMat() { return orthoMat; }
	Matrix3x3 GetViewportMat() { return viewportMat; }

private:
	Matrix3x3 cameraMat;
	Matrix3x3 viewMat;
	Matrix3x3 orthoMat;
	Matrix3x3 viewportMat;
};
