#pragma once
#include <SDL2/SDL.h>
#include "lib_selector.h"
#include "game_math.h"
#include "constants.h"
#include "camera.h"

class Entity
{
public:
    Entity(Vector2f p_pos, SDL_Texture* p_tex, SDL_Renderer* renderer, Camera& camera);     // Default constructor

    Vector2f& get_pos();                            // Getter for the position

    SDL_Texture* get_texture();                     // Getter for the texture
    SDL_Rect get_current_frame();                   // Getter for the frame

    void update_rotation();                         // Method to update the rotation
    void render(Camera& camera);                    // Method to render the enemy

private:
    SDL_Renderer* m_Renderer;                       // Renderer copy
    Vector2f m_Pos;                                 // Vector position
    SDL_Rect m_CurrentFrame;                        // Current frame
    SDL_Texture* m_Texture;                         // Texture
    
    Camera& m_Camera;                               // Camera field

    float m_Angle = 0.f;                            // Rotation of the texture
};