#pragma once
#include "player.h"
#include "camera.h"
#include "enemy.h"
#include "assets.h"
#include "constants.h"
#include <SDL2/SDL.h>

#include <vector>

class Game
{
public:
	Game(SDL_Renderer* renderer);
	~Game();

	void game_logic(float delta_time);

	Player* get_player();

private:
	SDL_Renderer* m_Renderer;
	
	Player* m_Player;
	Camera m_Camera;

	std::vector<Enemy> enemies;

	int player_w;
	int player_h;
};