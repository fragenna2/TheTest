#pragma once

struct Vector2f
{
    Vector2f() : m_X(0.0f), m_Y(0.0f)
    {}

    Vector2f(float p_x, float p_y) : m_X(p_x), m_Y(p_y)
    {}

    //TODO print function

    float m_X, m_Y;
};
