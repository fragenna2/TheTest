#include "assets.h"
#include <iostream>

SDL_Texture* player_texture;
SDL_Texture* enemy_texture;
SDL_Texture* background_texture;

SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* file_path)
{
#ifndef PRODUCTION_BUILD
    std::cout << "Looking for file: " << file_path << std::endl;
#endif // !PRODUCTION_BUILD

    SDL_Texture* texture = IMG_LoadTexture(renderer , file_path);

    if (texture == NULL)
    {
        std::cout << "No file found!" << std::endl;
        return nullptr;
    }

    return texture;
}

void loadAssets(SDL_Renderer* renderer)
{
    player_texture = loadTexture(renderer, RESOURCES_PATH "entity.png");
    enemy_texture = loadTexture(renderer, RESOURCES_PATH "block.png");
    background_texture = loadTexture(renderer, RESOURCES_PATH "background.png");
}