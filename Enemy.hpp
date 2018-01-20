#pragma once

#include "Player.hpp"
class Enemy :public Player
{
public:
	Enemy(sf::Vector2f v)
		: Player(v)
	{}
	virtual void move() {};
private:
	
	//virtual void shoot();
};