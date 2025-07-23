#include "game.h"

#include <iostream>

int player_w;
int player_h;

void game_logic(Player* player, Camera& camera, float delta_time, std::vector<Enemy>* enemies)
{

    // Make the camera follow the player in the game world
    camera.follow(player->get_pos(), player_w, player_h);

    //Render and update the enemies
    for (auto& e : *enemies)
    {
        e.render(camera);
    }

    for (auto& e : *enemies)
    {
        e.update(delta_time, player->get_pos());
    }

    //Render the player
    player->update_rotation();
    player->render(camera);
    player->update(delta_time);

}

void init_character(Player* player)
{
    player_w = player->get_current_frame().w;
    player_h = player->get_current_frame().h;
}