#pragma once

#include <SFML\Graphics.hpp>
#include <vector>

#include "Bullet.hpp"


class Player
{
public:
	Player(sf::Vector2f);
	~Player() {};
	void draw(sf::RenderWindow& wnd);
	void shoot();
	void move();
	//std::vector<Bullet>& getClip() { return clip; }
	sf::Vector2f getPosition() const { return body.getPosition(); }
	sf::RectangleShape getBody() const { return body; }
	bool isAlive() { return HP >= 100; }
	void hit();
private:
	sf::RectangleShape body;
	//std::vector<Bullet> clip;
	std::vector<Bullet> clip;
	int HP = 100;
};
