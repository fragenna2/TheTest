#include "game_math.h"

float Vector2f::length() const
{
    return sqrt(m_X * m_X + m_Y * m_Y);
}

Vector2f Vector2f::operator-(const Vector2f& other) const
{
    return Vector2f(m_X - other.m_X, m_Y - other.m_Y);
}

Vector2f Vector2f::operator+(const Vector2f& other) const
{
    return Vector2f(m_X + other.m_X, m_Y + other.m_Y);
}

Vector2f Vector2f::operator*(float scalar) const
{
    return Vector2f(m_X * scalar, m_Y * scalar);
}

Vector2f& Vector2f::operator+=(const Vector2f& other)
{
    m_X += other.m_X;
    m_Y += other.m_Y;
    return *this;
}


Vector2f Vector2f::normalize() const
{
    float len = length();
    if (len == 0) 
    {
        return Vector2f(0.f, 0.f);
    }
    else
    {
        return Vector2f(m_X / len, m_Y / len);
    }

}

float Vector2f::distance(const Vector2f& other) const
{
    float dx = other.m_X - m_X; // Usa m_X dell'oggetto corrente
    float dy = other.m_Y - m_Y; // Usa m_Y dell'oggetto corrente
    
    return std::sqrt(dx * dx + dy * dy);
}

bool is_colliding(const Vector2f& enemy_pos, const Vector2f& p_pos, float ship_size)
{
    return enemy_pos.distance(p_pos) <= ship_size;
}