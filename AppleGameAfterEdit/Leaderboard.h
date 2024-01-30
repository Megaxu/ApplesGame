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
	void SortLeaderBoard(Leaderboard& leaderboard, int size);
	void SearchAndReplace(Leaderboard& leaderboard, struct Game& game, int end);
	std::string SetRandomName(int end);
	bool CheckPlayer(Leaderboard& leaderboard, const struct Game& game);
}