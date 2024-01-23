#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Math.h"

namespace ApplesGame {

	struct Result {
		std::string name;
		int score;
	};

	struct Leaderboard {
		Result results[LEADERBOARD_PLAYERS_COUNT];

		sf::RectangleShape leaderboardBackground;

		sf::Text header;
		sf::Text placesText[LEADERBOARD_PLAYERS_COUNT];
	};

	void InitResult(Result& result, std::string name);
	void InitLeaderboard(Leaderboard& leaderboard, const sf::Font& font);
	void UpdateLeaderboard(Leaderboard& leaderboard, const struct Game& game);
	void DrawLeaderboard(Leaderboard& leaderboard, sf::RenderWindow& window);
}