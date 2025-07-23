#pragma once
#include "platform.h"
#include "player.h"
#include "camera.h"
#include "enemy.h"

#include <vector>

void init_character(Player* player);
void game_logic(Player* player, Camera& camera ,float delta_time, std::vector<Enemy>* enemies);