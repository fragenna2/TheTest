#include "enemy.h"

Enemy::Enemy(Vector2f p_pos, SDL_Texture* p_tex, SDL_Renderer* renderer, Camera& camera)
	: Entity(p_pos, p_tex, renderer, camera)
{}

void Enemy::update(float delta_time, Vector2f& player_pos)
{
	Vector2f directionToPlayer = player_pos - get_pos();

	if (directionToPlayer.length() == 0)
	{
		directionToPlayer.m_X = 1;
		directionToPlayer.m_Y = 0;
	}
	else
	{
		directionToPlayer = directionToPlayer.normalize();
	}

	Vector2f newDirection = directionToPlayer + view_direction;
	if (newDirection.length() == 0)
	{
		newDirection = Vector2f(directionToPlayer.m_Y, -directionToPlayer.m_X);
	}

	view_direction = newDirection.normalize();
	get_pos() += view_direction * delta_time * ENEMY_SPEED;
}