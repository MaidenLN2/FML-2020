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

	//collisionChecker(this->level->GetTileMap()->GetTiles());
	



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

//void Game::CollideWithMyAss(std::vector<std::vector<Tile*>> _tiles)
//{
//	for (int i = 0; i < _tiles[0].size(); i++)
//	{
//		if (this->player->getGlobalBounds().intersects(_tiles[0].at(i)->getGlobalBounds()));
//		{
//			//mPosition.x += x;
//			//updateAABB();
//			//checkCollisions(); // collect info of all tiles player intersects with
//			//resolveXCollisions();
//			//mPosition.y += y;
//			//updateAABB();
//			//checkCollisions();
//			//resolveYCollisions();
//		}
//	}
//}

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
	//	{
	//		if (tiles[0].at(j)->GetSprite().getGlobalBounds().width == 48 && tiles[0].at(j)->GetSprite().getGlobalBounds().height == 15
	//			|| tiles[0].at(j)->GetSprite().getGlobalBounds().width == 15 && tiles[0].at(j)->GetSprite().getGlobalBounds().height == 48)
	//		{
				//TilePlayerCollisionResults.push_back(this->collisionHandler->collisionCheck(tiles[0].at(j)->GetSprite(), this->player->getGlobalBounds()));
	//		}
	//	}
	//}

	
	//PROCESSING COLLECTED DATA
	//std::vector<Vector2<bool>>::iterator BoolVecIterator;

	for (int i = 0; i < _tiles[0].size(); i++)
	{
		//if (_tiles[0].at(i)->GetSprite().getGlobalBounds().width == 48 && _tiles[0].at(i)->GetSprite().getGlobalBounds().height == 15) // Handling x-axis collision first
		//{
			if (this->collisionHandler->collisionCheck(this->player->getSprite(), _tiles[0].at(i)->GetSprite()) == sf::Vector2<bool>(1,1))
			{
				this->player->setVelocity(this->player->getVelocityX(), 0.f);
			}
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
	this->updatePlayerMovement();

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

void Game::move(const float dir_x, const float dir_y, std::vector<std::vector<Tile*>> _tiles)
{
	// The way the movement needs to be done in somewhat psuedocode - Zac mentioned that you can use .intersect() to see if collision is true and then set the position to be offset by the difference in positions

	//mPosition.x += x; (can be potentially handled by updating the velocity and then getting the position right afterwards)
	this->player->velocity.x += dir_x * this->player->acceleration;

	//updateAABB();
	sf::Vector2f updateCenterPos;
	updateCenterPos.x = (this->player->sprite.getGlobalBounds().left + (this->player->sprite.getGlobalBounds().width / 2));
	updateCenterPos.y = (this->player->sprite.getGlobalBounds().top + (this->player->sprite.getGlobalBounds().height / 2));

	this->player->setCenterPos(updateCenterPos);

	//checkCollisions(); for loop that checks .intersects()
	for (int i = 0; i < _tiles[0].size(); i++)
	{
		if (_tiles[0].at(i)->getGlobalBounds().width == 48 || _tiles[0].at(i)->getGlobalBounds().width == 15)
		{
			if (this->player->sprite.getGlobalBounds().intersects(_tiles[0].at(i)->getGlobalBounds()));
			{
				//left of tile
				if (this->player->centerPos.x <= _tiles[0].at(i)->getCenterPos().x)
				{
					float temp = this->player->getPosition().x;
					temp += -(this->player->sprite.getGlobalBounds().left + this->player->sprite.getGlobalBounds().width - _tiles[0].at(i)->getGlobalBounds().left);
					this->player->setPosition(temp, this->player->getPosition().y);

					//mPosition.x += -(mAABB.left + mAABB.width - collision.mBounds.left);

					updateCenterPos.x = (this->player->sprite.getGlobalBounds().left + (this->player->sprite.getGlobalBounds().width / 2));
					updateCenterPos.y = (this->player->sprite.getGlobalBounds().top + (this->player->sprite.getGlobalBounds().height / 2));
					this->player->setCenterPos(updateCenterPos);
				}
				//right of tile
				if (this->player->centerPos.x >= _tiles[0].at(i)->getCenterPos().x)
				{
					float temp = this->player->getPosition().x;
					temp += ((_tiles[0].at(i)->getGlobalBounds().left + _tiles[0].at(i)->getGlobalBounds().width) - this->player->sprite.getGlobalBounds().left);
					this->player->setPosition(temp, this->player->getPosition().y);
					//mPosition.x += (collision.mBounds.left + collision.mBounds.width) - mAABB.left;

					updateCenterPos.x = (this->player->sprite.getGlobalBounds().left + (this->player->sprite.getGlobalBounds().width / 2));
					updateCenterPos.y = (this->player->sprite.getGlobalBounds().top + (this->player->sprite.getGlobalBounds().height / 2));
					this->player->setCenterPos(updateCenterPos);
				}
			}
		}
	}

	//resolveXCollisions(); this can be inside the above for loop, checking first for left collision then right collison and resolving each in that order as they happen

	//mPosition.y += y; (can be potentially handled by updating the velocity and then getting the position right afterwards)
	this->player->velocity.y += dir_y * this->player->acceleration;

	//updateAABB();
	updateCenterPos.x = (this->player->sprite.getGlobalBounds().left + (this->player->sprite.getGlobalBounds().width / 2));
	updateCenterPos.y = (this->player->sprite.getGlobalBounds().top + (this->player->sprite.getGlobalBounds().height / 2));

	this->player->setCenterPos(updateCenterPos);

	//checkCollisions(); for loop that checks .intersects()
	for (int i = 0; i < _tiles[0].size(); i++)
	{
		if (_tiles[0].at(i)->getGlobalBounds().width == 48 || _tiles[0].at(i)->getGlobalBounds().width == 15)
		{
			if (this->player->sprite.getGlobalBounds().intersects(_tiles[0].at(i)->getGlobalBounds()));
			{
				//top of tile
				if (this->player->centerPos.y <= _tiles[0].at(i)->getCenterPos().y)
				{
					float temp = this->player->getPosition().y;
					temp += -(this->player->sprite.getGlobalBounds().top + this->player->sprite.getGlobalBounds().height - _tiles[0].at(i)->getGlobalBounds().top);
					this->player->setPosition(this->player->getPosition().x, temp);

					updateCenterPos.x = (this->player->sprite.getGlobalBounds().left + (this->player->sprite.getGlobalBounds().width / 2));
					updateCenterPos.y = (this->player->sprite.getGlobalBounds().top + (this->player->sprite.getGlobalBounds().height / 2));
					this->player->setCenterPos(updateCenterPos);
				}
				//bottom of tile
				if (this->player->centerPos.y >= _tiles[0].at(i)->getCenterPos().y)
				{
					float temp = this->player->getPosition().y;
					temp += ((_tiles[0].at(i)->getGlobalBounds().top + _tiles[0].at(i)->getGlobalBounds().height) - this->player->sprite.getGlobalBounds().top);
					this->player->setPosition(this->player->getPosition().x, temp);

					updateCenterPos.x = (this->player->sprite.getGlobalBounds().left + (this->player->sprite.getGlobalBounds().width / 2));
					updateCenterPos.y = (this->player->sprite.getGlobalBounds().top + (this->player->sprite.getGlobalBounds().height / 2));
					this->player->setCenterPos(updateCenterPos);
				}
			}
		}
	}

	//resolveYCollisions(); this can be inside the above for loop, checking first for top collision then bottom collison and resolving each in that order as they happen

	//Limit Velocity
	if (std::abs(this->player->velocity.x) > this->player->velocityMax)
	{
		this->player->velocity.x = this->player->velocityMax * ((this->player->velocity.x < 0.f) ? -1.f : 1.f);
	}
}

void Game::updatePlayerMovement()
{
	if (!this->player->getJumping())
		this->player->animState = IDLE;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) //Move left
	{
		this->move(-1.f, 0.f, this->level->GetTileMap()->GetTiles());
		if (!this->player->getJumping())
			this->player->animState = MOVING_LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) //Move Right
	{
		this->move(1.f, 0.f, this->level->GetTileMap()->GetTiles());
		if (!this->player->getJumping())
			this->player->animState = MOVING_RIGHT;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && this->player->jumping == false) //Jump
	{
		this->move(0.f, -120.f, this->level->GetTileMap()->GetTiles());
		this->player->animState = JUMPING;
		this->player->setJumping(true);
	}
}