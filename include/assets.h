#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "platform.h"
#include "main.h"
#include <iostream>

extern SDL_Texture* player;

void loadAssets(SDL_Renderer* renderer);
SDL_Texture* loadTexture(SDL_Renderer* renderer,const char* file_path);