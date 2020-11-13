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

void Game::checkLevelChange()
{
	if (this->player->getCenterPos().x > this->level->getAcorn()->getGlobalBounds().left && 
		this->player->getCenterPos().x < (this->level->getAcorn()->getGlobalBounds().left + this->level->getAcorn()->getGlobalBounds().width) &&
		this->player->getCenterPos().y > this->level->getAcorn()->getGlobalBounds().top &&
		this->player->getCenterPos().y < (this->level->getAcorn()->getGlobalBounds().top + this->level->getAcorn()->getGlobalBounds().height)) //Insert collision detection for acorn here.
	{		
		//std::cout << "Check Success \n";
		if (this->levelCounter == 0)
		{
			this->levelCounter = 1;
			this->player->setPosition(50.f, 50.f);
			generateLevel(this->levelCounter);
		}
		else if (this->levelCounter == 1)
		{
			this->levelCounter = 0;
			this->player->setPosition(50.f, 50.f);
			generateLevel(this->levelCounter);
		}
	}
}

void Game::distanceDebug()
{
	float xDif;
	float yDif;
	xDif = abs(this->player->getCenterPos().x - this->level->GetAcornPos().x);
	yDif = abs(this->player->getCenterPos().y - this->level->GetAcornPos().y);
	//std::cout << "Diff in x = " << floor(xDif) << ". Diff in y = " << floor(yDif) << ". \n";
}

void Game::initPlayer()
{
	this->player = new Player();
}

void Game::initCollision()
{
	this->collisionHandler = new collision();
}

//Functions

Game::Game()
{
	levelCounter = 0;
	this->initWindow();
	this->initPlayer();
	this->initCollision();
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
	if (this->player->getPosition().y + this->player->getGlobalBounds().height > (this->window->getSize().y - 23.f))
	{
		this->player->setJumping(false);
		this->player->resetVelocityY();
		this->player->setPosition(
			this->player->getPosition().x,
			this->window->getSize().y - this->player->getGlobalBounds().height - 23
		);
	}

	collisionChecker(this->level->GetTileMap()->GetTiles());
	



	//else if (this->player->getPosition().y < 23.f) // Collision for top of screen
	//{
	//	this->player->setPosition(this->player->getPosition().x, 23);
	//}
	//else if (this->player->getPosition().x + this->player->getGlobalBounds().width > (this->window->getSize().x - 23.f)) // Collision for right of screen
	//{
	//	this->player->setPosition(
	//		this->window->getSize().x - this->player->getGlobalBounds().width - 23,
	//		this->player->getPosition().y
	//	);
	//}
	//else if (this->player->getPosition().x < 23.f) // Collision for left of screen
	//{
	//	this->player->setPosition(23, this->player->getPosition().y);
	//}

}

void Game::collisionChecker(std::vector<std::vector<Tile*>> _tiles)
{
	//COLLECTING CHECK DATA FOR EACH OF THE COLLIDEABLE TILES

	// Checking for collision with tile sprites
	//std::vector<std::vector<Tile*>> tiles = this->level->GetTileMap()->GetTiles();

	//std::vector<std::vector<Tile*>>::iterator TileVecItRow;
	//std::vector<Tile*>::iterator TileVecItCol;

	//std::vector<sf::Vector2<bool>> TilePlayerCollisionResults;

	//Attempt one at iteration - this one would be entered into by the code but then wouldn't do anything, not sure why exactly

	//for (TileVecItRow = tiles.begin(); TileVecItRow != tiles.end(); TileVecItRow++)
	//{
	//	for (TileVecItCol = TileVecItRow->begin(); TileVecItCol != TileVecItRow->end(); TileVecItCol++)
	//	{
	//		if (tiles[TileVecItCol][TileVecItCol]->GetSprite().getGlobalBounds().width == 48 && tiles[i][j]->GetSprite().getGlobalBounds().height == 15
	//			|| tiles[i][j]->GetSprite().getGlobalBounds().width == 15 && tiles[i][j]->GetSprite().getGlobalBounds().height == 48)
	//		{
	//			TilePlayerCollisionResults.push_back(this->collisionHandler->collisionCheck(tiles[i][j]->GetSprite(), this->player->getGlobalBounds()));
	//		}
	//	}
	//}
	//
	//tiles.clear();

	//attempt 2 at iteration - should work in theory but for some reason the code never runs: tried it with breakpoints ut it never got to the breakpoints, even ones where it did with the first attempt
	/*for (int i = 0; i < 3; i++)
	{*/
		//for (int j = 0; j < _tiles[0].size(); j++)
		{
	//		if (tiles[0].at(j)->GetSprite().getGlobalBounds().width == 48 && tiles[0].at(j)->GetSprite().getGlobalBounds().height == 15
	//			|| tiles[0].at(j)->GetSprite().getGlobalBounds().width == 15 && tiles[0].at(j)->GetSprite().getGlobalBounds().height == 48)
	//		{
				//TilePlayerCollisionResults.push_back(this->collisionHandler->collisionCheck(tiles[0].at(j)->GetSprite(), this->player->getGlobalBounds()));
	//		}
		}
	//}

	
	//PROCESSING COLLECTED DATA
	//std::vector<Vector2<bool>>::iterator BoolVecIterator;

	for (int i = 0; i < _tiles[0].size(); i++)
	{
		if ((_tiles[0].at(i)->GetSprite().getLocalBounds().width == 48) || (_tiles[0].at(i)->GetSprite().getLocalBounds().height == 15))
		{
			if ((this->collisionHandler->collisionCheck(_tiles[0].at(i)->GetSprite(), this->player->getSprite())) == sf::Vector2<bool>(1, 1))
			{
				this->player->setVelocity(this->player->getVelocityX(), this->player->getVelocityY() * -1);
			}
		}
		//if (_tiles[0].at(i)->GetSprite().getGlobalBounds().width == 48 && _tiles[0].at(i)->GetSprite().getGlobalBounds().height == 15) // Handling x-axis collision first
		//{
			/*if (this->collisionHandler->collisionCheck(this->player->getSprite(), _tiles[0].at(i)->GetSprite()) == sf::Vector2<bool>(0,0))
			{
				this->player->setVelocity(this->player->getVelocityX(), 0.f);
			}*/
			//this->player->setPosition(this->player->getPosition().x, 20.f); // Not working, not sure why
//		}

		//if (TilePlayerCollisionResults[i].y) // Then handling y-axis collision
		//{
		//	this->player->resetVelocityY();
		//}
	}
	/*TilePlayerCollisionResults.erase();*/
}

void Game::update()
{
	this->checkLevelChange();
	this->updatePollEvents();
	this->updateCollision();
	this->updatePlayer();

	this->distanceDebug();

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
	return *this->window;
}
