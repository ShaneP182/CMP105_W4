#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	texture.loadFromFile("gfx/Mushroom.png");
	playerSprite.loadFromFile("gfx/Mushroom.png");
	enemySprite.loadFromFile("gfx/Goomba.png");
	altEnemySprite.loadFromFile("gfx/Brian.png");
	cursorSprite.loadFromFile("gfx/Icon.png");

	testSprite.setTexture(&texture);
	testSprite.setSize(sf::Vector2f(100, 100));
	testSprite.setPosition(100, 100);

	player.setTexture(&playerSprite);
	player.setSize(sf::Vector2f(100, 100));
	player.setPosition(300, 300);
	player.setInput(input);
	player.setVelocity(100, 100);

	enemy1.setTexture(&altEnemySprite);
	enemy1.setSize(sf::Vector2f(75, 75));
	enemy1.setPosition(500, 500);
	enemy1.setWindow(window);
	enemy1.setVelocity(50, 50);

	enemy2.setTexture(&enemySprite);
	enemy2.setSize(sf::Vector2f(50, 50));
	enemy2.setPosition(400, 400);
	enemy2.setWindow(window);
	enemy2.setVelocity(-200, -200);

	cursor.setTexture(&cursorSprite);
	cursor.setSize(sf::Vector2f(25, 25));
	cursor.setInput(input);

	window->setMouseCursorVisible(false);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	// Close window on Escape pressed.
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}

	player.handleInput(dt);

}

// Update game objects
void Level::update(float dt)
{
	side = window->getSize().x;
	bottom = window->getSize().y;

	if (player.getPosition().x > side - 100)
	{
		player.setPosition(side - 100, player.getPosition().y);
	}
	if (player.getPosition().x < 0)
	{
		player.setPosition(0, player.getPosition().y);
	}
	if (player.getPosition().y > bottom - 100)
	{
		player.setPosition(player.getPosition().x, bottom - 100);
	}
	if (player.getPosition().y < 0)
	{
		player.setPosition(player.getPosition().x, 0);
	}

	enemy1.update(dt);
	enemy2.update(dt);
	cursor.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	//window->draw(testSprite);
	window->draw(player);
	window->draw(enemy1);
	window->draw(enemy2);
	window->draw(cursor);

	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}