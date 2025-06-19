#include "platform.h"

bool moveUp = false;
bool moveDown = false;
bool moveLeft = false;
bool moveRight = false;

Uint32 lastTick = 0;
Uint32 current_tick = 0;
float delta_time;

int mouse_x;
int mouse_y;

bool isRunning = true;

Platform::Platform(const char* gameName, int width, int height)
 : m_GameName(gameName), m_Width(width), m_Height(height)
{}

Platform::~Platform()
{}

void Platform::initAndRun()
{
    SDL_Init(SDL_INIT_VIDEO);

    m_Window = SDL_CreateWindow("The test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_Width, m_Height, 0);
    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_SOFTWARE);

    loadAssets(m_Renderer);
    
    Player p(Vector2f(100, 100), player, m_Renderer);
    std::vector<Entity> entities = { Entity(Vector2f(10.f, 5.f), player, m_Renderer), Entity(Vector2f(64.f, 5.f), player, m_Renderer), Entity(Vector2f(120.f, 5.f), player, m_Renderer) };

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

        for (auto &e : entities)
        {
            render(e);
        }

        //Render the player
        p.updateRotation();
        p.render();
        p.update(delta_time);

        display();
    }
    
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

void Platform::render(Entity& entity)
{
    SDL_Rect src;
    src.x = entity.getCurrentFrame().x;
    src.y = entity.getCurrentFrame().y;
    src.w = entity.getCurrentFrame().w;
    src.h = entity.getCurrentFrame().h;

    SDL_Rect dst;
    dst.x = entity.getPos().m_X * SCALE_FACTOR;
    dst.y = entity.getPos().m_Y * SCALE_FACTOR;
    dst.w = entity.getCurrentFrame().w * 2; //We can multiply for a constants for making it bigger
    dst.h = entity.getCurrentFrame().h * 2; //We can multiply for a constants for making it bigger

    SDL_RenderCopy(m_Renderer, entity.getTexture(), &src, &dst);
}

void Platform::display()
{
    SDL_RenderPresent(m_Renderer);
}