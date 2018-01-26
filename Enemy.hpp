#pragma once

#include "Player.hpp"
class Enemy : public Player
{
public:
	Enemy(sf::Vector2f v)
		: Player(v)
	{}
	//virtual void move() {};
	void setY(sf::Uint16 y) { body.setPosition(body.getPosition().x, y); }
private:
	
	//virtual void shoot();
};