#include "Paddle.h"

Paddle::Paddle()
{

}

Paddle::~Paddle()
{

}

void Paddle::update(float dt, sf::Vector2u winSize)
{
	if (getPosition().y < 0)
	{
		setPosition(0, getPosition().y);
	}
	if (getPosition().x > winSize.y - getSize().y)
	{
		setPosition(winSize.x - getSize().x, getPosition().y);
	}
}