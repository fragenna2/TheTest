#pragma once
#include "game_math.h"
#include "constants.h"

class Camera
{
public:
	Camera();
	~Camera();

	void follow(const Vector2f& target, int playerW, int playerH);
	Vector2f worldToScreen(const Vector2f& worldPos) const;

	Vector2f getSize() const;
	void setSize(float x, float y);

	Vector2f& getPos();

private:
	Vector2f m_Pos = { 0, 0};
	Vector2f m_Size;
	Vector2f m_Viewport;


};
