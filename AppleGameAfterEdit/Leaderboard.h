#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Math.h"
#include <string>

namespace ApplesGame {

	struct Result {
		std::string name;
		int score;
	};

	struct Leaderboard {
		Result results[LEADERBOARD_PLAYERS_COUNT];
	};

	void InitResult(Result& result, std::string name, int score);
	void InitLeaderboard(Leaderboard& leaderboard, struct Game& game);
	void UpdateLeaderboard(Leaderboard& leaderboard, struct Game& game);
	void SortLeaderboard(Leaderboard& leaderboard, Game& game, int size);
	void SearchAndReplace(Leaderboard& leaderboard, struct Game& game, int end);
	std::string GetRandomName(int end);
	bool CheckPlayer(Leaderboard& leaderboard, struct Game& game, int size);
}