#pragma once
#include "entity.h"
#include "constants.h"

class Player : public Entity 
{

public:
    Player(Vector2f p_pos, SDL_Texture* p_texture, SDL_Renderer* renderer, Camera& camera);
    ~Player();

    void attack();
    void takeDamage(float hit);

    float getHealth() const;
    int getScore() const;

    void handleEvent(const SDL_Event& event);
    void update(float deltaTime);

    //TODO physics
    //float getMass() const;
    //float getGravityForce() const;

    //bool isColliding(const Vector2f& firstObject);

private:
    float m_Mass{ 9.f };
    float m_Health{ 20.f };
    int m_Score{ 0 };

    bool moveUp = false;
    bool moveDown = false;
    bool moveLeft = false;
    bool moveRight = false;
};
