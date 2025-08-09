#pragma once

#include "player.h"
#include "camera.h"
#include "enemy.h"
#include "assets.h"
#include "constants.h"
#include <SDL2/SDL.h>

#include <vector>

/*
* GameState class
*/
enum class GameState
{
	MAIN_MENU,
	PLAYING,
	ABOUT
};

class GameManager
{
public:
	GameManager();								// Default constructor
	~GameManager();								// Default deconstructor

	void game_logic(float delta_time);			// Method that handle the entire game
	void init(SDL_Renderer* renderer);			// Method to initialize the game

	Player* get_player();						// Getter for the player object

private:
	SDL_Renderer* m_Renderer;					// Copy of the renderer

	Player* m_Player;							// Player class field
	Camera m_Camera;							// Camera class field

	std::vector<Enemy> enemies;					// List of enemies

	int player_w;								// Data about dimensions of the player textures
	int player_h;
};