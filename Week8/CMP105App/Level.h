#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string>
#include <iostream>
#include "Ball.h"
#include "Square.h"
#include "Paddle.h"
#include "Pong.h"

class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	sf::Vector2u winSize;

	sf::Texture ballTexture;
	Ball ball1;
	Ball ball2;

	Square square1;
	Square square2;

	Paddle paddleL;
	Paddle paddleR;

	Pong pong;
};