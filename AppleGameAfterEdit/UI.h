#pragma once
#include "SFML/Graphics.hpp" // Подключаем библиотеку для удобства создания игр и приложений, в частности подключаем модуль для графики
#include "Constants.h"
#include <string>

namespace ApplesGame {

	struct UIState {
		bool isGameOverTextVisible = false;
		bool isStartGameTextVisible = true;
		bool isLeaderboardVisible = false;

		std::string firtsOptionInfo;
		std::string secondOptionInfo;

		sf::Text scoreText;
		sf::Text inputHintText;
		sf::Text gameOverText;
		sf::Text startHintText;

		sf::RectangleShape leaderboardBackground;
		sf::Text headerLeaderboard;
		sf::Text placesText[LEADERBOARD_PLAYERS_COUNT];
	};

	void InitUI(UIState& uiState, const sf::Font& font);
	void UpdateUI(UIState& uiState, const struct Game& game);
	void DrawUI(UIState& uiState, sf::RenderWindow& window);

}