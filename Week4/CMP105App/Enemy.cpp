#include "Enemy.h"

Enemy::Enemy()
{

}

Enemy::~Enemy()
{

}

void Enemy::update(float dt)
{
	side = window->getSize().x;
	bottom = window->getSize().y;

	if (getPosition().x >= side - getSize().x || getPosition().x <= 0)
	{
		setVelocity(-getVelocity().x, getVelocity().y);
	}
	if (getPosition().y >= bottom - getSize().y || getPosition().y <= 0)
	{
		setVelocity(getVelocity().x, -getVelocity().y);
	}

	move(dt * getVelocity().x, dt * getVelocity().y);
}