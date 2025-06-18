#include "assets.h"

SDL_Texture* player;

SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* file_path)
{

    SDL_Texture* texture = IMG_LoadTexture(renderer , file_path);
    if (texture == NULL)
    {
        std::cout << "No file found!" << std::endl;
    }

    return texture;
}

void loadAssets(SDL_Renderer* renderer)
{
    player = loadTexture(renderer, RESOURCES_PATH "entity.png");
}