#pragma once
#include <string>

namespace ApplesGame {

	const int RANDOM_APPLES = (rand() % 30 + 5);
	const std::string RESOURCES_PATH = "Resources/";
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;
	const float INITIAL_SPEED = 100.f; // Pixels per second
	const float PLAYER_SIZE = 20.f;
	const float ACCELERATION = 20.f; // Pixels per second per second
	const int NUM_APPLES = 2;
	const float APPLE_SIZE = 20.f;
	const int NUM_STONES = 5;
	const float STONE_SIZE = 40.f;
	const float TIMEOUT = 3.f;
	const int LEADERBOARD_SIZE = 5;
	const std::string names[10] = { "Boss", "BigBoss", "Killer123", "Molodec", "Halk", "Leader", "Zombie", "Max", "Min", "Unknown" };
}