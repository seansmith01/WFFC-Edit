#pragma once
#include "pch.h"
#include "InputCommands.h"


using namespace DirectX;
using namespace DirectX::SimpleMath;

class Camera
{
public:
	Camera(Vector3 _position, Vector3 _lookAt, int _width, int _height);
	~Camera();
	void Update(float _deltaTime);
	void HandleInput(InputCommands& _input, float _deltaTime);

	void CameraLook(InputCommands& _input, float _deltaTime);

	void CameraMove(InputCommands& _input, float _deltaTime);

	Vector3 GetPosition() { return cameraPosition; }
	Vector3 GetLookAt() { return cameraLookAt; }
	Matrix	GetView() { return view; }
	Matrix	GetProjection() { return projection; }

	void SetProjection(Matrix& _projection) { projection = _projection; };

private:
	int width;
	int height;

	float	rotationSpeed;
	float	rotationSensitivity;
	float	moveSpeed;

	Matrix	projection;
	Matrix	view;

	Vector2 previousMousePosition;

	Vector3	cameraPosition;
	Vector3	cameraLookAt;
	Vector3	cameraLookDirection;
	Vector3	cameraOrientation;
	Vector3	cameraRight;
	Vector3	up;
};

