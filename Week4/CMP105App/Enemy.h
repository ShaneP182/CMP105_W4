#pragma once
#include "Framework/GameObject.h"

class Enemy:
	public GameObject
{
public:
	Enemy();
	~Enemy();

	void update(float dt);

	void setWindow(sf::RenderWindow* hwnd) { window = hwnd; };

protected:
	sf::RenderWindow* window;

	int side;
	int bottom;
};

