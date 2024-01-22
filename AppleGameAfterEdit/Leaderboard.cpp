#include "Leaderboard.h"
#include "Game.h"

namespace ApplesGame {
	
	void InitResult(Result& result) {
		result.name = "FFFF";
		result.score = (rand() % 25);
	}

	void InitLeaderboard(Leaderboard& leaderboard, const sf::Font& font) {
		for (Result& result : leaderboard.results) {
			InitResult(result);
		}

		leaderboard.leaderboardBackground.setSize(sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));
		leaderboard.leaderboardBackground.setOrigin(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
		leaderboard.leaderboardBackground.setFillColor(sf::Color::White);
		leaderboard.leaderboardBackground.setPosition(0.f, 0.f);

		// Init game over text
		leaderboard.firstPlaceText.setFont(font);
		leaderboard.firstPlaceText.setCharacterSize(24);
		leaderboard.firstPlaceText.setStyle(sf::Text::Bold);
		leaderboard.firstPlaceText.setFillColor(sf::Color::Black);
		leaderboard.firstPlaceText.setString(leaderboard.results[0].name + " | " + std::to_string(leaderboard.results[0].score));
		SetTextRelativeOrigin(leaderboard.firstPlaceText, 0.5f, 0.5f);

	}

	void UpdateLeaderboard(Leaderboard& leaderboard, const Game& game) {
	}

	void DrawLeaderboard(Leaderboard& leaderboard, sf::RenderWindow& window) {
		window.draw(leaderboard.leaderboardBackground);
		leaderboard.firstPlaceText.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
		window.draw(leaderboard.firstPlaceText);
	}


}
