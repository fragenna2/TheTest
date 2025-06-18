#pragma once
#include "entity.h"
#include "constants.h"

class Player : public Entity 
{

public:
    Player(Vector2f p_pos, SDL_Texture* p_texture, SDL_Renderer* renderer);
    ~Player();

    void attack();
    void takeDamage(float hit);

    float getHealth() const;
    int getScore() const;

    void handleEvent(const SDL_Event& event);
    void update(float deltaTime);

private:
    float m_Health = 20.f;
    int m_Score = 0;

    bool moveUp = false;
    bool moveDown = false;
    bool moveLeft = false;
    bool moveRight = false;


};
