#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "game_math.h"
#include "constants.h"

class Entity
{
public:
    Entity(Vector2f p_pos, SDL_Texture* p_tex, SDL_Renderer* renderer);

    Vector2f& getPos();

    SDL_Texture* getTexture();
    SDL_Rect getCurrentFrame();

    void updateRotation();
    void render();

private:
    SDL_Renderer* m_Renderer;
    Vector2f m_Pos;
    SDL_Rect m_CurrentFrame;
    SDL_Texture* m_Texture;

    float m_Angle = 0.f;
};