#pragma once
#include <SDL2/SDL.h>
#include "lib_selector.h"
#include "game_math.h"
#include "constants.h"
#include "camera.h"

class Entity
{
public:
    Entity(Vector2f p_pos, SDL_Texture* p_tex, SDL_Renderer* renderer, Camera& camera);

    Vector2f& getPos();

    SDL_Texture* getTexture();
    SDL_Rect getCurrentFrame();

    void updateRotation();
    void render(Camera& camera);

private:
    SDL_Renderer* m_Renderer;
    Vector2f m_Pos;
    SDL_Rect m_CurrentFrame;
    SDL_Texture* m_Texture;
    
    Camera& m_Camera;

    float m_Angle = 0.f;
};