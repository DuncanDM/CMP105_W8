#pragma once

#include "Framework/GameObject.h"
#include "Framework/Collision.h"

class Pong :public GameObject
{
public:
	Pong();
	~Pong();

	void update(float dt, sf::Vector2u winSize);
	void collisionResponse(GameObject* collider);

private:
	sf::Vector2f velocity;
};