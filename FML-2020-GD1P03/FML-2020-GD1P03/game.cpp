//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2020 Media Design School
//
// File Name	: game.cpp
// Description	: Main file for running the game loop
// Author		: Callum Boyce
//				: Lera Blokhina
// Mail			: callum.boyce@mds.ac.nz
//				: valeriia.blokhina@mds.ac.nz
//

#include "stdafx.h"
#include "Game.h"

//Private Functions
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "FML-2020", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

void Game::initBackground()
{
	this->Background = new background();
}

void Game::generateLevel(int _levelCounter)
{
	this->level = new SceneNode(_levelCounter);
}

void Game::initPlayer()
{
	this->player = new Player();
}

//Functions

Game::Game()
{
	levelCounter = 0;
	this->initWindow();
	this->initPlayer();
	this->initBackground();
	this->generateLevel(levelCounter);
}

Game::~Game()
{
	delete this->window;
	delete this->player;
}

void Game::updatePollEvents()
{
	//Polling the windows events
	while (this->window->pollEvent(ev))
	{
		//Closes the window if the X button is clicked on the top right.
		if (this->ev.Event::type == sf::Event::Closed)
			this->window->close();

		if ( //Resets the player animation when any of the direction keys are released.
			this->ev.type == sf::Event::KeyReleased && 
			(
				this->ev.key.code == sf::Keyboard::A ||
				this->ev.key.code == sf::Keyboard::D ||
				this->ev.key.code == sf::Keyboard::S ||
				this->ev.key.code == sf::Keyboard::W 
				)
			)
		{
			this->player->resetAnimationTimer();
		}
	}
}

void Game::updateLevel()
{
}

void Game::updatePlayer()
{
	this->player->update();
}

void Game::updateCollision()
{
	//Collision for bottom of screen.
	if (this->player->getPosition().y + this->player->getGlobalBounds().height > this->window->getSize().y)
	{
		this->player->setJumping(false);
		this->player->resetVelocityY();
		this->player->setPosition(
			this->player->getPosition().x,
			this->window->getSize().y - this->player->getGlobalBounds().height
		);
	}
}

void Game::update()
{
	this->updatePollEvents();
	this->updatePlayer();
	this->updateCollision();
}

void Game::renderBG()
{
	this->Background->render(*this->window);
}

void Game::renderLevel()
{
	this->level->Render(*this->window);
}

void Game::renderPlayer()
{
	this->player->render(*this->window);
}

void Game::render()
{
	this->window->clear(); //Clear the frame

	//Draw all the things!
	this->renderBG();
	this->renderLevel();
	this->renderPlayer();


	this->window->display(); //Display the new frame!
}

const sf::RenderWindow& Game::getWindow() const
{
	// TODO: insert return statement here
	return *this->window;
}
