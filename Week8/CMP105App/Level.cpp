#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	ballTexture.loadFromFile("gfx/Beach_Ball.png");

	ball1.setSize(sf::Vector2f(50, 50));
	ball1.setPosition(50, 300);
	ball1.setVelocity(50, 0);
	ball1.setTexture(&ballTexture);

	ball2.setSize(sf::Vector2f(50, 50));
	ball2.setPosition(800, 330);
	ball2.setVelocity(-50, 0);
	ball2.setTexture(&ballTexture);

	square1.setSize(sf::Vector2f(50, 50));
	square1.setCollisionBox(sf::FloatRect(0, 0, 50, 50));
	square1.setPosition(0, 200);
	square1.setVelocity(50, 0);
	square1.setFillColor(sf::Color::Blue);
	
	square2.setPosition(750, 200);
	square2.setSize(sf::Vector2f(50, 50));
	square2.setCollisionBox(sf::FloatRect(0, 0, 50, 50));
	square2.setVelocity(-50, 0);
	square2.setFillColor(sf::Color::Green);

	winSize = window->getSize();

	paddleL.setPosition(50, winSize.y / 2 - paddleL.getSize().y);
	paddleL.setSize(sf::Vector2f(50, 150));
	paddleL.setCollisionBox(sf::FloatRect(0, 0, 50, 150));
	paddleL.setVelocity(0, 500);
	paddleL.setFillColor(sf::Color::Blue);

	paddleR.setPosition(winSize.x - 100 , winSize.y / 2 - paddleR.getSize().y);
	paddleR.setSize(sf::Vector2f(50, 150));
	paddleR.setCollisionBox(sf::FloatRect(0, 0, 50, 150));
	paddleR.setVelocity(0, 500);
	paddleR.setFillColor(sf::Color::Red);

	pong.setSize(sf::Vector2f(50, 50));
	pong.setPosition(winSize.x / 2 - 50, winSize.y / 2 - 50);
	pong.setCollisionBox(sf::FloatRect(0, 0, 50, 50));
	pong.setTexture(&ballTexture);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::W) && paddleL.getPosition().y > 0)
	{
		paddleL.move(-paddleL.getVelocity() * dt);
	}
	if (input->isKeyDown(sf::Keyboard::S) && paddleL.getPosition().y < winSize.y - paddleL.getSize().y)
	{
		paddleL.move(paddleL.getVelocity() * dt);
	}

	if (input->isKeyDown(sf::Keyboard::Up) && paddleR.getPosition().y > 0)
	{
		paddleR.move(-paddleR.getVelocity() * dt);
	}
	if (input->isKeyDown(sf::Keyboard::Down) && paddleR.getPosition().y < winSize.y - paddleR.getSize().y)
	{
		paddleR.move(paddleR.getVelocity() * dt);
	}
}

// Update game objects
void Level::update(float dt)
{
	winSize = window->getSize();

	pong.update(dt, winSize);

	if (Collision::checkBoundingBox(&paddleL, &pong))
	{
		pong.collisionResponse(NULL);
	}
	if (Collision::checkBoundingBox(&paddleR, &pong))
	{
		pong.collisionResponse(NULL);
	}

	//ball1.update(dt, winSize);
	//ball2.update(dt, winSize);
	//if (Collision::checkBoundingCircle(&ball1, &ball2)) 
	//{
	//	ball1.collisionResponse(NULL);
	//	ball2.collisionResponse(NULL);
	//}

	//square1.update(dt, winSize);
	//square2.update(dt, winSize);
	//if (Collision::checkBoundingBox(&square1, &square2)) 
	//{ 
	//	square1.collisionResponse(NULL);
	//	square2.collisionResponse(NULL);
	//}
}

// Render level
void Level::render()
{
	beginDraw();

	//window->draw(ball1);
	//window->draw(ball2);
	//window->draw(square1);
	//window->draw(square2);

	window->draw(paddleL);
	window->draw(paddleR);
	window->draw(pong);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}