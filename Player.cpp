#include "Player.hpp"
#include "Constants.hpp"

Player::Player(sf::Vector2f v)
{
	body.setSize(sf::Vector2f(50, 50));
	//body.setOrigin(body.getSize().x / 2, body.getSize().y / 2);
	body.setPosition(v.x, v.y);
}

void Player::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && body.getPosition().y < 600-50)
		body.move(0, playerSpeed);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && body.getPosition().y > 0)
		body.move(0, -playerSpeed);
}

void Player::shoot()
{
	//Bullet bullet;
	//clip.push_back(bullet);
	//clip.back().fire();
}