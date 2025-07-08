#include "camera.h"

Camera::Camera()
{ }

Camera::~Camera()
{ }

void Camera::follow(const Vector2f& target, int playerW, int playerH) {
	m_Pos.m_X = target.m_X + (playerW * 0.5f) - m_Size.m_X * 0.5f;
	m_Pos.m_Y = target.m_Y + (playerH * 0.5f) - m_Size.m_Y * 0.5f;
}

Vector2f Camera::world_to_screen(const Vector2f& worldPos) const
{
	return worldPos - m_Pos;
}

void Camera::set_size(float x, float y)
{
	m_Size.m_X = x;
	m_Size.m_Y = y;
}

Vector2f Camera::get_size() const
{
	return m_Size;
}

Vector2f& Camera::get_pos()
{
	return m_Pos;
}