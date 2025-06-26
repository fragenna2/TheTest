#pragma once
#include "entity.h"

class Enemy : public Entity
{
public:
	Enemy(Vector2f p_pos, SDL_Texture* p_tex, SDL_Renderer* renderer, Camera& camera);
	void update(float delta_time, Vector2f& player_pos);

	Vector2f viewDirection = { 1.f,0.f };

};
