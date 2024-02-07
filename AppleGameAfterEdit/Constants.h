#pragma once
#include <string>


namespace ApplesGame {

	const std::string RESOURCES_PATH = "Resources/";
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;
	const float INITIAL_SPEED = 100.f; // Pixels per second
	const float PLAYER_SIZE = 20.f;
	const float ACCELERATION = 20.f; // Pixels per second per second
	const float APPLE_SIZE = 20.f;
	const float STONE_SIZE = 40.f;
	const float TIMEOUT = 3.f;
	const int LEADERBOARD_PLAYERS_COUNT = 5;
	const int LEADERBOARD_SCREEN_WIDTH = SCREEN_WIDTH / 2;
	const int LEADERBOARD_SCREEN_HEIGHT = SCREEN_HEIGHT / 2;
}