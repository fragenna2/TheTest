#pragma once
#include <SDL2/SDL.h>
#include "lib_selector.h"
#include "platform.h"
#include "main.h"
#include <iostream>

/*
	Texture of the player, the definition is in the assets.cpp file
*/
extern SDL_Texture* playerTexture;
extern SDL_Texture* enemyTexture;
extern SDL_Texture* backGroundTexture;

/*
	Load a texture based on the name of the file
*/
void loadAssets(SDL_Renderer* renderer);

/*
	The "RESOURCES_PATH" macro is defined in the CMake setup script
*/
SDL_Texture* loadTexture(SDL_Renderer* renderer,const char* file_path);