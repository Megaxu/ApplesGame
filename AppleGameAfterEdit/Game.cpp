#include "Game.h"
#include "cassert"
#include <iostream>

namespace ApplesGame {

	void RestartGame(Game& game) {
		
		// Init background
		InitBackground(game.background);

		// Init player
		InitPlayer(game.player, game);

		// Init apples
		for (Apple* ptr = game.apples; ptr < game.apples + game.numApples; ++ptr) {
			InitApple(*ptr, game);
		}

		// Init stones
		for (Stone& stone : game.stones) {
			InitStone(stone, game);
		}

		if (game.gameMode & GameMode::LimitedApples) {
			game.numEatenApples = game.numApples;
		}
		else {
			game.numEatenApples = 0;
		}

		game.isGameFinished = false;
		game.gameFinishTime = 0.f;
	}

	void InitGame(Game& game) {

		// Load textures
		assert(game.playerTexture.loadFromFile(RESOURCES_PATH + "\\Player.png"));
		assert(game.appleTexture.loadFromFile(RESOURCES_PATH + "\\Apple.png"));
		assert(game.stoneTexture.loadFromFile(RESOURCES_PATH + "\\Rock.png"));

		// Load fonts
		assert(game.font.loadFromFile(RESOURCES_PATH + "Fonts/Roboto-Regular.ttf"));

		// Load sounds
		assert(game.appleEatSoundBuffer.loadFromFile(RESOURCES_PATH + "\\AppleEat.wav"));
		assert(game.gameOverSoundBuffer.loadFromFile(RESOURCES_PATH + "\\Death.wav"));

		// Set audio params
		InitSound(game.gameOverSoundBuffer, game.gameOverSound, 25.f);
		InitSound(game.appleEatSoundBuffer, game.appleEatSound, 25.f);

		// Init UI
		InitUI(game.uiState, game.font);

		// Init playerResult
		InitResult(game.playerResult, "Player");

		// Init leaderboard
		InitLeaderboard(game.leaderboard, game.font);

		RestartGame(game);
	}

	void HandlerInput(Game& game) {

		//sf::Event event;
		if (game.isGameMenuOpen) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				game.isGameMenuOpen = false;
				RestartGame(game);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
				game.uiState.firtsOptionInfo = "On";
				SetGameMode(game, GameMode::LimitedApples);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
				game.uiState.secondOptionInfo = "On";
				SetGameMode(game, GameMode::AcceleratedMovement);
			}

			// We don't handle input in game over state
			return;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			game.player.playerDirection = PlayerDirection::Right;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			game.player.playerDirection = PlayerDirection::Up;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			game.player.playerDirection = PlayerDirection::Left;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			game.player.playerDirection = PlayerDirection::Down;
		}
	}

	void UpdateGame(Game& game, float deltaTime) {
		if (!game.isGameFinished) {
			// Handler for keyboard
			HandlerInput(game);

			if (game.isGameMenuOpen) {
				UpdateUI(game.uiState, game);
				return;
			}

			// Set player's direction
			SetPlayerDirection(game, deltaTime);

			// Check stones collision
			for (Stone& stone : game.stones) {
				if (isRectanglesCollide(game.player.position, { PLAYER_SIZE, PLAYER_SIZE }, stone.position, { STONE_SIZE, STONE_SIZE })) {
					GameOver(game);
				}
			}

			// Check screen borders collision
			if (game.player.position.x - PLAYER_SIZE / 2.f < 0.f || game.player.position.x + PLAYER_SIZE / 2.f > SCREEN_WIDTH || game.player.position.y - PLAYER_SIZE / 2.f < 0.f || game.player.position.y + PLAYER_SIZE / 2.f > SCREEN_HEIGHT) {
				GameOver(game);
			}

			// Check apples collision
			for (int i = 0; i < game.numApples; i++) {
				if (isCirclesCollide(game.player.position, PLAYER_SIZE / 2.f, game.apples[i].position, APPLE_SIZE / 2) && !game.apples[i].isEaten) {
					PlayAppleEatSound(game);
					// Behavior depending on the gamemode
					if (game.gameMode & GameMode::LimitedApples) {
						--game.numEatenApples;
						game.apples[i].isEaten = true;
					}
					else {
						++game.numEatenApples;
						game.apples[i].position = GetRandomPositionInScreen(SCREEN_WIDTH, SCREEN_HEIGHT);
					}
					// Speed ​​increase from apple if gamemode on
					if (game.gameMode >> 2 & GameMode::AcceleratedMovement) {
						game.player.playerSpeed += ACCELERATION;
					}
				}
			}

		}
		else {
			if (game.gameFinishTime <= TIMEOUT) {
				game.gameFinishTime += deltaTime;
				SetBackgroundColor(game.background, sf::Color::Green);
			}
			else {
				RestartGame(game);
			}
		}
		UpdateUI(game.uiState, game);
	}

	void DrawGame(Game& game, sf::RenderWindow& window) {

		// Draw background
		DrawBackground(game.background, window);

		// Draw player
		DrawPlayer(game.player, window);

		// Draw apples
		for (Apple* ptr = game.apples; ptr < game.apples + game.numApples; ++ptr) {
			DrawApple(*ptr, window);
		}

		// Draw stones
		for (Stone& stone : game.stones) {
			DrawStone(stone, window);
		}

		DrawUI(game.uiState, window);

		DrawLeaderboard(game.leaderboard, window);
	}

	void PlayAppleEatSound(Game& game) {
		game.appleEatSound.play();
	}

	void PlayGameOverSound(Game& game) {
		game.gameOverSound.play();
	}

	void GameOver(Game& game) {
		PlayGameOverSound(game);
		game.isGameFinished = true;
		game.gameFinishTime = 0.f;
	}

	void InitSound(sf::SoundBuffer& soundBuffer, sf::Sound& sound, float volume) {
		sound.setBuffer(soundBuffer);
		sound.setVolume(volume);
	}

	void DeinitGame(Game& game) {
		delete[] game.apples;
	}

	void SetGameMode(Game& game, int mode) {
		switch (mode) {
		case 1:
		{
			game.gameMode |= (mode << 0);
			break;
		}
		case 2:
		{
			game.gameMode |= (mode << 2);
			break;
		}
		}
	}
	void OpenLeaderboard(Game& game, sf::RenderWindow& window) {
	}
}