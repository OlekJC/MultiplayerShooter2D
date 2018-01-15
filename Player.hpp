#pragma once

#include <SFML\Graphics.hpp>
#include <vector>

#include "Bullet.hpp"

class Player
{
public:
	Player(sf::Vector2f);
	~Player() {};
	void draw(sf::RenderWindow& wnd) { wnd.draw(body); }
	void shoot();
	void move();
	//std::vector<Bullet>& getClip() { return clip; }
	sf::Vector2f getPosition() const { return body.getPosition(); }
private:
	sf::RectangleShape body;
	//std::vector<Bullet> clip;
};
