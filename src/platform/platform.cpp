#include "platform.h"

Uint32 lastTick = 0;
Uint32 current_tick = 0;
float delta_time;

int playerW;
int playerH;

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
    }
    SDL_assert_release(m_Window != NULL);

    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_SOFTWARE);
    if (!m_Renderer)
    {
        SDL_Log("Error while creting the renderer: %s", SDL_GetError());
    }
    SDL_assert_release(m_Renderer != NULL);

    //This method will load all the assets that the game require
    loadAssets(m_Renderer);
    return;
}


void Platform::run()
{    
    int winW, winH;
    SDL_GetWindowSize(m_Window, &winW, &winH);

    Camera camera;
    camera.setSize(static_cast<float>(WIDTH / SCALE_FACTOR), static_cast<float>(HEIGHT / SCALE_FACTOR));

    Player p(Vector2f(static_cast<float>(WIDTH /2), static_cast<float>(HEIGHT / 2)), playerTexture, m_Renderer, camera);
    std::vector<Enemy>enemies = {Enemy(Vector2f(10, 10), enemyTexture, m_Renderer, camera)};

    playerW = p.getCurrentFrame().w;
    playerH = p.getCurrentFrame().h;

    while (isRunning)
    {
        lastTick = current_tick;
        current_tick = SDL_GetTicks();
        delta_time = (current_tick - lastTick) / 1000.0f;

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                isRunning = false;

            p.handleEvent(event);
        }

        SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        clean();

        camera.follow(p.getPos(), playerW, playerH);

        render(backGroundTexture, camera);
        
        //Render and update the enemies
        for (auto& e : enemies)
        {
            e.render(camera);
        }

        for (auto& e : enemies)
        {
            e.update(delta_time, p.getPos());
        }

        //Render the player
        p.updateRotation();
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

SDL_Window* Platform::getWindow()
{
    return m_Window;
}

SDL_Renderer* Platform::getRenderer()
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
    SDL_assert_release(texture != NULL);

    int texW, texH;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);

    SDL_Rect srcRect;
    srcRect.x = static_cast<int>(WIDTH / 2);
    srcRect.y = static_cast<int>(HEIGHT / 2);
    srcRect.w = texW;
    srcRect.h = texH;

    SDL_Rect dstRect;
    dstRect.x = 0;
    dstRect.y = 0;
    dstRect.w = texW;
    dstRect.h = texH;

    SDL_RenderCopy(m_Renderer, texture, &srcRect, &dstRect);
}