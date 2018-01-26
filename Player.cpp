#include "Player.hpp"
#include "Constants.hpp"

Player::Player(sf::Vector2f v)
{
	body.setSize(sf::Vector2f(sidePlayerLength, sidePlayerLength));
	body.setPosition(v.x, v.y);
	y = body.getPosition().y;
}
void Player::setEnemy(Player* enemy)
{
	Player::enemy = enemy;
}

void Player::draw(sf::RenderWindow& wnd)
{
	y = body.getPosition().y;
	bounds = body.getGlobalBounds();
	for (auto& bullet : clip)
	{
		bullet.fire();
		if (bullet.getBody().getGlobalBounds().intersects(enemy->bounds))
		{
			enemy->hit();
			bullet.setPosition(trash);
		}
		else
			bullet.draw(wnd);
		
	}

	if (isAlive())
		wnd.draw(body);
	else
		body.setPosition(trash);
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