#include "entity.h"

Entity::Entity(Vector2f p_pos, SDL_Texture* p_tex, SDL_Renderer* renderer)
    :m_Pos(p_pos), m_Texture(p_tex), m_Renderer(renderer) 
{
    m_CurrentFrame.x = 0;
    m_CurrentFrame.y = 0;
    SDL_QueryTexture(m_Texture, NULL, NULL, &m_CurrentFrame.w, &m_CurrentFrame.h);
}

Vector2f& Entity::getPos()
{
    return m_Pos;
}

SDL_Texture* Entity::getTexture()
{
    return m_Texture;
}

SDL_Rect Entity::getCurrentFrame()
{
    return m_CurrentFrame;
}

void Entity::render()
{
    SDL_Rect dest_rect = {
        static_cast<int>(m_Pos.m_X - m_CurrentFrame.w /2),
        static_cast<int>(m_Pos.m_Y - m_CurrentFrame.h /2),
        m_CurrentFrame.w * SCALE_FACTOR,
        m_CurrentFrame.h * SCALE_FACTOR
    };

    SDL_RenderCopyEx(m_Renderer, m_Texture, &m_CurrentFrame, &dest_rect, m_Angle, NULL, SDL_FLIP_NONE);
}

void Entity::updateRotation()
{
    int mouse_x, mouse_y;
    SDL_GetMouseState(&mouse_x, &mouse_y);

    float sprite_x = getPos().m_X / 2;
    float sprite_y = getPos().m_Y / 2;

    float dx = mouse_x - sprite_x;
    float dy = mouse_y - sprite_y;

    m_Angle = atan2(dy, dx) * 180.0 / M_PI + 90.f;
}