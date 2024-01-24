#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Math.h"
#include "Constants.h"
#include "Player.h"
#include "Apple.h"
#include "Stone.h"
#include "UI.h"
#include "Background.h"
#include "Leaderboard.h"

namespace ApplesGame {

	// TODO finish game if apples count equals zero
	// TODO: don't generate stone near start position

	enum GameMode {

		LimitedApples = 1,
		AcceleratedMovement = 2,
	};

	struct Game {

		int numApples = rand() % 20 + 10;

		// Player data
		Player player;

		// Apples data
		Apple* apples = new Apple[numApples];

		// Stones data
		Stone stones[NUM_STONES];

		// UI data
		UIState uiState;

		// Background data
		Background background;

		// Leaderboard data
		Leaderboard leaderboard;

		Result playerResult;

		// Global game data
		int numEatenApples = 0;
		bool isGameFinished = false;
		float gameFinishTime = 0.f;
		bool isGameMenuOpen = true;
		bool isLeaderboardOpen = false;
		int gameMode = 0;

		// Resources
		sf::Texture playerTexture;
		sf::Texture appleTexture;
		sf::Texture stoneTexture;

		sf::SoundBuffer appleEatSoundBuffer;
		sf::SoundBuffer gameOverSoundBuffer;

		sf::Sound gameOverSound;
		sf::Sound appleEatSound;

		sf::Font font;
	};

	void RestartGame(Game& game);
	void InitGame(Game& game);
	void HandlerInput(Game& game);
	void UpdateGame(Game& game, float deltaTime);
	void DrawGame(Game& game, sf::RenderWindow& window);
	void GameOver(Game& game);
	void InitSound(sf::SoundBuffer& soundBuffer, sf::Sound& sound, float volume);
	void PlayAppleEatSound(Game& game);
	void PlayGameOverSound(Game& game);
	void DeinitGame(Game& game);
	void SetGameMode(Game& game, int mode);
	void SetPlayerResult(Game& game);
	void OpenLeaderboard(Game& game);
}