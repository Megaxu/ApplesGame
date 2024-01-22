// ©2023, XYZ School. All rights reserved.
// Authored by Aleksandr Rybalka (polterageist@gmail.com)

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

const std::string RESOURCES_PATH = "Resources/";
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

const float INITIAL_PLAYER_SPEED = 100.f;
const float PLAYER_WIDTH = 100.f;
const float PLAYER_HEIGHT = 10.f;

const float INITIAL_ENEMY_SPEED = 100.f;
const float ENEMY_WIDTH = 100.f;
const float ENEMY_HEIGHT = 10.f;

const float INITIAL_BALL_SPEED = 100.f;
const float BALL_SIZE = 20.f;

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Pong game");

	// init player
	float playerX = SCREEN_WIDTH / 2.f;
	float playerY = 0 + BALL_SIZE * 2;
	float playerSpeed = INITIAL_PLAYER_SPEED;

	// init enemy
	float enemyX = SCREEN_WIDTH / 2.f;
	float enemyY = SCREEN_HEIGHT - BALL_SIZE * 2;
	float enemySpeed = INITIAL_ENEMY_SPEED;
	int enemyDirection = 0; // right - 0, left - 1

	// Init player shape
	sf::RectangleShape playerShape;
	playerShape.setSize(sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT));
	playerShape.setFillColor(sf::Color::Green);
	playerShape.setOrigin(PLAYER_WIDTH / 2.f, PLAYER_HEIGHT / 2.f); // Относительный центр
	playerShape.setPosition(playerX, playerY);

	// Init enemy shape
	sf::RectangleShape enemyShape;
	enemyShape.setSize(sf::Vector2f(ENEMY_WIDTH, ENEMY_HEIGHT));
	enemyShape.setFillColor(sf::Color::Red);
	enemyShape.setOrigin(ENEMY_WIDTH / 2.f, ENEMY_HEIGHT / 2.f); // Относительный центр
	enemyShape.setPosition(enemyX, enemyY);

	// init ball
	float ballX = SCREEN_WIDTH / 2.f;
	float ballY = SCREEN_HEIGHT / 2.f;
	float ballSpeed = INITIAL_BALL_SPEED;

	// Init ball shape
	sf::CircleShape ballShape;
	ballShape.setRadius(BALL_SIZE / 2.f);
	ballShape.setFillColor(sf::Color::White);
	ballShape.setOrigin(BALL_SIZE / 2.f, BALL_SIZE / 2.f); // Относительный центр
	ballShape.setPosition(ballX, ballY);

	// Init game clock
	sf::Clock gameClock;
	float lastTime = gameClock.getElapsedTime().asSeconds();

	while (window.isOpen())
	{
		// Calculate delta time
		float currentTime = gameClock.getElapsedTime().asSeconds();
		float deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// handler keyboard
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && playerX + PLAYER_WIDTH / 2.f < SCREEN_WIDTH) {
			playerX += playerSpeed * deltaTime;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && playerX - PLAYER_WIDTH / 2.f > 0.f) {
			playerX -= playerSpeed * deltaTime;
		}

		// change enemy direction when touch border
		if (enemyX - ENEMY_WIDTH / 2.f < 0.f) {
			enemyDirection = 0;
		}
		else if (enemyX + ENEMY_WIDTH / 2.f > SCREEN_WIDTH) {
			enemyDirection = 1;
		}

		// enemy move
		if (enemyDirection == 0) {
			enemyX += enemySpeed * deltaTime;
		}
		else if (enemyDirection == 1) {
			enemyX -= enemySpeed * deltaTime;
		}
		
		// check ball border collision

		// check ball player collision

		// check ball enemy collision

		// check goal

		window.clear();
		playerShape.setPosition(playerX, playerY);
		enemyShape.setPosition(enemyX, enemyY);
		ballShape.setPosition(ballX, ballY);

		window.draw(playerShape);
		window.draw(enemyShape);
		window.draw(ballShape);
		window.display();
	}

	return 0;
}
