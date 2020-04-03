#pragma once

#include "Framework/GameObject.h"
#include "Framework/Collision.h"

class Paddle :public GameObject
{
public:
	Paddle();
	~Paddle();

	void update(float dt, sf::Vector2u winSize);

private:
	sf::Vector2f velocity;
};