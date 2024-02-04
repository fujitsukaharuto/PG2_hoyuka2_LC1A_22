#include "Camera.h"

Camera::Camera()
{
	Init();
}

Camera::~Camera()
{
}

void Camera::Init()
{
	cameraMat = MakeAffineMat(Vector2{ 1.0f,1.0f }, 0.0f, Vector2{ 640.0f,360.0f });
	viewMat = Inverse(cameraMat);
	orthoMat = MakeOrthographicMat(-640.0f, 360.0f, 640.0f, -360.0f);
	viewportMat = MakeViewportMat(0, 0, 1280.0f, 720.0f);
}