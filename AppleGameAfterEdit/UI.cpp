#include "UI.h"
#include "Game.h"

namespace ApplesGame {

	void InitUI(UIState& uiState, const sf::Font& font) {
		// Init score text
		uiState.scoreText.setFont(font);
		uiState.scoreText.setCharacterSize(24);
		uiState.scoreText.setFillColor(sf::Color::Yellow);

		// Init hint text
		uiState.inputHintText.setFont(font);
		uiState.inputHintText.setCharacterSize(24);
		uiState.inputHintText.setFillColor(sf::Color::White);
		uiState.inputHintText.setString("Use WASD to move, ESC to exit");
		SetTextRelativeOrigin(uiState.inputHintText, 1.f, 0.f);

		// Init game over text
		uiState.isGameOverTextVisible = false;
		uiState.gameOverText.setFont(font);
		uiState.gameOverText.setCharacterSize(144);
		uiState.gameOverText.setStyle(sf::Text::Bold);
		uiState.gameOverText.setFillColor(sf::Color::Red);
		uiState.gameOverText.setString("GAME OVER");
		SetTextRelativeOrigin(uiState.gameOverText, 0.5f, 0.5f);

		// Init start menu text
		uiState.firtsOptionInfo = "Off";
		uiState.secondOptionInfo = "Off";
		uiState.isStartGameTextVisible = true;
		uiState.startHintText.setFont(font);
		uiState.startHintText.setCharacterSize(24);
		uiState.startHintText.setFillColor(sf::Color::White);

		//
		uiState.leaderboardBackground.setSize(sf::Vector2f(LEADERBOARD_SCREEN_WIDTH, LEADERBOARD_SCREEN_HEIGHT));
		uiState.leaderboardBackground.setOrigin(LEADERBOARD_SCREEN_WIDTH / 2.f, LEADERBOARD_SCREEN_HEIGHT / 2.f);
		uiState.leaderboardBackground.setFillColor(sf::Color::White);

		uiState.headerLeaderboard.setFont(font);
		uiState.headerLeaderboard.setCharacterSize(36);
		uiState.headerLeaderboard.setStyle(sf::Text::Bold);
		uiState.headerLeaderboard.setFillColor(sf::Color::Black);
		uiState.headerLeaderboard.setString("Leaderboard!");
		SetTextRelativeOrigin(uiState.headerLeaderboard, 0.5f, 0.5f);

		for (int i = 0; i < LEADERBOARD_PLAYERS_COUNT; ++i) {
			uiState.placesText[i].setFont(font);
			uiState.placesText[i].setCharacterSize(24);
			uiState.placesText[i].setFillColor(sf::Color::Black);
			SetTextRelativeOrigin(uiState.placesText[i], 0.5f, 0.5f);
		}
	}

	void UpdateUI(UIState& uiState, const Game& game) {
		uiState.scoreText.setString("Apples eaten: " + std::to_string(game.numEatenApples));
		uiState.startHintText.setString("Use:\n1 - Limited apples mode - " + uiState.firtsOptionInfo + "\n2 - Accelerated movement mode - " + uiState.secondOptionInfo + "\nSpace - start game\nESC to exit");
		uiState.isGameOverTextVisible = game.isGameFinished;
		uiState.isStartGameTextVisible = game.isGameMenuOpen;
		uiState.isLeaderboardVisible = game.isLeaderboardOpen;

		for (int i = 0; i < LEADERBOARD_PLAYERS_COUNT; ++i) {
			uiState.placesText[i].setString(game.leaderboard.results[i].name + " | " + std::to_string(game.leaderboard.results[i].score));
		}
	}

	void DrawUI(UIState& uiState, sf::RenderWindow& window) {

		if (!uiState.isGameOverTextVisible && !uiState.isStartGameTextVisible) {
			uiState.scoreText.setPosition(10.f, 10.f);
			window.draw(uiState.scoreText);

			uiState.inputHintText.setPosition(window.getSize().x - 10.f, 10.f);
			window.draw(uiState.inputHintText);
		}

		if (uiState.isGameOverTextVisible) {
			uiState.gameOverText.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
			window.draw(uiState.gameOverText);
		}

		// 
		if (uiState.isLeaderboardVisible) {
			uiState.leaderboardBackground.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
			window.draw(uiState.leaderboardBackground);

			uiState.headerLeaderboard.setPosition(window.getSize().x / 2.f, (SCREEN_HEIGHT / 3) - 30);
			window.draw(uiState.headerLeaderboard);

			for (int i = 0; i < LEADERBOARD_PLAYERS_COUNT; ++i) {
				uiState.placesText[i].setPosition(window.getSize().x / 2.5f, (SCREEN_HEIGHT / 2.75f) + i * 50);
				window.draw(uiState.placesText[i]);
			}
		}

		if (uiState.isStartGameTextVisible) {
			uiState.startHintText.setPosition(10.f, 10.f);
			window.draw(uiState.startHintText);
		}
	}
}