#pragma once

#include <SFML/Graphics.hpp>

#include "Constants.hpp"

class Bullet
{
public:
	Bullet(sf::Vector2f);
	void fire() { bullet.move(bulletSpeed, 0); }
	void draw(sf::RenderWindow&);
	void setPosition(sf::Vector2f vec) { bullet.setPosition(vec); }
	sf::RectangleShape& getBody() { return bullet; }
private:
	sf::RectangleShape bullet;
};