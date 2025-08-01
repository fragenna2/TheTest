#pragma once
#include <SDL2/SDL.h>

#include "assets.h"
#include "entity.h"
#include "constants.h"
#include "game_math.h"
#include "player.h"
#include "enemy.h"
#include "camera.h"
#include "game.h"

#include <string>
#include <vector>
#include <assert.h>

// Forward declaration ot the Game class coming from the "game.h"
class Game;

// This class use Singletone pattern in order to access the renderer and the window, that are required in lots of files
class Platform
{
public:

    Platform(const Platform&) = delete;
    Platform& operator=(const Platform&) = delete;

    static Platform& get_instance()
    {
        assert(instance != nullptr && "Platform must be initialized with init_instance() before use.");
        return *instance;
    }

    static void init_instance(const char* game_name, int width, int height)
    {
        if (instance == nullptr)
            instance = new Platform(game_name, width, height);
    }

    static void destroy_instance()
    {
        delete instance;
        instance = nullptr;
    }

    void run(Game& game);                   //Inside this method the game will run
    void clean();                           //Clear the screen before redraw the objects

    void render(SDL_Texture* texture);      //Render a texture onto the screen

    void display();                         //Show the result to the screen

    SDL_Window* get_window();                //Getter for window
    SDL_Renderer* get_renderer();            //Getter for the renderer

    bool is_running();

private:
    Platform(const char* game_name, int width, int height);
    ~Platform();

    void init();                            //This method will setup the window and the renderer

private:
    static Platform* instance;

    SDL_Window* m_Window = nullptr;         //The pointer to the window object
    SDL_Renderer* m_Renderer = nullptr;     //The pointer to the renderer object

    const char* m_GameName = "";            //Window name 
    int m_Width = 0;                        //Size of the window
    int m_Height = 0;                       //Size of the window

    bool m_Running = true;                  //Variable to check if the game is running
};