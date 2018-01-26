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
	virtual void shoot();
	virtual void move();
	sf::Vector2f getPosition() const { return body.getPosition(); }
	sf::RectangleShape getBody() const { return body; }
	bool isAlive() { return HP >= 0; }
	void hit();
	void setEnemy(Player*);
	int getHP() { return HP; }
	sf::Uint16 getY() { return y; };
	sf::RectangleShape body;
protected:
	
private:
	std::vector<Bullet> clip;
	sf::FloatRect bounds;
	Player* enemy = nullptr;
	int HP = 100;
	sf::Uint16 y;
};
