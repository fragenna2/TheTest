#include "entity.h"

Entity::Entity(Vector2f p_pos, SDL_Texture* p_tex, SDL_Renderer* renderer, Camera& camera)
    :m_Pos(p_pos), m_Texture(p_tex), m_Renderer(renderer), m_Camera(camera)
{
    m_CurrentFrame.x = 0;
    m_CurrentFrame.y = 0;
    SDL_QueryTexture(m_Texture, NULL, NULL, &m_CurrentFrame.w, &m_CurrentFrame.h);
}

Vector2f& Entity::get_pos()
{
    return m_Pos;
}

SDL_Texture* Entity::get_texture()
{
    return m_Texture;
}

SDL_Rect Entity::get_current_frame()
{
    return m_CurrentFrame;
}

void Entity::render(Camera& camera) 
{
    Vector2f screenPos = m_Pos - camera.getPos();
    SDL_Rect dest_rect = {
        static_cast<int>(screenPos.m_X * SCALE_FACTOR - (m_CurrentFrame.w * SCALE_FACTOR) / 2),
        static_cast<int>(screenPos.m_Y * SCALE_FACTOR - (m_CurrentFrame.h * SCALE_FACTOR) / 2),
        m_CurrentFrame.w * SCALE_FACTOR,
        m_CurrentFrame.h * SCALE_FACTOR
    };

    SDL_RenderCopyEx(m_Renderer, m_Texture, &m_CurrentFrame, &dest_rect, m_Angle, NULL, SDL_FLIP_NONE);
}

void Entity::update_rotation()
{
    int mouse_x, mouse_y;
    SDL_GetMouseState(&mouse_x, &mouse_y);

    float sprite_x = get_pos().m_X / 2;
    float sprite_y = get_pos().m_Y / 2;

    float dx = mouse_x - sprite_x;
    float dy = mouse_y - sprite_y;

    m_Angle = atan2(dy, dx) * 180.0 / M_PI + 90.f;
}