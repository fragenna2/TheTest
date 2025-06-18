#pragma once
#include <SDL2/SDL.h>
#include "assets.h"
#include "entity.h"
#include "constants.h"
#include "game_math.h"
#include "player.h"

#include <string>
#include <vector>
#include <math.h>

class Platform
{
private:
    SDL_Window* m_Window;
    SDL_Renderer* m_Renderer;

    const char* m_GameName = "";
    int m_Width = 0;
    int m_Height = 0;

    bool isRunning = true;

public:
    Platform(const char* gameName, int width, int height);
    ~Platform();

    void initAndRun();

    void clean();
    void render(Entity& entity);
    void display();

    SDL_Window* getWindow();
    SDL_Renderer* getRenderer();
};