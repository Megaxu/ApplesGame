#include "Leaderboard.h"
#include "Game.h"

namespace ApplesGame {
	
	void InitResult(Result& result, std::string name) {
		result.name = name;
		result.score = rand() % 20 + 10;
	}

	void InitLeaderboard(Leaderboard& leaderboard, const sf::Font& font) {
		for (Result& result : leaderboard.results) {
			InitResult(result, NAMES[0]);
		}

		leaderboard.leaderboardBackground.setSize(sf::Vector2f(LEADERBOARD_SCREEN_WIDTH, LEADERBOARD_SCREEN_HEIGHT));
		leaderboard.leaderboardBackground.setOrigin(LEADERBOARD_SCREEN_WIDTH / 2, LEADERBOARD_SCREEN_HEIGHT / 2);
		leaderboard.leaderboardBackground.setFillColor(sf::Color::White);

		leaderboard.header.setFont(font);
		leaderboard.header.setCharacterSize(36);
		leaderboard.header.setStyle(sf::Text::Bold);
		leaderboard.header.setFillColor(sf::Color::Black);
		leaderboard.header.setString("Leaderboard!");
		SetTextRelativeOrigin(leaderboard.header, 0.5f, 0.5f);

		for (int i = 0; i < LEADERBOARD_PLAYERS_COUNT; ++i) {
			leaderboard.placesText[i].setFont(font);
			leaderboard.placesText[i].setCharacterSize(24);
			//leaderboard.placesText[i].setStyle(sf::Text::Bold);
			leaderboard.placesText[i].setFillColor(sf::Color::Black);
			leaderboard.placesText[i].setString(leaderboard.results[i].name + " | " + std::to_string(leaderboard.results[i].score));
			SetTextRelativeOrigin(leaderboard.placesText[i], 0.5f, 0.5f);
		}

	}

	void UpdateLeaderboard(Leaderboard& leaderboard, const Game& game) {

	}

	void DrawLeaderboard(Leaderboard& leaderboard, sf::RenderWindow& window) {
		leaderboard.leaderboardBackground.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
		window.draw(leaderboard.leaderboardBackground);

		leaderboard.header.setPosition(window.getSize().x / 2.f, (SCREEN_HEIGHT / 3) - 30);
		window.draw(leaderboard.header);

		for (int i = 0; i < LEADERBOARD_PLAYERS_COUNT; ++i) {
			leaderboard.placesText[i].setPosition(window.getSize().x / 2.f, (SCREEN_HEIGHT / 2.75) + i * 50);
			window.draw(leaderboard.placesText[i]);
		}
	}
}
