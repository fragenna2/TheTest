#pragma once
#include <SDL2/SDL.h>

#include "assets.h"
#include "entity.h"
#include "constants.h"
#include "game_math.h"
#include "player.h"
#include "enemy.h"
#include "camera.h"

#include <string>
#include <vector>
#include <assert.h>

class Platform
{
public:
    Platform(const char* gameName, int width, int height);
    ~Platform();

    void run();                             //Inside this method the game will run
    void clean();                           //Clear the screen before redraw the objects

    void render(SDL_Texture* texture, Camera& camera);

    void display();                         //Show the result to the screen

    SDL_Window* getWindow();                //Getters for window and renderer
    SDL_Renderer* getRenderer();
private:
    void init();                            //This method will setup the window and the renderer

private:
    SDL_Window* m_Window = nullptr;         //The pointer to the window object
    SDL_Renderer* m_Renderer = nullptr;     //The pointer to the renderer object

    const char* m_GameName = "";            //Window name 
    int m_Width = 0;                        //Size of the window
    int m_Height = 0;                       //Size of the window

    bool isRunning = true;                  //Variable to check if the game is running

};