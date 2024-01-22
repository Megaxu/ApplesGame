#pragma once
#include "SFML/Graphics.hpp" // ���������� ���������� ��� �������� �������� ��� � ����������, � ��������� ���������� ������ ��� �������
#include <string>

namespace ApplesGame {

	struct UIState {
		bool isGameOverTextVisible = false;
		bool isStartGameTextVisible = true;

		std::string firtsOptionInfo;
		std::string secondOptionInfo;

		sf::Text scoreText;
		sf::Text inputHintText;
		sf::Text gameOverText;
		sf::Text startHintText;
	};

	void InitUI(UIState& uiState, const sf::Font& font);
	void UpdateUI(UIState& uiState, const struct Game& game);
	void DrawUI(UIState& uiState, sf::RenderWindow& window);
}