#pragma once

#ifdef _WIN32
	constexpr int WIDTH = 1200;
	constexpr int HEIGHT = 720;
#elif __linux__
	constexpr int WIDTH = 1920;
	constexpr int HEIGHT = 1080;
#else
	constexpr int WIDTH = 1800;
	constexpr int HEIGHT = 1200;
#endif

constexpr int SCALE_FACTOR = 4;
constexpr int PLAYER_SPEED = 200;
constexpr float GRAVITY_ACCELERATION = 5.f;
constexpr int ENEMY_SPEED = 150;