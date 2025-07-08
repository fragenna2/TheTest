#include "player.h"

Player::Player(Vector2f p_pos, SDL_Texture* p_texture, SDL_Renderer* renderer, Camera& camera)
    : Entity(p_pos, p_texture, renderer, camera)
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
            case SDLK_w: move_up = true; break;
            case SDLK_s: move_down = true; break;
            case SDLK_a: move_left = true; break;
            case SDLK_d: move_right = true; break;
        }
    }
    else if(event.type == SDL_KEYUP)
    {
        switch(event.key.keysym.sym)
        {
            case SDLK_w: move_up = false; break;
            case SDLK_s: move_down = false; break;
            case SDLK_a: move_left = false; break;
            case SDLK_d: move_right = false; break;
        }
    }
}

void Player::update(float deltaTime)
{
    Vector2f direction(0.0f, 0.0f);

    if(move_up)
        direction.m_Y = -1.0f;
    if(move_down)
        direction.m_Y = 1.0f;
    if(move_left)
        direction.m_X = -1.0f;
    if(move_right)
        direction.m_X = 1.0f;

    if (direction.m_X != 0.0f || direction.m_Y != 0.0f)
    {
        Vector2f norm_dir = direction.normalize();

        getPos().m_X += norm_dir.m_X * PLAYER_SPEED * deltaTime;
        getPos().m_Y += norm_dir.m_Y * PLAYER_SPEED * deltaTime;
    }

}

//TODO per fisica
//getPos().m_Y += getGravityForce() * deltaTime;

//float Player::getMass() const
//{
//    return m_Mass;
//}
//
//float Player::getGravityForce() const
//{
//    return m_Mass * GRAVITY_ACCELERATION;
//}

//bool Player::isColliding(const Vector2f& firstObject)
//{
//    const float epsilon = 0.1f;
//    float playerBottomY = getPos().m_Y - 16.0f;
//
//    return std::abs(playerBottomY - firstObject.m_Y + 16) < epsilon;
//}
