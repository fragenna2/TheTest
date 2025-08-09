#pragma once
#include "entity.h"

class Enemy : public Entity
{
public:
	Enemy(Vector2f p_pos, SDL_Texture* p_tex, SDL_Renderer* renderer, Camera& camera);			// Default constructor
	void update(float delta_time, Vector2f& player_pos);										// Update the Enemy position

	Vector2f view_direction = { 1.f,0.f };														// Direction of the texture

};
