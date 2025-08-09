#pragma once
#include "math.h"

struct Vector2f
{
    Vector2f() : m_X(0.0f), m_Y(0.0f)                       // Default constructor
    {}

    Vector2f(float p_x, float p_y) : m_X(p_x), m_Y(p_y)     // Constructor that require x and y coordinates
    {}

    /*
        Operators for subtracting
    */
    Vector2f operator-(const Vector2f& other) const;
    Vector2f operator+(const Vector2f& other) const;
    Vector2f operator*(float scalar) const;
    Vector2f& operator+=(const Vector2f& other);

    float length() const;                                   // Method to calculate the lenght of the vector
    Vector2f normalize() const;                             // Method to make the vector with module 1
    
    float distance(const Vector2f& other) const;            // Return the distance between two vectors

    float m_X, m_Y;                                         // Field for x and y coordinates
};

bool is_colliding(const Vector2f& enemy_pos, const Vector2f& p_pos, float ship_size); // Check if two vectors are colliding and return a boolean