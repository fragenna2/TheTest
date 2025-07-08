#pragma once
#include "entity.h"
#include "constants.h"

class Player : public Entity 
{

public:
    Player(Vector2f p_pos, SDL_Texture* p_texture, SDL_Renderer* renderer, Camera& camera);
    ~Player();

    void attack();
    void apply_damage(float hit);

    float get_health() const;
    int get_score() const;

    void handle_events(const SDL_Event& event);
    void update(float deltaTime);

    //TODO physics
    //float getMass() const;
    //float getGravityForce() const;

    //bool isColliding(const Vector2f& firstObject);

private:
    float m_Mass{ 9.f };
    float m_Health{ 20.f };
    int m_Score{ 0 };

    bool move_up = false;
    bool move_down = false;
    bool move_left = false;
    bool move_right = false;
};
