#include "assets.h"
#include <iostream>

SDL_Texture* playerTexture;
SDL_Texture* enemyTexture;
SDL_Texture* backGroundTexture;

SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* file_path)
{
    std::cout << "Looking for file: " << file_path << std::endl;
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
    playerTexture = loadTexture(renderer, RESOURCES_PATH "entity.png");
    enemyTexture = loadTexture(renderer, RESOURCES_PATH "block.png");
    backGroundTexture = loadTexture(renderer, RESOURCES_PATH "background.png");
}