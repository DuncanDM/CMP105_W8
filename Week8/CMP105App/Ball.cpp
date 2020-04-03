#include "Ball.h"

Ball::Ball()
{

}

Ball::~Ball()
{

}

void Ball::update(float dt, sf::Vector2u winSize)
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
}

void Ball::collisionResponse(GameObject* collider)
{
	velocity.x = -velocity.x;
}