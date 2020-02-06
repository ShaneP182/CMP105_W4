#include "Player.h"
#include <iostream>
Player::Player()
{

}

Player::~Player() 
{

}

void Player::handleInput(float dt)
{
	// W moves player up
	if (input->isKeyDown(sf::Keyboard::W))
	{
		move(0, dt * -getVelocity().y);
	}

	// S moves player down
	if (input->isKeyDown(sf::Keyboard::S))
	{
		move(0, dt * getVelocity().y);
	}

	// A moves player left
	if (input->isKeyDown(sf::Keyboard::A))
	{
		move(dt * -getVelocity().x, 0);
	}

	// D moves player right
	if (input->isKeyDown(sf::Keyboard::D))
	{
		move(dt * getVelocity().x, 0);
	}

}

void Player::update(float dt)
{

}
