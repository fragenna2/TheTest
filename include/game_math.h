#pragma once
#include "math.h"

struct Vector2f
{
    Vector2f() : m_X(0.0f), m_Y(0.0f)
    {}

    Vector2f(float p_x, float p_y) : m_X(p_x), m_Y(p_y)
    {}

    Vector2f operator-(const Vector2f& other) const;
    Vector2f operator+(const Vector2f& other) const;
    Vector2f operator*(float scalar) const;
    Vector2f& operator+=(const Vector2f& other);

    float length() const;
    Vector2f normalize() const;
    
    float distance(const Vector2f& other) const;

    float m_X, m_Y;
};

bool is_colliding(const Vector2f& enemy_pos, const Vector2f& p_pos, float ship_size);