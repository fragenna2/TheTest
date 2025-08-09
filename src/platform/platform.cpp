#include "platform.h"

// set this instance variable to NULL
Platform* Platform::instance = nullptr;

// variable for timings
Uint32 last_tick{ 0 };
Uint32 current_tick{ 0 };
float delta_time;

Platform::Platform(const char* game_name, int width, int height)
 : m_GameName(game_name), m_Width(width), m_Height(height)
{
    init();
}

Platform::~Platform()
{}

void Platform::init()
{
    // Init vide
    SDL_Init(SDL_INIT_VIDEO);

    m_Window = SDL_CreateWindow("The test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_Width, m_Height, SDL_WINDOW_MAXIMIZED);
    if (!m_Window)
    {
        SDL_Log("Error while creating the window: %s", SDL_GetError());
        exit(1);
    }
    SDL_assert(m_Window != NULL);

    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_SOFTWARE);
    if (!m_Renderer)
    {
        SDL_Log("Error while creting the renderer: %s", SDL_GetError());
        exit(1);
    }
    SDL_assert(m_Renderer != NULL);

    //This method will load all the assets that the game require
    loadAssets(m_Renderer);

    // Initialize the game and run
    game.init(m_Renderer);
    run();
}

void Platform::run()
{
    //Game loop
    while (is_running())
    {
        //Managing the timing of refresh
        last_tick = current_tick;
        current_tick = SDL_GetTicks();
        delta_time = (current_tick - last_tick) / 1000.0f;

        //Handling events
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                m_Running = false;

            game.get_player()->handle_events(event);
        }

        SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        clean();

        //This method containg all the logic of the game
        game.game_logic(delta_time);

        //Update the window
        display();
    }
    
    //Free the memory from the assets
    free_memory_assets();

    //Close the game
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
    SDL_Quit();
}

// Getter for window
SDL_Window* Platform::get_window()
{
    return m_Window;
}

// Getter for renderer
SDL_Renderer* Platform::get_renderer()
{
    return m_Renderer;
}

void Platform::clean()
{
    SDL_RenderClear(m_Renderer);
}

void Platform::display()
{
    SDL_RenderPresent(m_Renderer);
}

void Platform::render(SDL_Texture* texture)
{
    if (texture == nullptr)
    {
        SDL_Log("Error while rendering a texture, the texture is null!");
        return;
    }

    int tex_w, tex_h;
    SDL_QueryTexture(texture, NULL, NULL, &tex_w, &tex_h);

    SDL_Rect src_rect;
    src_rect.x = static_cast<int>(WIDTH / 2);
    src_rect.y = static_cast<int>(HEIGHT / 2);
    src_rect.w = tex_w;
    src_rect.h = tex_h;

    SDL_Rect dstRect;
    dstRect.x = 0;
    dstRect.y = 0;
    dstRect.w = tex_w;
    dstRect.h = tex_h;

    SDL_RenderCopy(m_Renderer, texture, &src_rect, &dstRect);
}

bool Platform::is_running()
{
    return m_Running;
}