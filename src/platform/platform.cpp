#include "platform.h"

Uint32 last_tick = 0;
Uint32 current_tick = 0;
float delta_time;

int player_w;
int player_h;

Platform::Platform(const char* gameName, int width, int height)
 : m_GameName(gameName), m_Width(width), m_Height(height)
{
    init();
}

Platform::~Platform()
{}

void Platform::init()
{
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
    return;
}


void Platform::run()
{
    Camera camera;
    camera.set_size(static_cast<float>(WIDTH / SCALE_FACTOR), static_cast<float>(HEIGHT / SCALE_FACTOR));

    Player p(Vector2f(static_cast<float>(WIDTH /2), static_cast<float>(HEIGHT / 2)), player_texture, m_Renderer, camera);
    std::vector<Enemy>enemies = {Enemy(Vector2f(10, 10), enemy_texture, m_Renderer, camera)};

    player_w = p.get_current_frame().w;
    player_h = p.get_current_frame().h;

    while (is_running)
    {
        last_tick = current_tick;
        current_tick = SDL_GetTicks();
        delta_time = (current_tick - last_tick) / 1000.0f;

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                is_running = false;

            p.handle_events(event);
        }

        SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        clean();

        camera.follow(p.get_pos(), player_w, player_h);

        //Render and update the enemies
        for (auto& e : enemies)
        {
            e.render(camera);
        }

        for (auto& e : enemies)
        {
            e.update(delta_time, p.get_pos());
        }

        //Render the player
        p.update_rotation();
        p.render(camera);
        p.update(delta_time);

        //Update the window
        display();
    }
    
    //Close the game
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
    SDL_Quit();
}

SDL_Window* Platform::get_window()
{
    return m_Window;
}

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

void Platform::render(SDL_Texture* texture, Camera& camera)
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