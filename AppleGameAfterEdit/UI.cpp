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
	}

	void UpdateUI(UIState& uiState, const Game& game) {
		uiState.scoreText.setString("Apples eaten: " + std::to_string(game.numEatenApples));
		uiState.startHintText.setString("Use:\n1 - Limited apples mode - " + uiState.firtsOptionInfo + "\n2 - Accelerated movement mode - " + uiState.secondOptionInfo + "\nSpace - start game\nESC to exit");
		uiState.isGameOverTextVisible = game.isGameFinished;
		uiState.isStartGameTextVisible = game.isGameMenuOpen;
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

		if (uiState.isStartGameTextVisible) {
			uiState.startHintText.setPosition(10.f, 10.f);
			window.draw(uiState.startHintText);
		}
	}
}