#include "game.h"

GameManager::GameManager()
{}

GameManager::~GameManager()
{
    delete m_Player;
}

void GameManager::init(SDL_Renderer* renderer)
{
    this->m_Renderer = renderer;
    // Camera initialization
    this->m_Camera.set_size(static_cast<float>(WIDTH / SCALE_FACTOR), static_cast<float>(HEIGHT / SCALE_FACTOR));

    // Player initialization
    this->m_Player = new Player(Vector2f(static_cast<float>(WIDTH / 2), static_cast<float>(HEIGHT / 2)), player_texture, m_Renderer, m_Camera);

    player_w = m_Player->get_current_frame().w;
    player_h = m_Player->get_current_frame().h;

    // Initializing the enemies
    this->enemies.reserve(1);
    this->enemies.emplace_back(Enemy(Vector2f(10, 10), enemy_texture, m_Renderer, m_Camera));
}


void GameManager::game_logic(float delta_time)
{

    // Make the camera follow the player in the game world
    m_Camera.follow(m_Player->get_pos(), player_w, player_h);

    //Render and update the enemies
    for (auto& e : enemies)
    {
        e.render(m_Camera);
    }

    for (auto& e : enemies)
    {
        e.update(delta_time, m_Player->get_pos());
        
        // Check for collisions
        if (is_colliding(m_Player->get_pos(), e.get_pos(), player_w))
        {
            exit(90);
        }

    }

    //Render the player
    m_Player->update_rotation();
    m_Player->render(m_Camera);
    m_Player->update(delta_time);

}

Player* GameManager::get_player()
{
    return m_Player;
}
