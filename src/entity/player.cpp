#include "player.h"

Player::Player(Vector2f p_pos, SDL_Texture* p_texture, SDL_Renderer* renderer)
    : Entity(p_pos, p_texture, renderer)
{}

Player::~Player() {}

void Player::attack()
{
    return;
}

void Player::takeDamage(float hit)
{
    m_Health -= hit;
    if (m_Health < 0.f) m_Health = 0.f;
}

float Player::getHealth() const 
{
    return m_Health;
}

int Player::getScore() const
{
    return m_Score;
}

void Player::handleEvent(const SDL_Event& event)
{

    if(event.type == SDL_KEYDOWN)
    {
        switch(event.key.keysym.sym)
        {
            case SDLK_w: moveUp = true; break;
            case SDLK_s: moveDown = true; break;
            case SDLK_a: moveLeft = true; break;
            case SDLK_d: moveRight = true; break;
        }
    }
    else if(event.type == SDL_KEYUP)
    {
        switch(event.key.keysym.sym)
        {
            case SDLK_w: moveUp = false; break;
            case SDLK_s: moveDown = false; break;
            case SDLK_a: moveLeft = false; break;
            case SDLK_d: moveRight = false; break;
        }
    }
}

void Player::update(float deltaTime)
{
    Vector2f direction(0.0f, 0.0f);

    if(moveUp)
        getPos().m_Y -= 1.0f;
    if(moveDown)
        getPos().m_Y += 1.0f;
    if(moveLeft)
        getPos().m_X -= 1.0f;
    if(moveRight)
        getPos().m_X += 1.0f;

    if (direction.m_X != 0.0f || direction.m_Y != 0.0f)
    {
        Vector2f normDir = direction.normalize();

        getPos().m_X = normDir.m_X * PLAYER_SPEED * deltaTime;
        getPos().m_Y = normDir.m_Y * PLAYER_SPEED * deltaTime;
    }
}
