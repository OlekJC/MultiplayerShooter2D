#include "Player.hpp"
#include "Constants.hpp"

Player::Player(sf::Vector2f v)
{
	body.setSize(sf::Vector2f(sidePlayerLength, sidePlayerLength));
	body.setPosition(v.x, v.y);
}

void Player::draw(sf::RenderWindow& wnd)
{
	for (auto& bullet : clip)
	{
		bullet.fire();
		bullet.draw(wnd);
	}

	if (isAlive())
		wnd.draw(body);
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
	Bullet bullet(sf::Vector2f( body.getPosition() ));
	clip.push_back(bullet);
}

void Player::hit()
{
	HP -= bulletDamage;
}