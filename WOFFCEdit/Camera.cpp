#include "Camera.h"

Camera::Camera(Vector3 _position, Vector3 _lookAt, int _width, int _height)
{
	cameraPosition = _position;
	cameraLookAt = _lookAt;
	width = _width;
	height = _height;

	previousMousePosition = Vector2::Zero;
	previousMousePosition = Vector2::Zero;
	cameraLookAt = _lookAt;
	cameraRight = Vector3::Right;
	up = Vector3::Up;

	rotationSensitivity = 1;
	rotationSpeed = 40;
	moveSpeed = 10;



}
Camera::~Camera()
{

}
void Camera::HandleInput(InputCommands& _input, float _deltaTime)
{

	CameraMove(_input, _deltaTime);

	

	CameraLook(_input, _deltaTime);
}
void Camera::CameraLook(InputCommands& _input, float _deltaTime)
{
	Vector2 currentMousePosition = Vector2(_input.mousePosX, _input.mousePosY);
	// If not holding right mouse button, return but keep setting previous mouse pos to current mouse pos so it doesn't jitter everytime you press right click
	if (!_input.mouseRightDown) {
		previousMousePosition = currentMousePosition;
		return;
	}
		

	Vector2 mouseDelta = currentMousePosition - previousMousePosition;
	previousMousePosition = currentMousePosition;


	cameraOrientation.y += mouseDelta.x * -rotationSpeed * _deltaTime;
	cameraOrientation.x -= mouseDelta.y * -rotationSpeed * _deltaTime;

	//cameraOrientation.x = std::min(std::max(m_orientation.x, -89.f), 89.f);
}
void Camera::CameraMove(InputCommands& _input, float _deltaTime)
{
	Vector3 moveDirection = Vector3::Zero;

	Vector3 planarMoveDir = cameraLookDirection;
	planarMoveDir.y = 0;
	planarMoveDir.Normalize();

	if (_input.forward)
	{
		moveDirection += planarMoveDir;
	}
	if (_input.back)
	{
		moveDirection -= planarMoveDir;
	}
	if (_input.right)
	{
		moveDirection += cameraRight;
	}
	if (_input.left)
	{
		moveDirection -= cameraRight;
	}
	if (_input.up)
	{
		moveDirection += Vector3::Up;
	}
	if (_input.down)
	{
		moveDirection -= Vector3::Up;
	}

	moveDirection.Normalize();
	cameraPosition += (moveDirection * moveSpeed * _deltaTime);
}
void Camera::Update(float _deltaTime)
{
	//create look direction from Euler angles in m_camOrientation
	cameraLookDirection.x = sin((cameraOrientation.y) * 3.1415 / 180);
	cameraLookDirection.z = cos((cameraOrientation.y) * 3.1415 / 180);
	cameraLookDirection.Normalize();

	//create right vector from look Direction
	cameraLookDirection.Cross(Vector3::UnitY, cameraRight);

	//update lookat point
	cameraLookAt = cameraPosition + cameraLookDirection;

	//apply camera vectors
	view = Matrix::CreateLookAt(cameraPosition, cameraLookAt, Vector3::UnitY);


}


