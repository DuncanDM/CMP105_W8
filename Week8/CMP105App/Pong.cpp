#include "Pong.h"

Pong::Pong()
{
	velocity = sf::Vector2f(500.f, 500.f);
}

Pong::~Pong()
{

}

void Pong::update(float dt, sf::Vector2u winSize)
{
	move(velocity * dt);
	if (getPosition().x < 0)
	{
		setPosition(0, getPosition().y);
		velocity.x = -velocity.x;
	}
	if (getPosition().x > winSize.x - getSize().x)
	{
		setPosition(winSize.x - getSize().x, getPosition().y);
		velocity.x = -velocity.x;
	}
	if (getPosition().y < 0)
	{
		setPosition(getPosition().x, 0);
		velocity.y = -velocity.y;
	}
	if (getPosition().y > winSize.y - getSize().y)
	{
		setPosition(getPosition().x, winSize.y - getSize().y);
		velocity.y = -velocity.y;
	}
}

void Pong::collisionResponse(GameObject* collider)
{
	velocity.x = -velocity.x;
}