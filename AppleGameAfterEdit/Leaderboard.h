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
		Result results[LEADERBOARD_SIZE];

		sf::RectangleShape leaderboardBackground;

		sf::Text firstPlaceText;
		sf::Text secondPlaceText;
		sf::Text thirdPlaceText;
		sf::Text fourthPlaceText;
		sf::Text fifthPlaceText;
	};

	void InitResult(Result& result);
	void InitLeaderboard(Leaderboard& leaderboard, const sf::Font& font);
	void UpdateLeaderboard(Leaderboard& leaderboard, const struct Game& game);
	void DrawLeaderboard(Leaderboard& leaderboard, sf::RenderWindow& window);
}